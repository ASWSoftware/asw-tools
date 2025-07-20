/* **************************************************************************
Main.cpp
Author: Anthony S. West - ASW Software

Console app that runs tests. Run this when making changes to ASWTools to defend against breaking changes.

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
#include <exception>
#include <iostream>
#include <tchar.h>
//---------------------------------------------------------------------------
#include "ASWUnitTests_Handler.h"
//---------------------------------------------------------------------------
using namespace ASWUnitTests;
//---------------------------------------------------------------------------

int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
    int returnCode = 0; // no error

    try
    {
        TTestHandler tester;

        tester.Initialize();

        TTestResults testResults = tester.Run();
        unsigned int nTestsFailed = testResults.FailedCount;
        if (nTestsFailed > 0)
            returnCode = 1;
    }
    catch (std::exception const& ex)
    {
        std::cout << "\nTerminating app. Unhandled exception: " << ex.what() << std::endl;
        returnCode = 2;
    }
    catch (...)
    {
        std::cout << "\nTerminating app. Unhandled exception: Unknown" << std::endl;
        returnCode = 3;
    }

#ifdef _DEBUG
    system("pause");
#endif
    return returnCode;
}
