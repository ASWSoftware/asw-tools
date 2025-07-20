/* **************************************************************************
ASWUnitTests_Handler.h
Author: Anthony S. West - ASW Software

A simple unit testing framework.

Requires C++ 11 or higher.

To register a test module, create a class that inherits 'TTestGroupBase'.
Add the module's .h and register it in: 'TTestHandler::RegisterTestGroups()'

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

#ifndef ASWUnitTests_HandlerH
#define ASWUnitTests_HandlerH
//---------------------------------------------------------------------------
#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include "ASWUnitTests_TestBase.h"
//---------------------------------------------------------------------------

//#if __cplusplus < 201103L
//
//#if !defined(nullptr)
//#  define nullptr NULL
//#endif
//
//#if !defined(override)
//#  define override
//#endif
//
//#endif // #if __cplusplus < 201103L

//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestHandler
//
// Handles the registration running of tests
/////////////////////////////////////////////////////////////////////////////
class TTestHandler
{
private:
    typedef std::vector<std::unique_ptr<ITestGroup> > ITestGroups;

private:
    ITestGroups m_TestGroups;

private:
    void RegisterTestGroups();

public:
    static std::string GetUTCTimeISO8601();

public:
    TTestHandler();
    ~TTestHandler();

    void Initialize();
    TTestResults Run();
};

} // namespace ASWUnitTests

#endif // #ifndef TestHandlerH
