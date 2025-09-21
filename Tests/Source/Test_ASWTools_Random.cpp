/* **************************************************************************
Test_ASWTools_Random.cpp
Author: Anthony S. West - ASW Software

See header for info.

Copyright 2025 Anthony S. West

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
#include "Test_ASWTools_Random.h"
//---------------------------------------------------------------------------
#include "ASWTools_Random.h"
//---------------------------------------------------------------------------
using namespace ASWTools;
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTest_TMersenneTwisterRandom
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTest_TMersenneTwisterRandom::TTest_TMersenneTwisterRandom()
    : inherited("ASWTools_Random_TMersenneTwisterRandom_Tests")
{
    // Interesting way to do it, but works (AI generated)
    RegisterTest([this]()
        {
            Test_Constructor_DefaultSeed();
        });

    RegisterTest(Test_Random_FloatRange);
    RegisterTest(Test_Random_UIntRange);
    RegisterTest(Test_Randomize_ChangesSeed);
    RegisterTest(Test_SetAndGetSeed);
}
//---------------------------------------------------------------------------
TTest_TMersenneTwisterRandom::~TTest_TMersenneTwisterRandom()
{
}
//---------------------------------------------------------------------------
void TTest_TMersenneTwisterRandom::SetUp()
{
}
//---------------------------------------------------------------------------
void TTest_TMersenneTwisterRandom::TearDown()
{
}
//---------------------------------------------------------------------------

// /////// Begin tests after this line ///////////////////////

//---------------------------------------------------------------------------
// Test: Constructor sets default seed
void TTest_TMersenneTwisterRandom::Test_Constructor_DefaultSeed()
{
    // Arrange
    TMersenneTwisterRandom rNumGen;

    // Act
    uint32_t seed = rNumGen.GetRandomSeed();

    // Assert
    AssertEquals(static_cast<uint32_t>(1), seed, __func__, __LINE__, "Default seed should be 1");
}
//---------------------------------------------------------------------------
// Test: Random() returns float in [0.0, 1.0]
void TTest_TMersenneTwisterRandom::Test_Random_FloatRange()
{
    // Arrange
    TMersenneTwisterRandom rNumGen;
    rNumGen.SetRandomSeed(99);
    bool inRange = true;

    // Act
    for (int i = 0; i < 1000; ++i)
    {
        float val = rNumGen.Random();
        if (val < 0.0f || val > 1.0f)
        {
            inRange = false;
            break;
        }
    }

    // Assert
    AssertTrue(inRange, __func__, __LINE__, "Random() should be in [0.0, 1.0]");
}
//---------------------------------------------------------------------------
// Test: Random(uint32_t n) returns values in [0, n)
void TTest_TMersenneTwisterRandom::Test_Random_UIntRange()
{
    // Arrange
    TMersenneTwisterRandom rNumGen;
    rNumGen.SetRandomSeed(42);
    uint32_t n = 100;
    bool inRange = true;

    // Act
    for (int i = 0; i < 1000; ++i)
    {
        uint32_t val = rNumGen.Random(n);
        if (val >= n)
        {
            inRange = false;
            break;
        }
    }

    // Assert
    AssertTrue(inRange, __func__, __LINE__, "Random(n) should be in [0, n)");
}
//---------------------------------------------------------------------------
// Test: Randomize changes the seed
void TTest_TMersenneTwisterRandom::Test_Randomize_ChangesSeed()
{
    // Arrange
    TMersenneTwisterRandom rNumGen;
    rNumGen.SetRandomSeed(1);
    uint32_t before = rNumGen.GetRandomSeed();

    // Act
    rNumGen.Randomize();
    uint32_t after = rNumGen.GetRandomSeed();

    // Assert
    AssertNotEquals(before, after, __func__, __LINE__, "Randomize should change the seed");
}
//---------------------------------------------------------------------------
// Test: Set and Get Seed
void TTest_TMersenneTwisterRandom::Test_SetAndGetSeed()
{
    // Arrange
    TMersenneTwisterRandom rNumGen;
    uint32_t testSeed = 123456789;

    // Act
    rNumGen.SetRandomSeed(testSeed);
    uint32_t result = rNumGen.GetRandomSeed();

    // Assert
    AssertEquals(testSeed, result, __func__, __LINE__, "Set/Get seed should match");
}
//---------------------------------------------------------------------------

} // namespace ASWUnitTests
