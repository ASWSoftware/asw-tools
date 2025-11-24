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
#include <shlobj.h>
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
    RegisterTest(Test_Combine, "Combine");
    RegisterTest(Test_ExpandEnvironmentVars, "ExpandEnvironmentVars");
    RegisterTest(Test_ExtractDir, "ExtractDir");
    RegisterTest(Test_ExtractFileName, "ExtractFileName");
    RegisterTest(Test_GenerateRandomName, "GenerateRandomName");
    RegisterTest(Test_GetDocumentsDir, "GetDocumentsDir");
    RegisterTest(Test_GetExtension, "GetExtension");
    RegisterTest(Test_GetFullPath, "GetFullPath");
    RegisterTest(Test_GetLongPath, "GetLongPath");
    RegisterTest(Test_GetPicturesDir, "GetPicturesDir");
    RegisterTest(Test_GetShortPath, "GetShortPath");
    RegisterTest(Test_GetSpecialFolderDir, "GetSpecialFolderDir");
    RegisterTest(Test_GetTempDir, "GetTempDir");
    RegisterTest(Test_IsDots, "IsDots");
    RegisterTest(Test_IsEnvironment, "IsEnvironment");
    RegisterTest(Test_IsNetwork, "IsNetwork");
    RegisterTest(Test_IsRelative, "IsRelative");
    RegisterTest(Test_RemoveExtension, "RemoveExtension");
}
//---------------------------------------------------------------------------
TTest_ASWTools_Path::~TTest_ASWTools_Path()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::SetUp_Group()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::TearDown_Group()
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
void TTest_ASWTools_Path::Test_ExtractDir()
{
    // Arrange
    std::string dir = "C:\\path\\to\\file.txt";
    std::wstring dirW = L"C:\\path\\to\\file.txt";

    std::string noDir = "file.txt";
    std::wstring noDirW = L"file.txt";

    std::string dirNoFileTrailSlash = "C:\\path\\to\\";
    std::wstring dirNoFileTrailSlashW = L"C:\\path\\to\\";

    std::string dirNoFileNoSlash = "C:\\path\\to\\file";
    std::wstring dirNoFileNoSlashW = L"C:\\path\\to\\file";

    std::string expected1 = "C:\\path\\to";
    std::wstring expected1W = L"C:\\path\\to";
    std::string expected2 = "C:\\path\\to\\";
    std::wstring expected2W = L"C:\\path\\to\\";

    // Act & Assert
    CheckEquals(expected1, TPathTool::ExtractDir(dir, false), __func__, __LINE__, "no trail slash, ansi");
    CheckEquals(expected1W, TPathTool::ExtractDir(dirW, false), __func__, __LINE__, "no trail slash, wide");
    CheckEquals(expected2, TPathTool::ExtractDir(dir), __func__, __LINE__, "with trail slash, ansi");
    CheckEquals(expected2W, TPathTool::ExtractDir(dirW), __func__, __LINE__, "with trail slash, wide");
    CheckEquals("", TPathTool::ExtractDir(noDir), __func__, __LINE__, "No dir, ansi");
    CheckEquals(L"", TPathTool::ExtractDir(noDirW), __func__, __LINE__, "No dir, wide");
    CheckEquals(expected2, TPathTool::ExtractDir(dirNoFileTrailSlash), __func__, __LINE__, "No file slash, ansi");
    CheckEquals(expected2W, TPathTool::ExtractDir(dirNoFileTrailSlashW), __func__, __LINE__, "No file slash, wide");
    CheckEquals(expected2, TPathTool::ExtractDir(dirNoFileNoSlash), __func__, __LINE__, "no file, ansi");
    CheckEquals(expected2W, TPathTool::ExtractDir(dirNoFileNoSlashW), __func__, __LINE__, "no file, wide");
    CheckEquals("", TPathTool::ExtractDir(""), __func__, __LINE__, "empty str, ansi");
    CheckEquals(L"", TPathTool::ExtractDir(L""), __func__, __LINE__, "empty str, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_ExtractFileName()
{
    // Arrange
    std::string dir = "C:\\path\\to\\file.txt";
    std::wstring dirW = L"C:\\path\\to\\file.txt";

    std::string noDir = "file.txt";
    std::wstring noDirW = L"file.txt";

    std::string dirNoFileTrailSlash = "C:\\path\\to\\";
    std::wstring dirNoFileTrailSlashW = L"C:\\path\\to\\";

    std::string dirNoSlash = "C:\\path\\to\\file";
    std::wstring dirNoSlashW = L"C:\\path\\to\\file";

    std::string expected1 = "file.txt";
    std::wstring expected1W = L"file.txt";
    std::string expected2 = "file";
    std::wstring expected2W = L"file";

    // Act & Assert
    CheckEquals(expected1, TPathTool::ExtractFileName(dir), __func__, __LINE__, "file.txt, ansi");
    CheckEquals(expected1W, TPathTool::ExtractFileName(dirW), __func__, __LINE__, "file.txt, wide");
    CheckEquals(expected1, TPathTool::ExtractFileName(dir, false), __func__, __LINE__, "file.txt retain, ansi");
    CheckEquals(expected1W, TPathTool::ExtractFileName(dirW, false), __func__, __LINE__, "file.txt retain, wide");
    CheckEquals(expected2, TPathTool::ExtractFileName(dir, true), __func__, __LINE__, "file, ansi");
    CheckEquals(expected2W, TPathTool::ExtractFileName(dirW, true), __func__, __LINE__, "file, wide");
    CheckEquals(expected1, TPathTool::ExtractFileName(noDir), __func__, __LINE__, "No dir, ansi");
    CheckEquals(expected1W, TPathTool::ExtractFileName(noDirW), __func__, __LINE__, "No dir, wide");
    CheckEquals("", TPathTool::ExtractFileName(dirNoFileTrailSlash), __func__, __LINE__, "No file slash, ansi");
    CheckEquals(L"", TPathTool::ExtractFileName(dirNoFileTrailSlashW), __func__, __LINE__, "No file slash, wide");
    CheckEquals(expected2, TPathTool::ExtractFileName(dirNoSlash), __func__, __LINE__, "no file, ansi");
    CheckEquals(expected2W, TPathTool::ExtractFileName(dirNoSlashW), __func__, __LINE__, "no file, wide");
    CheckEquals("", TPathTool::ExtractFileName(""), __func__, __LINE__, "empty str, ansi");
    CheckEquals(L"", TPathTool::ExtractFileName(L""), __func__, __LINE__, "empty str, wide");
    CheckEquals("", TPathTool::ExtractFileName("", false), __func__, __LINE__, "empty str retain, ansi");
    CheckEquals(L"", TPathTool::ExtractFileName(L"", false), __func__, __LINE__, "empty str retain, wide");
    CheckEquals("", TPathTool::ExtractFileName("", true), __func__, __LINE__, "empty str no retain, ansi");
    CheckEquals(L"", TPathTool::ExtractFileName(L"", true), __func__, __LINE__, "empty str no retain, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GenerateRandomName()
{
    // Arrange
    std::string customA = "ABC123";
    std::wstring customW = L"XYZ789";

    // Act & Assert
    auto nameA = TPathTool::GenerateRandomNameA(12);
    CheckEquals(static_cast<size_t>(12), nameA.length(), __func__, __LINE__, "Length, ansi");
    for (char c : nameA)
        CheckTrue(strchr(TPathTool::AlphaCharsA, c) != nullptr, __func__, __LINE__, "Char in AlphaCharsA");

    auto nameCustomA = TPathTool::GenerateRandomName(8, customA);
    CheckEquals(static_cast<size_t>(8), nameCustomA.length(), __func__, __LINE__, "Length, custom ansi");
    for (char c : nameCustomA)
        CheckTrue(customA.find(c) != std::string::npos, __func__, __LINE__, "Char in customA");

    auto nameW = TPathTool::GenerateRandomNameW(10);
    CheckEquals(static_cast<size_t>(10), nameW.length(), __func__, __LINE__, "Length, wide");
    for (wchar_t c : nameW)
        CheckTrue(wcschr(TPathTool::AlphaCharsW, c) != nullptr, __func__, __LINE__, "Char in AlphaCharsW");

    auto nameCustomW = TPathTool::GenerateRandomName(6, customW);
    CheckEquals(static_cast<size_t>(6), nameCustomW.length(), __func__, __LINE__, "Length, custom wide");
    for (wchar_t c : nameCustomW)
        CheckTrue(customW.find(c) != std::wstring::npos, __func__, __LINE__, "Char in customW");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetDocumentsDir()
{
    // Act
    auto dirA = TPathTool::GetDocumentsDirA();
    auto dirW = TPathTool::GetDocumentsDirW();

    // Assert
    CheckTrue(!dirA.empty(), __func__, __LINE__, "Documents dir not empty, ansi");
    CheckTrue(!dirW.empty(), __func__, __LINE__, "Documents dir not empty, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetExtension()
{
    // Arrange
    std::string path = "C:\\path\\to\\file.txt";
    std::wstring pathW = L"C:\\path\\to\\file.txt";

    std::string noDir = "file.txt";
    std::wstring noDirW = L"file.txt";

    std::string noExt = "file";
    std::wstring noExtW = L"file";

    std::string extOnly = ".txt";
    std::wstring extOnlyW = L".txt";

    std::string pathDot = "C:\\path\\to\\file.";
    std::wstring pathDotW = L"C:\\path\\to\\file.";

    std::string expected1 = ".txt";
    std::wstring expected1W = L".txt";
    std::string expected2 = ".";
    std::wstring expected2W = L".";

    // Act & Assert
    CheckEquals(expected1, TPathTool::GetExtension(path), __func__, __LINE__, "path file.txt, ansi");
    CheckEquals(expected1W, TPathTool::GetExtension(pathW), __func__, __LINE__, "path file.txt, wide");
    CheckEquals(expected1, TPathTool::GetExtension(noDir), __func__, __LINE__, "file.txt no dir, ansi");
    CheckEquals(expected1W, TPathTool::GetExtension(noDirW), __func__, __LINE__, "file.txt no dir, wide");
    CheckEquals("", TPathTool::GetExtension(noExt), __func__, __LINE__, "no ext, ansi");
    CheckEquals(L"", TPathTool::GetExtension(noExtW), __func__, __LINE__, "no ext, wide");
    CheckEquals("", TPathTool::GetExtension(""), __func__, __LINE__, "empty, ansi");
    CheckEquals(L"", TPathTool::GetExtension(L""), __func__, __LINE__, "empty, wide");
    CheckEquals(expected1, TPathTool::GetExtension(extOnly), __func__, __LINE__, "ext only, ansi");
    CheckEquals(expected1W, TPathTool::GetExtension(extOnlyW), __func__, __LINE__, "ext only, wide");
    CheckEquals(expected2, TPathTool::GetExtension(pathDot), __func__, __LINE__, "path dot, ansi");
    CheckEquals(expected2W, TPathTool::GetExtension(pathDotW), __func__, __LINE__, "path dot, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetFullPath()
{
    // Arrange
    std::string relA = "TestFile.txt";
    std::wstring relW = L"TestFile.txt";

    // Act
    auto fullA = TPathTool::GetFullPathA(relA);
    auto fullW = TPathTool::GetFullPathW(relW);

    // Assert
    CheckTrue(!fullA.empty(), __func__, __LINE__, "Full path not empty, ansi");
    CheckTrue(fullA.find(relA) != std::string::npos, __func__, __LINE__, "Full path contains file name, ansi");
    CheckTrue(!fullW.empty(), __func__, __LINE__, "Full path not empty, wide");
    CheckTrue(fullW.find(relW) != std::wstring::npos, __func__, __LINE__, "Full path contains file name, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetLongPath()
{
    // Arrange
    std::string pathA;
    TPathTool::ExpandEnvironmentVars("%AppData%", pathA);
    std::wstring pathW;
    TPathTool::ExpandEnvironmentVars(L"%AppData%", pathW);

    // Act
    auto longA = TPathTool::GetLongPathA(pathA);
    auto longW = TPathTool::GetLongPathW(pathW);

    // Assert
    CheckTrue(!longA.empty(), __func__, __LINE__, "Long path not empty, ansi");
    CheckTrue(!longW.empty(), __func__, __LINE__, "Long path not empty, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetPicturesDir()
{
    // Act
    auto dirA = TPathTool::GetPicturesDirA();
    auto dirW = TPathTool::GetPicturesDirW();

    // Assert
    CheckTrue(!dirA.empty(), __func__, __LINE__, "Pictures dir not empty, ansi");
    CheckTrue(!dirW.empty(), __func__, __LINE__, "Pictures dir not empty, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetShortPath()
{
    // Arrange
    std::string pathA = TPathTool::GetPicturesDirA();
    std::wstring pathW = TPathTool::GetPicturesDirW();

    // Act
    auto shortA = TPathTool::GetShortPathA(pathA);
    auto shortW = TPathTool::GetShortPathW(pathW);

    // Assert
    CheckTrue(!shortA.empty(), __func__, __LINE__, "Short path not empty, ansi");
    CheckTrue(!shortW.empty(), __func__, __LINE__, "Short path not empty, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetSpecialFolderDir()
{
    // Arrange
    int csidl = CSIDL_DESKTOP;

    // Act
    auto dirA = TPathTool::GetSpecialFolderDirA(csidl);
    auto dirW = TPathTool::GetSpecialFolderDirW(csidl);

    // Assert
    CheckTrue(!dirA.empty(), __func__, __LINE__, "Special folder dir not empty, ansi");
    CheckTrue(!dirW.empty(), __func__, __LINE__, "Special folder dir not empty, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_Path::Test_GetTempDir()
{
    // Act
    auto dirA = TPathTool::GetTempDirA();
    auto dirW = TPathTool::GetTempDirW();

    // Assert
    CheckTrue(!dirA.empty(), __func__, __LINE__, "Temp dir not empty, ansi");
    CheckTrue(!dirW.empty(), __func__, __LINE__, "Temp dir not empty, wide");
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
void TTest_ASWTools_Path::Test_RemoveExtension()
{
    // Arrange
    std::string path = "C:\\path\\to\\file.txt";
    std::wstring pathW = L"C:\\path\\to\\file.txt";

    std::string noDir = "file.txt";
    std::wstring noDirW = L"file.txt";

    std::string pathTrailSlash = "C:\\path\\to\\";
    std::wstring pathTrailSlashW = L"C:\\path\\to\\";

    std::string pathDot = "C:\\path\\to\\file.";
    std::wstring pathDotW = L"C:\\path\\to\\file.";

    std::string expected1 = "C:\\path\\to\\file";
    std::wstring expected1W = L"C:\\path\\to\\file";
    std::string expected2 = "file";
    std::wstring expected2W = L"file";

    // Act & Assert
    CheckEquals(expected1, TPathTool::RemoveExtension(path), __func__, __LINE__, "file.txt, ansi");
    CheckEquals(expected1W, TPathTool::RemoveExtension(pathW), __func__, __LINE__, "file.txt, wide");
    CheckEquals(expected2, TPathTool::RemoveExtension(noDir), __func__, __LINE__, "file.txt no dir, ansi");
    CheckEquals(expected2W, TPathTool::RemoveExtension(noDirW), __func__, __LINE__, "file.txt no dir, wide");
    CheckEquals(pathTrailSlash, TPathTool::RemoveExtension(pathTrailSlash), __func__, __LINE__, "no file, ansi");
    CheckEquals(pathTrailSlashW, TPathTool::RemoveExtension(pathTrailSlashW), __func__, __LINE__, "no file, wide");
    CheckEquals(expected1, TPathTool::RemoveExtension(pathDot), __func__, __LINE__, "dot ext, ansi");
    CheckEquals(expected1W, TPathTool::RemoveExtension(pathDotW), __func__, __LINE__, "dot ext, wide");
}
//---------------------------------------------------------------------------

} // ASWUnitTests
