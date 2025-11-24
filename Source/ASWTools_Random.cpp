/* **************************************************************************
ASWTools_Random.cpp
Author: Anthony S. West - ASW Software

See header for info.

Copyright 2010 Anthony S. West

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

************************************************************************** */

//---------------------------------------------------------------------------
// Module header
#include "ASWTools_Random.h"
//---------------------------------------------------------------------------
#include <time.h>
//---------------------------------------------------------------------------

#if __cplusplus < 201103L
  #define nullptr NULL
#endif

// Period parameters
//#define CMATH_N 624 // defined in the header
#define CMATH_M 397
#define CMATH_MATRIX_A 0x9908b0df   // constant vector a
#define CMATH_UPPER_MASK 0x80000000 // most significant w-r bits
#define CMATH_LOWER_MASK 0x7fffffff // least significant r bits

// Tempering parameters
#define CMATH_TEMPERING_MASK_B 0x9d2c5680
#define CMATH_TEMPERING_MASK_C 0xefc60000
#define CMATH_TEMPERING_SHIFT_U(y)  (y >> 11)
#define CMATH_TEMPERING_SHIFT_S(y)  (y << 7)
#define CMATH_TEMPERING_SHIFT_T(y)  (y << 15)
#define CMATH_TEMPERING_SHIFT_L(y)  (y >> 18)

//---------------------------------------------------------------------------

namespace ASWTools
{

/////////////////////////////////////////////////////////////////////////////
// TMersenneTwisterRandom
/////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
TMersenneTwisterRandom::TMersenneTwisterRandom()
    : m_rseed(1),
      m_mti(CMATH_N + 1)
{
}
//----------------------------------------------------------------------------
TMersenneTwisterRandom::~TMersenneTwisterRandom()
{
}
//----------------------------------------------------------------------------
uint32_t TMersenneTwisterRandom::GetRandomSeed()
{
    return m_rseed;
}
//----------------------------------------------------------------------------
uint32_t TMersenneTwisterRandom::Random(uint32_t n)
{
    // Returns a number from 0 to n (excluding n)
    uint32_t y;
    static uint32_t mag01[2] = { 0x0, CMATH_MATRIX_A };

    if(n == 0)
        return(0);

    // mag01[x] = x * MATRIX_A  for x=0,1

    if (m_mti >= CMATH_N) // generate N words at one time
    {
        int kk;

        if (m_mti == CMATH_N + 1)
            SetRandomSeed(424242); // Randomize() has not been called, use a default initial seed

        for (kk = 0; kk < CMATH_N - CMATH_M; kk++)
        {
            y = (m_mt[kk] & CMATH_UPPER_MASK) | (m_mt[kk + 1] & CMATH_LOWER_MASK);
            m_mt[kk] = m_mt[kk + CMATH_M] ^ (y >> 1) ^ mag01[y & 0x1];
        }

        for (; kk < CMATH_N - 1; kk++)
        {
            y = (m_mt[kk] & CMATH_UPPER_MASK) | (m_mt[kk + 1] & CMATH_LOWER_MASK);
            m_mt[kk] = m_mt[kk + (CMATH_M - CMATH_N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }

        y = (m_mt[CMATH_N - 1] & CMATH_UPPER_MASK) | (m_mt[0] & CMATH_LOWER_MASK);
        m_mt[CMATH_N - 1] = m_mt[CMATH_M - 1] ^ (y >> 1) ^ mag01[y & 0x1];

        m_mti = 0;
    }

    y = m_mt[m_mti++];
    y ^= CMATH_TEMPERING_SHIFT_U(y);
    y ^= CMATH_TEMPERING_SHIFT_S(y) & CMATH_TEMPERING_MASK_B;
    y ^= CMATH_TEMPERING_SHIFT_T(y) & CMATH_TEMPERING_MASK_C;
    y ^= CMATH_TEMPERING_SHIFT_L(y);

    // Return a range from 0 to n (not including n).
    return (y % n);
}

//----------------------------------------------------------------------------
float TMersenneTwisterRandom::Random()
{
    // Returns a random float between 0.0f-1.0f

    int32_t r = static_cast<int32_t>(static_cast<float>(Random(0xffffffff)));
    float divisor = static_cast<float>(0xffffffff);

    return (static_cast<float>(r) / divisor) + 0.5f;
}
//----------------------------------------------------------------------------
void TMersenneTwisterRandom::Randomize()
{
    SetRandomSeed(static_cast<uint32_t>(time(nullptr)));
}
//----------------------------------------------------------------------------
void TMersenneTwisterRandom::SetRandomSeed(uint32_t n)
{
    // Setting initial seeds to mt[N] using the generator Line 25 of Table 1 in
    // [KNUTH 1981, The Art of Computer Programming Vol. 2 (2nd Ed.), pp102]

    m_mt[0] = n & 0xffffffff;
    for (m_mti = 1; m_mti < CMATH_N; m_mti++)
    {
        m_mt[m_mti] = (69069 * m_mt[m_mti - 1]) & 0xffffffff;
    }

    m_rseed = n;
}
//----------------------------------------------------------------------------

} // namespace ASWTools
