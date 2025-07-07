/* **************************************************************************
ASWTools_Version_Tests.cpp
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
#include "ASWTools_Version_Tests.h"
//---------------------------------------------------------------------------
#include <iostream>
//---------------------------------------------------------------------------
#include "ASWTools_Version.h"
//---------------------------------------------------------------------------
using namespace ASWTools;
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestGroup_ASWTools_Version_Tests
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTestGroup_ASWTools_Version_Tests::TTestGroup_ASWTools_Version_Tests()
    : inherited("ASWTools_Version_Tests")
{
    RegisterTest(Test_Compare);
    RegisterTest(Test_Copy);
    RegisterTest(Test_ExtractVersionNumbersFromVersionStr);
    RegisterTest(Test_SetVersion);
}
//---------------------------------------------------------------------------
TTestGroup_ASWTools_Version_Tests::~TTestGroup_ASWTools_Version_Tests()
{
}
//---------------------------------------------------------------------------
void TTestGroup_ASWTools_Version_Tests::SetUp()
{
}
//---------------------------------------------------------------------------
void TTestGroup_ASWTools_Version_Tests::TearDown()
{
}
//---------------------------------------------------------------------------

// /////// Begin tests after this line ///////////////////////

//---------------------------------------------------------------------------
void TTestGroup_ASWTools_Version_Tests::Test_Compare()
{
    // Arrange
    TVersion ver1(1, 2, 3, 4);
    TVersion ver2("1.2.3.4");
    TVersion ver3("1.2.3.2");

    // Act & Assert
    AssertTrue(ver1 == ver2, __func__, __LINE__, "Equals operator ver2");
    AssertFalse(ver1 == ver3, __func__, __LINE__, "Equals operator ver3");
    AssertTrue(ver1 != ver3, __func__, __LINE__, "Not equals operator ver3");
    AssertTrue(ver1 > ver3, __func__, __LINE__, "Greater than ver3");
    AssertTrue(ver1 >= ver3, __func__, __LINE__, "Greater than or equals ver3");
    AssertTrue(ver1 >= ver2, __func__, __LINE__, "Greater than or equals ver2");
    AssertTrue(ver3 < ver1, __func__, __LINE__, "Less than ver1");
    AssertTrue(ver3 <= ver1, __func__, __LINE__, "Less than or equals ver1");
    AssertTrue(ver1 <= ver2, __func__, __LINE__, "Less than or equals ver2");
}
//---------------------------------------------------------------------------
void TTestGroup_ASWTools_Version_Tests::Test_Copy()
{
    // Arrange
    TVersion ver1(1, 2, 3, 4);
    TVersion ver2("1.2.3.42");
    TVersion testVer;

    // Act & Assert
    AssertTrue(ver1.VersionU64 != 0, __func__, __LINE__, "Sanity check that set works");
    testVer = ver1;
    AssertEquals(ver1.VersionU64, testVer.VersionU64, __func__, __LINE__, "Copy ver1");
    testVer.CopyFrom(ver2);
    AssertEquals(ver2.VersionU64, testVer.VersionU64, __func__, __LINE__, "Copy ver2");
}
//---------------------------------------------------------------------------
void TTestGroup_ASWTools_Version_Tests::Test_ExtractVersionNumbersFromVersionStr()
{
    // Arrange
    TVersion expected(1, 2, 3, 4);
    TVersion actual;
    TVersion actual2("1.2.3.4");
    TVersion actual3(L"1.2.3.4");
    TVersion actual4(expected.VersionU64);
    TVersion actualNotEquals(1, 2, 3, 42);

    // Act
    actual.ExtractVersionNumbersFromVersionStr("1.2.3.4");

    // Assert
    AssertEquals(expected.ToStrVer(), actual.ToStrVer(), __func__, __LINE__, "ExtractVersionNumbersFromVersionStr()");
    AssertEquals(expected.ToStrVer(), actual2.ToStrVer(), __func__, __LINE__, "Constructor test");
    AssertEquals(expected.ToStrVerW(), actual3.ToStrVerW(), __func__, __LINE__, "Wide string test");
    AssertEquals(expected.VersionU64, actual4.VersionU64, __func__, __LINE__, "Constructor U64");
    AssertNotEquals(expected.VersionU64, actualNotEquals.VersionU64, __func__, __LINE__, "Values are default??");
}
//---------------------------------------------------------------------------
void TTestGroup_ASWTools_Version_Tests::Test_SetVersion()
{
    // Arrange
    WORD major = static_cast<WORD>(4200);
    WORD minor = static_cast<WORD>(420);
    WORD build = static_cast<WORD>(101010);
    WORD revision = static_cast<WORD>(42);
    TVersion ver;
    TVersion::TVerParts& parts = ver.Version;

    // Act
    ver.SetVersion(major, minor, build, revision);

    // Assert
    AssertTrue(parts.Major == major && parts.Minor == minor && parts.Build == build && parts.Revision == revision,
        __func__, __LINE__, "SetVersion()");
}
//---------------------------------------------------------------------------

} // ASWUnitTests
