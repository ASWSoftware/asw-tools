/* **************************************************************************
Test_ASWTools_Path.cpp
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
#include "Test_ASWTools_Path.h"
//---------------------------------------------------------------------------
#include <iostream>
//---------------------------------------------------------------------------
#include "ASWTools_Path.h"
//---------------------------------------------------------------------------
using namespace ASWTools;
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTest_ASWTools_Path
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTest_ASWTools_Path::TTest_ASWTools_Path()
    : inherited("ASWTools_Path_Tests")
{
    RegisterTest(Test_IsDots);
    RegisterTest(Test_IsRelative);
    RegisterTest(Test_IsEnvironment);
}
//---------------------------------------------------------------------------
TTest_ASWTools_Path::~TTest_ASWTools_Path()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::SetUp()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::TearDown()
{
}
//---------------------------------------------------------------------------

// /////// Begin tests after this line ///////////////////////

//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_IsDots()
{
    // Arrange
    std::string dot = ".";
    std::string dots = "..";
    std::string failDots = "...";
    std::wstring dotW = L".";
    std::wstring dotsW = L"..";
    std::wstring failDotsW = L"...";

    // Act & Assert
    CheckTrue(TPathTool::IsDots(dot), __func__, __LINE__, "Single dot, ansi");
    CheckTrue(TPathTool::IsDots(dots), __func__, __LINE__, "Double dots, ansi");
    CheckFalse(TPathTool::IsDots(failDots), __func__, __LINE__, "Triple dots, ansi");
    CheckFalse(TPathTool::IsDots(""), __func__, __LINE__, "Empty, ansi");
    CheckTrue(TPathTool::IsDots(dotW), __func__, __LINE__, "Single dot, wide");
    CheckTrue(TPathTool::IsDots(dotsW), __func__, __LINE__, "Double dots, wide");
    CheckFalse(TPathTool::IsDots(failDotsW), __func__, __LINE__, "Triple dots, wide");
    CheckFalse(TPathTool::IsDots(L""), __func__, __LINE__, "Empty, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_IsRelative()
{
    // Arrange
    std::string relative1 = "test\\relative\\path\\to\\file.txt";
    std::wstring relative1W = L"test\\relative\\path\\to\\file.txt";
    std::string relative2 = "\\test\\relative\\path\\to\\file.txt";
    std::wstring relative2W = L"\\test\\relative\\path\\to\\file.txt";
    std::string relative3 = "/test/relative/path/to/file.txt";
    std::wstring relative3W = L"/test/relative/path/to/file.txt";
    std::string relative4 = "..\\test\\relative\\path\\to\\file.txt";
    std::wstring relative4W = L"..\\test\\relative\\path\\to\\file.txt";
    std::string relative5 = "../test/relative/path/to/file.txt";
    std::wstring relative5W = L"../test/relative/path/to/file.txt";
    std::string relative6 = "..\\..\\test\\relative\\path\\to\\file.txt";
    std::wstring relative6W = L"..\\..\\test\\relative\\path\\to\\file.txt";
    std::string network = "\\\\a\\network\\path.txt";
    std::wstring networkW = L"\\\\a\\network\\path.txt";
    std::string environment = "%temp%\\path\\to\\file.txt";
    std::wstring environmentW = L"%temp%\\path\\to\\file.txt";
    std::string full = "C:\\not\\a\\relative\\path\\file.txt";
    std::wstring fullW = L"C:\\not\\a\\relative\\path\\file.txt";

    // Act & Assert
    CheckTrue(TPathTool::IsRelative(relative1), __func__, __LINE__, "relative1, ansi");
    CheckTrue(TPathTool::IsRelative(relative1W), __func__, __LINE__, "relative1, wide");
    CheckTrue(TPathTool::IsRelative(relative2), __func__, __LINE__, "relative2, ansi");
    CheckTrue(TPathTool::IsRelative(relative2W), __func__, __LINE__, "relative2, wide");
    CheckTrue(TPathTool::IsRelative(relative3), __func__, __LINE__, "relative3, ansi");
    CheckTrue(TPathTool::IsRelative(relative3W), __func__, __LINE__, "relative3, wide");
    CheckTrue(TPathTool::IsRelative(relative4), __func__, __LINE__, "relative4, ansi");
    CheckTrue(TPathTool::IsRelative(relative4W), __func__, __LINE__, "relative4, wide");
    CheckTrue(TPathTool::IsRelative(relative5), __func__, __LINE__, "relative5, ansi");
    CheckTrue(TPathTool::IsRelative(relative5W), __func__, __LINE__, "relative5, wide");
    CheckTrue(TPathTool::IsRelative(relative6), __func__, __LINE__, "relative6, ansi");
    CheckTrue(TPathTool::IsRelative(relative6W), __func__, __LINE__, "relative6, wide");

    CheckFalse(TPathTool::IsRelative(network), __func__, __LINE__, "network, ansi");
    CheckFalse(TPathTool::IsRelative(networkW), __func__, __LINE__, "network, wide");

    CheckFalse(TPathTool::IsRelative(environment), __func__, __LINE__, "environment, ansi");
    CheckFalse(TPathTool::IsRelative(environmentW), __func__, __LINE__, "environmentW, wide");

    CheckFalse(TPathTool::IsRelative(full), __func__, __LINE__, "full, ansi");
    CheckFalse(TPathTool::IsRelative(fullW), __func__, __LINE__, "fullW, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_IsEnvironment()
{
    // Arrange
    std::string relative1 = "test\\relative\\path\\to\\file.txt";
    std::wstring relative1W = L"test\\relative\\path\\to\\file.txt";
    std::string network = "\\\\a\\network\\path.txt";
    std::wstring networkW = L"\\\\a\\network\\path.txt";
    std::string environment = "%temp%\\path\\to\\file.txt";
    std::wstring environmentW = L"%temp%\\path\\to\\file.txt";
    std::string full = "C:\\not\\a\\relative\\path\\file.txt";
    std::wstring fullW = L"C:\\not\\a\\relative\\path\\file.txt";

    // Act & Assert
    CheckTrue(TPathTool::IsEnvironment(environment), __func__, __LINE__, "environment, ansi");
    CheckTrue(TPathTool::IsEnvironment(environmentW), __func__, __LINE__, "environmentW, wide");

    CheckFalse(TPathTool::IsEnvironment(relative1), __func__, __LINE__, "relative1, ansi");
    CheckFalse(TPathTool::IsEnvironment(relative1W), __func__, __LINE__, "relative1, wide");

    CheckFalse(TPathTool::IsEnvironment(network), __func__, __LINE__, "network, ansi");
    CheckFalse(TPathTool::IsEnvironment(networkW), __func__, __LINE__, "network, wide");

    CheckFalse(TPathTool::IsEnvironment(full), __func__, __LINE__, "full, ansi");
    CheckFalse(TPathTool::IsEnvironment(fullW), __func__, __LINE__, "fullW, wide");
}
//---------------------------------------------------------------------------

} // ASWUnitTests
