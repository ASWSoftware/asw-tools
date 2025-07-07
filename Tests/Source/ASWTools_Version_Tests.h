/* **************************************************************************
ASWTools_Version_Tests.h
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
#ifndef ASWTools_Version_TestsH
#define ASWTools_Version_TestsH
//---------------------------------------------------------------------------
#include "TestHandler.h"
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestGroup_ASWTools_Version_Tests
/////////////////////////////////////////////////////////////////////////////
class TTestGroup_ASWTools_Version_Tests : public TTestGroupBase
{
private:
    typedef TTestGroupBase inherited;

private: // Test methods
    void Test_Compare();
    void Test_Copy();
    void Test_ExtractVersionNumbersFromVersionStr();
    void Test_SetVersion();

public:
    TTestGroup_ASWTools_Version_Tests();
    ~TTestGroup_ASWTools_Version_Tests() override;

    void SetUp() override;
    void TearDown() override;
};

} // ASWUnitTests

//---------------------------------------------------------------------------
#endif // #ifndef ASWTools_Version_TestsH
