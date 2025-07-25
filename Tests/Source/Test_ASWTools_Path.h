/* **************************************************************************
Test_ASWTools_Path.h
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
#ifndef Test_ASWTools_PathH
#define Test_ASWTools_PathH
//---------------------------------------------------------------------------
#include "ASWUnitTests_TestBase.h"
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTest_ASWTools_Path
/////////////////////////////////////////////////////////////////////////////
class TTest_ASWTools_Path : public TTestGroupBase
{
private:
    typedef TTestGroupBase inherited;

private: // Test methods
    void Test_Combine();
    void Test_ExpandEnvironmentVars();
    void Test_IsDots();
    void Test_IsEnvironment();
    void Test_IsNetwork();
    void Test_IsRelative();

public:
    TTest_ASWTools_Path();
    ~TTest_ASWTools_Path() override;

    void SetUp() override;
    void TearDown() override;
};

} // ASWUnitTests

//---------------------------------------------------------------------------
#endif // #ifndef Test_ASWTools_PathH
