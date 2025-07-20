/* **************************************************************************
Test_ASWTools_Version.cpp
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
#include "Test_ASWTools_Version.h"
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
// TTest_ASWTools_Version
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTest_ASWTools_Version::TTest_ASWTools_Version()
    : inherited("ASWTools_Version_Tests")
{
    RegisterTest(Test_Compare);
    RegisterTest(Test_Copy);
    RegisterTest(Test_ExtractVersionNumbersFromVersionStr);
    RegisterTest(Test_SetVersion);
}
//---------------------------------------------------------------------------
TTest_ASWTools_Version::~TTest_ASWTools_Version()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Version::SetUp()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Version::TearDown()
{
}
//---------------------------------------------------------------------------

// /////// Begin tests after this line ///////////////////////

//---------------------------------------------------------------------------
void TTest_ASWTools_Version::Test_Compare()
{
    // Arrange
    TVersion ver1(1, 2, 3, 4);
    TVersion ver2("1.2.3.4");
    TVersion ver3("1.2.3.2");

    // Act & Assert
    CheckTrue(ver1 == ver2, __func__, __LINE__, "Equals operator ver2");
    CheckFalse(ver1 == ver3, __func__, __LINE__, "Equals operator ver3");
    CheckTrue(ver1 != ver3, __func__, __LINE__, "Not equals operator ver3");
    CheckTrue(ver1 > ver3, __func__, __LINE__, "Greater than ver3");
    CheckTrue(ver1 >= ver3, __func__, __LINE__, "Greater than or equals ver3");
    CheckTrue(ver1 >= ver2, __func__, __LINE__, "Greater than or equals ver2");
    CheckTrue(ver3 < ver1, __func__, __LINE__, "Less than ver1");
    CheckTrue(ver3 <= ver1, __func__, __LINE__, "Less than or equals ver1");
    CheckTrue(ver1 <= ver2, __func__, __LINE__, "Less than or equals ver2");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Version::Test_Copy()
{
    // Arrange
    TVersion ver1(1, 2, 3, 4);
    TVersion ver2("1.2.3.42");
    TVersion testVer;

    // Act & Assert
    CheckTrue(ver1.VersionU64 != 0, __func__, __LINE__, "Sanity check that set works");
    testVer = ver1;
    CheckEquals(ver1.VersionU64, testVer.VersionU64, __func__, __LINE__, "Copy ver1");
    testVer.CopyFrom(ver2);
    CheckEquals(ver2.VersionU64, testVer.VersionU64, __func__, __LINE__, "Copy ver2");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Version::Test_ExtractVersionNumbersFromVersionStr()
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
    CheckEquals(expected.ToStrVer(), actual.ToStrVer(), __func__, __LINE__, "ExtractVersionNumbersFromVersionStr()");
    CheckEquals(expected.ToStrVer(), actual2.ToStrVer(), __func__, __LINE__, "Constructor test");
    CheckEquals(expected.ToStrVerW(), actual3.ToStrVerW(), __func__, __LINE__, "Wide string test");
    CheckEquals(expected.VersionU64, actual4.VersionU64, __func__, __LINE__, "Constructor U64");
    CheckNotEquals(expected.VersionU64, actualNotEquals.VersionU64, __func__, __LINE__, "Values are default??");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Version::Test_SetVersion()
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
    CheckTrue(parts.Major == major && parts.Minor == minor && parts.Build == build && parts.Revision == revision,
        __func__, __LINE__, "SetVersion()");
}
//---------------------------------------------------------------------------

} // ASWUnitTests
