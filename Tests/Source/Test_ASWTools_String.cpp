/* **************************************************************************
Test_ASWTools_String.cpp
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
#include "Test_ASWTools_String.h"
//---------------------------------------------------------------------------
#include "ASWTools_String.h"
//---------------------------------------------------------------------------
using namespace ASWTools;
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTest_ASWTools_String
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTest_ASWTools_String::TTest_ASWTools_String()
    : inherited("ASWTools_String_Tests")
{
    RegisterTest(Test_Compare);
    RegisterTest(Test_CompareIC);
    RegisterTest(Test_Contains);
    RegisterTest(Test_ContainsIC);
    RegisterTest(Test_DateTime_GetMinDate_ISO8601);
    RegisterTest(Test_DateTime_GetUTCNow_ISO8601);
    RegisterTest(Test_EncodeStrToBase16Hex);
    RegisterTest(Test_EncodeStrToBase16Hex_Length);
    RegisterTest(Test_EncodeStrToBase64Str);
    RegisterTest(Test_EncodeStrToBase64Str_Length);
    RegisterTest(Test_EncodeToBase16Hex_Bytes);
    RegisterTest(Test_EncodeToBase64Str_Native);
    RegisterTest(Test_EndsWith);
    RegisterTest(Test_EndsWithIC);
    RegisterTest(Test_Fmt_printf);
    RegisterTest(Test_HexSingleToByte);
    RegisterTest(Test_IsEmptyOrWhiteSpace);
    RegisterTest(Test_IsSpace);
    RegisterTest(Test_IsValidBase64);
    RegisterTest(Test_Join);
    RegisterTest(Test_ReplaceAll);
    RegisterTest(Test_ReplaceAll_Char);
    RegisterTest(Test_Split);
    RegisterTest(Test_StartsWith);
    RegisterTest(Test_StartsWithIC);
    RegisterTest(Test_StrToInt32);
    RegisterTest(Test_StrToInt32_Invalid);
    RegisterTest(Test_ToLower);
    RegisterTest(Test_ToUpper);
    RegisterTest(Test_Trim);
    RegisterTest(Test_TrimLeft_Copy);
    RegisterTest(Test_TrimRight_Copy);
    RegisterTest(Test_TryStrToInt32);
    RegisterTest(Test_URL_EncodeDecode);
}
//---------------------------------------------------------------------------
TTest_ASWTools_String::~TTest_ASWTools_String()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::SetUp()
{
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::TearDown()
{
}
//---------------------------------------------------------------------------

// /////// Begin tests after this line ///////////////////////

//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_Compare()
{
    // Arrange
    std::string s1 = "abc";
    std::string s2 = "abc";
    std::string s3 = "def";
    std::wstring s1W = L"abc";
    std::wstring s2W = L"abc";
    std::wstring s3W = L"def";

    // Act & Assert
    CheckEquals(0, TStrTool::Compare(s1, s2), __func__, __LINE__, "Compare equal, ansi");
    CheckTrue(TStrTool::Compare(s1, s3) < 0, __func__, __LINE__, "Compare less, ansi");
    CheckTrue(TStrTool::Compare(s3, s1) > 0, __func__, __LINE__, "Compare greater, ansi");
    CheckEquals(0, TStrTool::Compare(s1W, s2W), __func__, __LINE__, "Compare equal, wide");
    CheckTrue(TStrTool::Compare(s1W, s3W) < 0, __func__, __LINE__, "Compare less, wide");
    CheckTrue(TStrTool::Compare(s3W, s1W) > 0, __func__, __LINE__, "Compare greater, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_CompareIC()
{
    // Arrange
    std::string s1 = "abc";
    std::string s2 = "ABC";
    std::string s3 = "def";
    std::wstring s1W = L"abc";
    std::wstring s2W = L"ABC";
    std::wstring s3W = L"def";

    // Act & Assert
    CheckEquals(0, TStrTool::CompareIC(s1, s2), __func__, __LINE__, "CompareIC equal, ansi");
    CheckTrue(TStrTool::CompareIC(s1, s3) < 0, __func__, __LINE__, "CompareIC less, ansi");
    CheckTrue(TStrTool::CompareIC(s3, s1) > 0, __func__, __LINE__, "CompareIC greater, ansi");
    CheckEquals(0, TStrTool::CompareIC(s1W, s2W), __func__, __LINE__, "CompareIC equal, wide");
    CheckTrue(TStrTool::CompareIC(s1W, s3W) < 0, __func__, __LINE__, "CompareIC less, wide");
    CheckTrue(TStrTool::CompareIC(s3W, s1W) > 0, __func__, __LINE__, "CompareIC greater, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_Contains()
{
    // Arrange
    std::string s = "hello world";
    std::wstring ws = L"hello world";

    // Act & Assert
    CheckTrue(TStrTool::Contains(s, "world"), __func__, __LINE__, "Contains ansi");
    CheckTrue(TStrTool::Contains(ws, L"world"), __func__, __LINE__, "Contains wide");
    CheckFalse(TStrTool::Contains(s, "foo"), __func__, __LINE__, "Not contains ansi");
    CheckFalse(TStrTool::Contains(ws, L"foo"), __func__, __LINE__, "Not contains wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_ContainsIC()
{
    // Arrange
    std::string s = "Hello World";
    std::wstring ws = L"Hello World";

    // Act & Assert
    CheckTrue(TStrTool::ContainsIC(s, "world"), __func__, __LINE__, "ContainsIC, ansi");
    CheckFalse(TStrTool::ContainsIC(s, "foo"), __func__, __LINE__, "ContainsIC not found, ansi");
    CheckTrue(TStrTool::ContainsIC(ws, L"world"), __func__, __LINE__, "ContainsIC, wide");
    CheckFalse(TStrTool::ContainsIC(ws, L"foo"), __func__, __LINE__, "ContainsIC not found, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_DateTime_GetMinDate_ISO8601()
{
    // Arrange
    std::string expected = "0001-01-01T00:00:00Z";

    // Act
    auto minDate = TStrTool::DateTime_GetMinDate_ISO8601();

    // Assert
    CheckEquals(expected, minDate, __func__, __LINE__, "MinDate ISO8601 format");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_DateTime_GetUTCNow_ISO8601()
{
    // Arrange
    // Act
    std::string now = TStrTool::DateTime_GetUTCNow_ISO8601();
    bool hasZ = TStrTool::ContainsIC(now, "Z");

    // Assert
    CheckTrue(now.length() >= 20, __func__, __LINE__, "UTCNow ISO8601 format");
    CheckTrue(hasZ, __func__, __LINE__, "UTCNow ISO8601 Has Z");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EncodeStrToBase16Hex()
{
    // Arrange
    std::string s = "abc123z";
    std::wstring ws = L"abcz";

    // Act
    auto hexLower = TStrTool::EncodeStrToBase16Hex(s, false);
    auto hexUpper = TStrTool::EncodeStrToBase16Hex(s, true);
    auto hexWLower = TStrTool::EncodeStrToBase16Hex(ws, false);
    auto hexWUpper = TStrTool::EncodeStrToBase16Hex(ws, true);

    // Assert
    CheckEquals("6162633132337a", hexLower, __func__, __LINE__, "Base16 hex lower, ansi");
    CheckEquals("6100620063007a00", hexWLower, __func__, __LINE__, "Base16 hex lower, wide");
    CheckEquals("6162633132337A", hexUpper, __func__, __LINE__, "Base16 hex upper, ansi");
    CheckEquals("6100620063007A00", hexWUpper, __func__, __LINE__, "Base16 hex upper, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EncodeStrToBase16Hex_Length()
{
    // Arrange
    std::string s = "abcdef";
    std::wstring ws = L"abcdef";
    size_t len = 3;

    // Act
    auto hexLower = TStrTool::EncodeStrToBase16Hex(s, len, false);
    auto hexUpper = TStrTool::EncodeStrToBase16Hex(s, len, true);
    auto hexWLower = TStrTool::EncodeStrToBase16Hex(ws, len, false);
    auto hexWUpper = TStrTool::EncodeStrToBase16Hex(ws, len, true);

    // Assert
    CheckEquals("616263", hexLower, __func__, __LINE__, "Base16 hex lower, length");
    CheckEquals("616263", hexUpper, __func__, __LINE__, "Base16 hex upper, length");
    CheckEquals("610062006300", hexWLower, __func__, __LINE__, "Base16 hex wide lower, length");
    CheckEquals("610062006300", hexWUpper, __func__, __LINE__, "Base16 hex wide upper, length");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EncodeStrToBase64Str()
{
    // Arrange
    std::string s = "abc";
    std::wstring ws = L"abc";

    // Act
    auto b64 = TStrTool::EncodeStrToBase64Str(s, false);
    auto b64W = TStrTool::EncodeStrToBase64Str(ws, false);

    // Assert
    CheckEquals("YWJj", b64, __func__, __LINE__, "Base64, ansi");
    CheckEquals("YQBiAGMA", b64W, __func__, __LINE__, "Base64, wide");
    CheckEquals(s, TStrTool::DecodeBase64ToStrA(b64), __func__, __LINE__, "DecodeBase64, ansi");
    CheckEquals(ws, TStrTool::DecodeBase64ToStrW(b64W), __func__, __LINE__, "DecodeBase64, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EncodeStrToBase64Str_Length()
{
    // Arrange
    std::string s = "abcdef";
    std::wstring ws = L"abcdef";
    size_t len = 3;

    // Act
    auto b64 = TStrTool::EncodeStrToBase64Str(s, len, false);
    auto b64W = TStrTool::EncodeStrToBase64Str(ws, len, false);

    // Assert
    CheckEquals("YWJj", b64, __func__, __LINE__, "Base64 ansi, length");
    CheckEquals("YQBiAGMA", b64W, __func__, __LINE__, "Base64 wide, length");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EndsWith()
{
    // Arrange
    std::string s = "hello world";
    std::wstring ws = L"hello world";

    // Act & Assert
    CheckTrue(TStrTool::EndsWith(s, "world"), __func__, __LINE__, "EndsWith ansi");
    CheckTrue(TStrTool::EndsWith(ws, L"world"), __func__, __LINE__, "EndsWith wide");
    CheckFalse(TStrTool::EndsWith(s, "hello"), __func__, __LINE__, "Not endsWith ansi");
    CheckFalse(TStrTool::EndsWith(ws, L"hello"), __func__, __LINE__, "Not endsWith wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EndsWithIC()
{
    // Arrange
    std::string s = "Hello World";
    std::wstring ws = L"Hello World";

    // Act & Assert
    CheckTrue(TStrTool::EndsWithIC(s, "world"), __func__, __LINE__, "EndsWithIC ansi");
    CheckTrue(TStrTool::EndsWithIC(ws, L"world"), __func__, __LINE__, "EndsWithIC wide");
    CheckFalse(TStrTool::EndsWithIC(s, "hello"), __func__, __LINE__, "Not endsWithIC ansi");
    CheckFalse(TStrTool::EndsWithIC(ws, L"hello"), __func__, __LINE__, "Not endsWithIC wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_HexSingleToByte()
{
    // Arrange
    char hex1 = 'A';
    char hex2 = 'f';
    char hex3 = '0';
    char hex4 = '9';

    // Act & Assert
    CheckEquals(10, TStrTool::HexSingleToByte(hex1), __func__, __LINE__, "HexSingleToByte A");
    CheckEquals(15, TStrTool::HexSingleToByte(hex2), __func__, __LINE__, "HexSingleToByte f");
    CheckEquals(0, TStrTool::HexSingleToByte(hex3), __func__, __LINE__, "HexSingleToByte 0");
    CheckEquals(9, TStrTool::HexSingleToByte(hex4), __func__, __LINE__, "HexSingleToByte 9");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EncodeToBase16Hex_Bytes()
{
    // Arrange
    BYTE bytes[] = { 0xDE, 0xAD, 0xBE, 0xEF };
    size_t len = 4;

    // Act
    auto hexLower = TStrTool::EncodeToBase16Hex(bytes, len, false);
    auto hexUpper = TStrTool::EncodeToBase16Hex(bytes, len, true);

    // Assert
    CheckEquals("deadbeef", hexLower, __func__, __LINE__, "EncodeToBase16Hex lower");
    CheckEquals("DEADBEEF", hexUpper, __func__, __LINE__, "EncodeToBase16Hex upper");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_EncodeToBase64Str_Native()
{
    // Arrange
    BYTE bytes[] = { 'a', 'b', 'c' };
    size_t len = 3;

    // Act
    auto b64 = TStrTool::EncodeToBase64Str_Native(bytes, len, false);
    auto b64Web = TStrTool::EncodeToBase64Str_Native(bytes, len, true);

    // Assert
    CheckEquals("YWJj", b64, __func__, __LINE__, "Base64 native");
    CheckEquals("YWJj", b64Web, __func__, __LINE__, "Base64 native web");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_Fmt_printf()
{
    // Arrange
    int val = 42;
    double dval = 3.14;

    // Act
    std::string s = TStrTool::Fmt_printf("Value: %d, Pi: %.2f", val, dval);
    std::wstring ws = TStrTool::Fmt_printf(L"Value: %d, Pi: %.2f", val, dval);

    // Assert
    CheckTrue(s.find("Value: 42") != std::string::npos, __func__, __LINE__, "Fmt_printf Value, ansi");
    CheckTrue(ws.find(L"Value: 42") != std::wstring::npos, __func__, __LINE__, "Fmt_printf Value, wide");
    CheckTrue(s.find("Pi: 3.14") != std::string::npos, __func__, __LINE__, "Fmt_printf Pi, ansi");
    CheckTrue(ws.find(L"Pi: 3.14") != std::wstring::npos, __func__, __LINE__, "Fmt_printf Pi, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_IsEmptyOrWhiteSpace()
{
    // Arrange
    std::string s1 = "";
    std::string s2 = "   ";
    std::string s3 = "abc";
    std::wstring ws1 = L"";
    std::wstring ws2 = L"   ";
    std::wstring ws3 = L"abc";

    // Act & Assert
    CheckTrue(TStrTool::IsEmptyOrWhiteSpace(s1), __func__, __LINE__, "Empty, ansi");
    CheckTrue(TStrTool::IsEmptyOrWhiteSpace(s2), __func__, __LINE__, "Whitespace, ansi");
    CheckFalse(TStrTool::IsEmptyOrWhiteSpace(s3), __func__, __LINE__, "Not empty, ansi");
    CheckTrue(TStrTool::IsEmptyOrWhiteSpace(ws1), __func__, __LINE__, "Empty, wide");
    CheckTrue(TStrTool::IsEmptyOrWhiteSpace(ws2), __func__, __LINE__, "Whitespace, wide");
    CheckFalse(TStrTool::IsEmptyOrWhiteSpace(ws3), __func__, __LINE__, "Not empty, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_IsSpace()
{
    // Arrange
    int space = ' ';
    int tab = '\t';
    int letter = 'A';

    // Act & Assert
    CheckTrue(TStrTool::IsSpace(space), __func__, __LINE__, "IsSpace space");
    CheckTrue(TStrTool::IsSpace(tab), __func__, __LINE__, "IsSpace tab");
    CheckFalse(TStrTool::IsSpace(letter), __func__, __LINE__, "IsSpace letter");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_IsValidBase64()
{
    // Arrange
    std::string valid = "YWJj+/";
    std::string validUrlSafe = "YWJj-_";
    std::string invalid = "YWJj$";

    // Act & Assert
    CheckTrue(TStrTool::IsValidBase64(valid, false), __func__, __LINE__, "IsValidBase64 valid");
    CheckTrue(TStrTool::IsValidBase64(validUrlSafe, true), __func__, __LINE__, "IsValidBase64 valid UrlSafe");
    CheckFalse(TStrTool::IsValidBase64(invalid, false), __func__, __LINE__, "IsValidBase64 invalid");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_Join()
{
    // Arrange
    std::vector<std::string> parts = { "a", "b", "c" };
    std::vector<std::wstring> partsW = { L"a", L"b", L"c" };

    // Act
    auto joined = TStrTool::Join(parts, ",");
    auto joinedW = TStrTool::Join(partsW, L",");

    // Assert
    CheckEquals("a,b,c", joined, __func__, __LINE__, "Join ansi");
    CheckEquals(L"a,b,c", joinedW, __func__, __LINE__, "Join wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_ReplaceAll()
{
    // Arrange
    std::string s = "foo bar foo";
    std::wstring ws = L"foo bar foo";

    // Act
    auto replaced = TStrTool::ReplaceAll(s, "foo", "baz");
    auto replacedW = TStrTool::ReplaceAll(ws, L"foo", L"baz");

    // Assert
    CheckEquals("baz bar baz", replaced, __func__, __LINE__, "Replace ansi");
    CheckEquals(L"baz bar baz", replacedW, __func__, __LINE__, "Replace wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_ReplaceAll_Char()
{
    // Arrange
    std::string s = "a.b.c";
    std::wstring ws = L"a.b.c";

    // Act
    auto replaced = TStrTool::ReplaceAll(s, '.', '-');
    auto replacedW = TStrTool::ReplaceAll(ws, L'.', L'-');

    // Assert
    CheckEquals("a-b-c", replaced, __func__, __LINE__, "ReplaceAll char, ansi");
    CheckEquals(L"a-b-c", replacedW, __func__, __LINE__, "ReplaceAll char, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_Split()
{
    // Arrange
    std::string s = "a,b,c";
    std::wstring ws = L"a,b,c";

    // Act
    auto parts = TStrTool::Split(s, ',');
    auto partsW = TStrTool::Split(ws, L',');

    // Assert
    CheckEquals(static_cast<size_t>(3), parts.size(), __func__, __LINE__, "Split count ansi");
    CheckEquals("a", parts[0], __func__, __LINE__, "Split first ansi");
    CheckEquals("b", parts[1], __func__, __LINE__, "Split second ansi");
    CheckEquals("c", parts[2], __func__, __LINE__, "Split third ansi");

    CheckEquals(static_cast<size_t>(3), partsW.size(), __func__, __LINE__, "Split count wide");
    CheckEquals(L"a", partsW[0], __func__, __LINE__, "Split first wide");
    CheckEquals(L"b", partsW[1], __func__, __LINE__, "Split second wide");
    CheckEquals(L"c", partsW[2], __func__, __LINE__, "Split third wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_StartsWith()
{
    // Arrange
    std::string s = "hello world";
    std::wstring ws = L"hello world";

    // Act & Assert
    CheckTrue(TStrTool::StartsWith(s, "hello"), __func__, __LINE__, "StartsWith ansi");
    CheckTrue(TStrTool::StartsWith(ws, L"hello"), __func__, __LINE__, "StartsWith wide");
    CheckFalse(TStrTool::StartsWith(s, "world"), __func__, __LINE__, "Not startsWith ansi");
    CheckFalse(TStrTool::StartsWith(ws, L"world"), __func__, __LINE__, "Not startsWith wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_StartsWithIC()
{
    // Arrange
    std::string s = "HelloWorld";
    std::wstring ws = L"HelloWorld";

    // Act & Assert
    CheckTrue(TStrTool::StartsWithIC(s, "hello"), __func__, __LINE__, "StartsWithIC, ansi");
    CheckFalse(TStrTool::StartsWithIC(s, "world"), __func__, __LINE__, "StartsWithIC false, ansi");
    CheckTrue(TStrTool::StartsWithIC(ws, L"hello"), __func__, __LINE__, "StartsWithIC, wide");
    CheckFalse(TStrTool::StartsWithIC(ws, L"world"), __func__, __LINE__, "StartsWithIC false, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_StrToInt32()
{
    // Arrange
    std::string valid = "123";

    // Act
    int32_t v = TStrTool::StrToInt32(valid);

    // Assert
    CheckEquals(123, v, __func__, __LINE__, "StrToInt32 valid");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_StrToInt32_Invalid()
{
    // Arrange
    std::string invalid = "abc";

    // Act & Assert
    SetExceptionExpected(true, __func__, __LINE__, "StrToInt32 invalid");
    int32_t i = TStrTool::StrToInt32(invalid);

    // Assert
    AssertEquals(1, i, __func__, __LINE__, "StrToInt32 invalid - shouldn't get here");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_ToLower()
{
    // Arrange
    std::string s = "abcDEF";
    std::wstring ws = L"abcDEF";

    // Act
    auto lower = TStrTool::ToLower(s);
    auto lowerW = TStrTool::ToLower(ws);

    // Assert
    CheckEquals("abcdef", lower, __func__, __LINE__, "ToLower ansi");
    CheckEquals(L"abcdef", lowerW, __func__, __LINE__, "ToLower wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_ToUpper()
{
    // Arrange
    std::string s = "abcDEF";
    std::wstring ws = L"abcDEF";

    // Act
    auto upper = TStrTool::ToUpper(s);
    auto upperW = TStrTool::ToUpper(ws);

    // Assert
    CheckEquals("ABCDEF", upper, __func__, __LINE__, "ToUpper ansi");
    CheckEquals(L"ABCDEF", upperW, __func__, __LINE__, "ToUpper wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_Trim()
{
    // Arrange
    std::string s = "  hello world  ";
    std::wstring ws = L"  hello world  ";

    // Act
    auto trimmed = TStrTool::Trim_Copy(s);
    auto trimmedW = TStrTool::Trim_Copy(ws);

    // Assert
    CheckEquals("hello world", trimmed, __func__, __LINE__, "Trim ansi");
    CheckEquals(L"hello world", trimmedW, __func__, __LINE__, "Trim wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_TrimLeft_Copy()
{
    // Arrange
    std::string s = "   abc";
    std::wstring ws = L"   abc";

    // Act
    auto trimmed = TStrTool::TrimLeft_Copy(s);
    auto trimmedW = TStrTool::TrimLeft_Copy(ws);

    // Assert
    CheckEquals("abc", trimmed, __func__, __LINE__, "TrimLeft_Copy, ansi");
    CheckEquals(L"abc", trimmedW, __func__, __LINE__, "TrimLeft_Copy, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_TrimRight_Copy()
{
    // Arrange
    std::string s = "abc   ";
    std::wstring ws = L"abc   ";

    // Act
    auto trimmed = TStrTool::TrimRight_Copy(s);
    auto trimmedW = TStrTool::TrimRight_Copy(ws);

    // Assert
    CheckEquals("abc", trimmed, __func__, __LINE__, "TrimRight_Copy, ansi");
    CheckEquals(L"abc", trimmedW, __func__, __LINE__, "TrimRight_Copy, wide");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_TryStrToInt32()
{
    // Arrange
    int32_t val = 0;
    int32_t valDummy = 0;

    // Act
    bool ok = TStrTool::TryStrToInt32("456", &val);
    bool fail = TStrTool::TryStrToInt32("abc", &valDummy);

    // Assert
    CheckTrue(ok, __func__, __LINE__, "TryStrToInt32 valid");
    CheckEquals(456, val, __func__, __LINE__, "TryStrToInt32 value");
    CheckFalse(fail, __func__, __LINE__, "TryStrToInt32 invalid");
}
//---------------------------------------------------------------------------
void TTest_ASWTools_String::Test_URL_EncodeDecode()
{
    // Arrange
    std::string url = "a b+c/d";
    bool invalid = false;

    // Act
    auto encoded = TStrTool::URL_EncodeUtf8(url);
    auto decoded = TStrTool::URL_DecodeUtf8(encoded, &invalid);

    // Assert
    CheckEquals("a%20b%2Bc%2Fd", encoded, __func__, __LINE__, "URL encode");
    CheckEquals(url, decoded, __func__, __LINE__, "URL decode");
    CheckFalse(invalid, __func__, __LINE__, "URL decode valid");
}
//---------------------------------------------------------------------------

} // namespace ASWUnitTests
