/* **************************************************************************
ASWTools_Random.h
Author: Anthony S. West - ASW Software, 06/10/2010, updated 2025

"Mersenne Twister pseudorandom number generator"
An implementation based on code written by Takuji Nishimura and Makoto Matsumoto
See: https://en.wikipedia.org/wiki/Mersenne_Twister
and: https://jblevins.org/projects/mt
and: book: Game Code Complete 3rd Edition??

Every attempt should be made to keep this module at least Windows portable.

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

#ifndef ASWTools_RandomH
#define ASWTools_RandomH
//---------------------------------------------------------------------------
#include <stdint.h>
//---------------------------------------------------------------------------

// Period parameters
#define CMATH_N 624

//---------------------------------------------------------------------------

namespace ASWTools
{

/////////////////////////////////////////////////////////////////////////////
// TMersenneTwisterRandom
/////////////////////////////////////////////////////////////////////////////
class TMersenneTwisterRandom
{
private:
    uint32_t m_rseed;
    uint32_t m_mt[CMATH_N]; // the array for the state vector
    int32_t m_mti; // m_mti==N+1 means mt[N] is not initialized

public:
    uint32_t GetRandomSeed();
    void SetRandomSeed(uint32_t n);

public:
    TMersenneTwisterRandom();
    ~TMersenneTwisterRandom();

    uint32_t Random(uint32_t n); // Returns a number from 0 to n (excluding n)
    float Random();
    void Randomize();
};

} // namespace ASWTools

//---------------------------------------------------------------------------
#endif // #ifndef ASWTools_RandomH
