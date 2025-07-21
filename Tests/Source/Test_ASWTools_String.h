/* **************************************************************************
Test_ASWTools_String.h
Author: Anthony S. West - ASW Software

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
#ifndef Test_ASWTools_StringH
#define Test_ASWTools_StringH
//---------------------------------------------------------------------------
#include "ASWUnitTests_TestBase.h"
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTest_ASWTools_String
/////////////////////////////////////////////////////////////////////////////
class TTest_ASWTools_String : public TTestGroupBase
{
private:
    typedef TTestGroupBase inherited;

private: // Test methods
    void Test_Compare();
    void Test_CompareIC();
    void Test_Contains();
    void Test_ContainsIC();
    void Test_DateTime_GetMinDate_ISO8601();
    void Test_DateTime_GetUTCNow_ISO8601();
    void Test_EncodeStrToBase16Hex();
    void Test_EncodeStrToBase16Hex_Length();
    void Test_EncodeStrToBase64Str();
    void Test_EncodeStrToBase64Str_Length();
    void Test_EncodeToBase16Hex_Bytes();
    void Test_EncodeToBase64Str_Native();
    void Test_EndsWith();
    void Test_EndsWithIC();
    void Test_Fmt_printf();
    void Test_HexSingleToByte();
    void Test_IsEmptyOrWhiteSpace();
    void Test_IsSpace();
    void Test_IsValidBase64();
    void Test_Join();
    void Test_ReplaceAll();
    void Test_ReplaceAll_Char();
    void Test_Split();
    void Test_StartsWith();
    void Test_StartsWithIC();
    void Test_StrToInt32();
    void Test_StrToInt32_Invalid();
    void Test_ToLower();
    void Test_ToUpper();
    void Test_Trim();
    void Test_TrimLeft_Copy();
    void Test_TrimRight_Copy();
    void Test_TryStrToInt32();
    void Test_URL_EncodeDecode();

public:
    TTest_ASWTools_String();
    ~TTest_ASWTools_String() override;

    void SetUp() override;
    void TearDown() override;
};

} // ASWUnitTests

//---------------------------------------------------------------------------
#endif // #ifndef Test_ASWTools_StringH
