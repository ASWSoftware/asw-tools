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
    RegisterTest(Test_Combine);
    RegisterTest(Test_ExpandEnvironmentVars);
    RegisterTest(Test_IsDots);
    RegisterTest(Test_IsEnvironment);
    RegisterTest(Test_IsNetwork);
    RegisterTest(Test_IsRelative);
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
void TTest_ASWTools_Path::Test_Combine()
{
    // Arrange
    std::string pathLeft0 = "";
    std::wstring pathLeft0W = L"";
    std::string pathLeft1 = "C:\\left";
    std::wstring pathLeft1W = L"C:\\left";
    std::string pathLeft2 = "C:\\left\\";
    std::wstring pathLeft2W = L"C:\\left\\";
    std::string pathLeft3 = "C:\\left/";
    std::wstring pathLeft3W = L"C:\\left/";
    std::string pathLeft4 = "\\";
    std::wstring pathLeft4W = L"\\";
    std::string pathLeft5 = "/";
    std::wstring pathLeft5W = L"/";

    std::string pathSub0 = "";
    std::wstring pathSub0W = L"";
    std::string pathSub1 = "sub";
    std::wstring pathSub1W = L"sub";
    std::string pathSub2 = "\\sub";
    std::wstring pathSub2W = L"\\sub";
    std::string pathSub3 = "/sub";
    std::wstring pathSub3W = L"/sub";
    std::string pathSub4 = "\\";
    std::wstring pathSub4W = L"\\";
    std::string pathSub5 = "/";
    std::wstring pathSub5W = L"/";

    std::string expected1 = "C:\\left\\sub";
    std::wstring expected1W = L"C:\\left\\sub";
    std::string expected2 = "C:\\left/sub";
    std::wstring expected2W = L"C:\\left/sub";

    // Act & Assert

    // Path left 0 against all subs
    CheckEquals(pathSub0, TPathTool::Combine(pathLeft0, pathSub0), __func__, __LINE__, "L0 S0, ansi");
    CheckEquals(pathSub0W, TPathTool::Combine(pathLeft0W, pathSub0W), __func__, __LINE__, "L0 S0, wide");
    CheckEquals(pathSub1, TPathTool::Combine(pathLeft0, pathSub1), __func__, __LINE__, "L0 S1, ansi");
    CheckEquals(pathSub1W, TPathTool::Combine(pathLeft0W, pathSub1W), __func__, __LINE__, "L0 S1, wide");
    CheckEquals(pathSub2, TPathTool::Combine(pathLeft0, pathSub2), __func__, __LINE__, "L0 S2, ansi");
    CheckEquals(pathSub2W, TPathTool::Combine(pathLeft0W, pathSub2W), __func__, __LINE__, "L0 S2, wide");
    CheckEquals(pathSub3, TPathTool::Combine(pathLeft0, pathSub3), __func__, __LINE__, "L0 S3, ansi");
    CheckEquals(pathSub3W, TPathTool::Combine(pathLeft0W, pathSub3W), __func__, __LINE__, "L0 S3, wide");
    CheckEquals(pathSub4, TPathTool::Combine(pathLeft0, pathSub4), __func__, __LINE__, "L0 S4, ansi");
    CheckEquals(pathSub4W, TPathTool::Combine(pathLeft0W, pathSub4W), __func__, __LINE__, "L0 S4, wide");
    CheckEquals(pathSub5, TPathTool::Combine(pathLeft0, pathSub5), __func__, __LINE__, "L0 S5, ansi");
    CheckEquals(pathSub5W, TPathTool::Combine(pathLeft0W, pathSub5W), __func__, __LINE__, "L0 S5, wide");

    // Path left 1 against all subs
    CheckEquals(pathLeft1, TPathTool::Combine(pathLeft1, pathSub0), __func__, __LINE__, "L1 S0, ansi");
    CheckEquals(pathLeft1W, TPathTool::Combine(pathLeft1W, pathSub0W), __func__, __LINE__, "L1 S0, wide");
    CheckEquals(expected1, TPathTool::Combine(pathLeft1, pathSub1), __func__, __LINE__, "L1 S1, ansi");
    CheckEquals(expected1W, TPathTool::Combine(pathLeft1W, pathSub1W), __func__, __LINE__, "L1 S1, wide");
    CheckEquals(expected1, TPathTool::Combine(pathLeft1, pathSub2), __func__, __LINE__, "L1 S2, ansi");
    CheckEquals(expected1W, TPathTool::Combine(pathLeft1W, pathSub2W), __func__, __LINE__, "L1 S2, wide");
    CheckEquals(expected2, TPathTool::Combine(pathLeft1, pathSub3), __func__, __LINE__, "L1 S3, ansi");
    CheckEquals(expected2W, TPathTool::Combine(pathLeft1W, pathSub3W), __func__, __LINE__, "L1 S3, wide");
    CheckEquals(pathLeft2, TPathTool::Combine(pathLeft1, pathSub4), __func__, __LINE__, "L1 S4, ansi");
    CheckEquals(pathLeft2W, TPathTool::Combine(pathLeft1W, pathSub4W), __func__, __LINE__, "L1 S4, wide");
    CheckEquals(pathLeft3, TPathTool::Combine(pathLeft1, pathSub5), __func__, __LINE__, "L1 S5, ansi");
    CheckEquals(pathLeft3W, TPathTool::Combine(pathLeft1W, pathSub5W), __func__, __LINE__, "L1 S5, wide");

    // Path left 2 against all subs
    CheckEquals(pathLeft2, TPathTool::Combine(pathLeft2, pathSub0), __func__, __LINE__, "L2 S0, ansi");
    CheckEquals(pathLeft2W, TPathTool::Combine(pathLeft2W, pathSub0W), __func__, __LINE__, "L2 S0, wide");
    CheckEquals(expected1, TPathTool::Combine(pathLeft2, pathSub1), __func__, __LINE__, "L2 S1, ansi");
    CheckEquals(expected1W, TPathTool::Combine(pathLeft2W, pathSub1W), __func__, __LINE__, "L2 S1, wide");
    CheckEquals(expected1, TPathTool::Combine(pathLeft2, pathSub2), __func__, __LINE__, "L2 S2, ansi");
    CheckEquals(expected1W, TPathTool::Combine(pathLeft2W, pathSub2W), __func__, __LINE__, "L2 S2, wide");
    CheckEquals(expected1, TPathTool::Combine(pathLeft2, pathSub3), __func__, __LINE__, "L2 S3, ansi");
    CheckEquals(expected1W, TPathTool::Combine(pathLeft2W, pathSub3W), __func__, __LINE__, "L2 S3, wide");
    CheckEquals(pathLeft2, TPathTool::Combine(pathLeft2, pathSub4), __func__, __LINE__, "L2 S4, ansi");
    CheckEquals(pathLeft2W, TPathTool::Combine(pathLeft2W, pathSub4W), __func__, __LINE__, "L2 S4, wide");
    CheckEquals(pathLeft2, TPathTool::Combine(pathLeft2, pathSub5), __func__, __LINE__, "L2 S5, ansi");
    CheckEquals(pathLeft2W, TPathTool::Combine(pathLeft2W, pathSub5W), __func__, __LINE__, "L2 S5, wide");

    // Path left 3 against all subs
    CheckEquals(pathLeft3, TPathTool::Combine(pathLeft3, pathSub0), __func__, __LINE__, "L3 S0, ansi");
    CheckEquals(pathLeft3W, TPathTool::Combine(pathLeft3W, pathSub0W), __func__, __LINE__, "L3 S0, wide");
    CheckEquals(expected2, TPathTool::Combine(pathLeft3, pathSub1), __func__, __LINE__, "L3 S1, ansi");
    CheckEquals(expected2W, TPathTool::Combine(pathLeft3W, pathSub1W), __func__, __LINE__, "L3 S1, wide");
    CheckEquals(expected2, TPathTool::Combine(pathLeft3, pathSub2), __func__, __LINE__, "L3 S2, ansi");
    CheckEquals(expected2W, TPathTool::Combine(pathLeft3W, pathSub2W), __func__, __LINE__, "L3 S2, wide");
    CheckEquals(expected2, TPathTool::Combine(pathLeft3, pathSub3), __func__, __LINE__, "L3 S3, ansi");
    CheckEquals(expected2W, TPathTool::Combine(pathLeft3W, pathSub3W), __func__, __LINE__, "L3 S3, wide");
    CheckEquals(pathLeft3, TPathTool::Combine(pathLeft3, pathSub4), __func__, __LINE__, "L3 S4, ansi");
    CheckEquals(pathLeft3W, TPathTool::Combine(pathLeft3W, pathSub4W), __func__, __LINE__, "L3 S4, wide");
    CheckEquals(pathLeft3, TPathTool::Combine(pathLeft3, pathSub5), __func__, __LINE__, "L3 S5, ansi");
    CheckEquals(pathLeft3W, TPathTool::Combine(pathLeft3W, pathSub5W), __func__, __LINE__, "L3 S5, wide");

    // Path left 4 against all subs
    CheckEquals(pathLeft4, TPathTool::Combine(pathLeft4, pathSub0), __func__, __LINE__, "L4 S0, ansi");
    CheckEquals(pathLeft4W, TPathTool::Combine(pathLeft4W, pathSub0W), __func__, __LINE__, "L4 S0, wide");
    CheckEquals(pathSub2, TPathTool::Combine(pathLeft4, pathSub1), __func__, __LINE__, "L4 S1, ansi");
    CheckEquals(pathSub2W, TPathTool::Combine(pathLeft4W, pathSub1W), __func__, __LINE__, "L4 S1, wide");
    CheckEquals(pathSub2, TPathTool::Combine(pathLeft4, pathSub2), __func__, __LINE__, "L4 S2, ansi");
    CheckEquals(pathSub2W, TPathTool::Combine(pathLeft4W, pathSub2W), __func__, __LINE__, "L4 S2, wide");
    CheckEquals(pathSub2, TPathTool::Combine(pathLeft4, pathSub3), __func__, __LINE__, "L4 S3, ansi");
    CheckEquals(pathSub2W, TPathTool::Combine(pathLeft4W, pathSub3W), __func__, __LINE__, "L4 S3, wide");
    CheckEquals(pathLeft4, TPathTool::Combine(pathLeft4, pathSub4), __func__, __LINE__, "L4 S4, ansi");
    CheckEquals(pathLeft4W, TPathTool::Combine(pathLeft4W, pathSub4W), __func__, __LINE__, "L4 S4, wide");
    CheckEquals(pathLeft4, TPathTool::Combine(pathLeft4, pathSub5), __func__, __LINE__, "L4 S5, ansi");
    CheckEquals(pathLeft4W, TPathTool::Combine(pathLeft4W, pathSub5W), __func__, __LINE__, "L4 S5, wide");

    // Path left 5 against all subs
    CheckEquals(pathLeft5, TPathTool::Combine(pathLeft5, pathSub0), __func__, __LINE__, "L5 S0, ansi");
    CheckEquals(pathLeft5W, TPathTool::Combine(pathLeft5W, pathSub0W), __func__, __LINE__, "L5 S0, wide");
    CheckEquals(pathSub3, TPathTool::Combine(pathLeft5, pathSub1), __func__, __LINE__, "L5 S1, ansi");
    CheckEquals(pathSub3W, TPathTool::Combine(pathLeft5W, pathSub1W), __func__, __LINE__, "L5 S1, wide");
    CheckEquals(pathSub3, TPathTool::Combine(pathLeft5, pathSub2), __func__, __LINE__, "L5 S2, ansi");
    CheckEquals(pathSub3W, TPathTool::Combine(pathLeft5W, pathSub2W), __func__, __LINE__, "L5 S2, wide");
    CheckEquals(pathSub3, TPathTool::Combine(pathLeft5, pathSub3), __func__, __LINE__, "L5 S3, ansi");
    CheckEquals(pathSub3W, TPathTool::Combine(pathLeft5W, pathSub3W), __func__, __LINE__, "L5 S3, wide");
    CheckEquals(pathLeft5, TPathTool::Combine(pathLeft5, pathSub4), __func__, __LINE__, "L5 S4, ansi");
    CheckEquals(pathLeft5W, TPathTool::Combine(pathLeft5W, pathSub4W), __func__, __LINE__, "L5 S4, wide");
    CheckEquals(pathLeft5, TPathTool::Combine(pathLeft5, pathSub5), __func__, __LINE__, "L5 S5, ansi");
    CheckEquals(pathLeft5W, TPathTool::Combine(pathLeft5W, pathSub5W), __func__, __LINE__, "L5 S5, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_ExpandEnvironmentVars()
{
    // Arrange
    std::string subDir = "path\\to\\file.txt";
    std::wstring subDirW = L"path\\to\\file.txt";

    std::string envTemp = TPathTool::Combine("%temp%", subDir);
    std::wstring envTempW = TPathTool::Combine(L"%temp%", subDirW);

    // Note: GetTempDir() returns the long path (no ~ path). ExpandEnvironmentVars() returns the short path.
    std::string expTemp = TPathTool::Combine(TPathTool::GetShortPathA(TPathTool::GetTempDirA()), subDir);
    std::wstring expTempW = TPathTool::Combine(TPathTool::GetShortPathW(TPathTool::GetTempDirW()), subDirW);

    std::string result;
    std::wstring resultW;

    // Act & Assert
    CheckTrue(TPathTool::ExpandEnvironmentVars(envTemp, result), __func__, __LINE__, "expand temp, ansi");
    CheckTrue(TPathTool::ExpandEnvironmentVars(envTempW, resultW), __func__, __LINE__, "expand temp, wide");
    CheckEquals(expTemp, result, __func__, __LINE__, "temp result, ansi");
    CheckEquals(expTempW, resultW, __func__, __LINE__, "temp result, wide");
}
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
void TTest_ASWTools_Path::Test_IsNetwork()
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
    CheckTrue(TPathTool::IsNetwork(network), __func__, __LINE__, "network, ansi");
    CheckTrue(TPathTool::IsNetwork(networkW), __func__, __LINE__, "network, wide");

    CheckFalse(TPathTool::IsNetwork(environment), __func__, __LINE__, "environment, ansi");
    CheckFalse(TPathTool::IsNetwork(environmentW), __func__, __LINE__, "environmentW, wide");

    CheckFalse(TPathTool::IsNetwork(relative1), __func__, __LINE__, "relative1, ansi");
    CheckFalse(TPathTool::IsNetwork(relative1W), __func__, __LINE__, "relative1, wide");

    CheckFalse(TPathTool::IsNetwork(full), __func__, __LINE__, "full, ansi");
    CheckFalse(TPathTool::IsNetwork(fullW), __func__, __LINE__, "fullW, wide");
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

} // ASWUnitTests
