/* **************************************************************************
ASWUnitTests_Handler.cpp
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
#include "ASWUnitTests_Handler.h"
//---------------------------------------------------------------------------
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
//---------------------------------------------------------------------------
#include "ASWUnitTests_Exception.h"
//---------------------------------------------------------------------------
#include "Test_ASWTools_Path.h"
#include "Test_ASWTools_Random.h"
#include "Test_ASWTools_String.h"
#include "Test_ASWTools_Version.h"
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestHandler
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTestHandler::TTestHandler()
{
}
//---------------------------------------------------------------------------
TTestHandler::~TTestHandler()
{
}
//---------------------------------------------------------------------------
std::string TTestHandler::GetUTCTimeISO8601()
{
    // Get the current time as a time_point
    auto now = std::chrono::system_clock::now();

    // Convert to time_t for time manipulation
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    auto milliSecs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    // Convert to UTC time structure
    std::tm utc_tm = *std::gmtime(&now_time_t);

    // Format the time into a string
    std::ostringstream oss;
    oss << std::put_time(&utc_tm, "%Y-%m-%dT%H:%M:%S") << '.'
    << std::setfill('0') << std::setw(3) << milliSecs.count() << "Z";
    return oss.str();
}
//---------------------------------------------------------------------------
void TTestHandler::Initialize()
{
    Log("Initializing test handler and registering test groups...");
    RegisterTestGroups();

    Log("Test groups registered: " + std::to_string(m_TestGroups.size()));

    size_t totalTests = 0;

    for (ITestGroups::iterator it = m_TestGroups.begin(); it != m_TestGroups.end(); it++)
    {
        ITestGroup& testGroup = *it->get();
        totalTests += testGroup.GetTestCallbackList().size();
    }

    Log("Total tests registered: " + std::to_string(totalTests));
}
//---------------------------------------------------------------------------
void TTestHandler::Log(std::string const& msg)
{
    std::cout << msg << std::endl;
}
//---------------------------------------------------------------------------
void TTestHandler::LogAppend(std::string const& msg)
{
    std::cout << msg;
}
//---------------------------------------------------------------------------
/*
    TTestHandler::RegisterTestGroups

    Developer: Add test modules here.
*/
void TTestHandler::RegisterTestGroups()
{
    // Example of how to add a module:
    // m_TestGroups.push_back(std::unique_ptr<TestClassName>(new TestClassName()));

    // ----- Add each class to be tested

    m_TestGroups.push_back(std::unique_ptr<TTest_ASWTools_Path>(new TTest_ASWTools_Path()));
    m_TestGroups.push_back(std::unique_ptr<TTest_ASWTools_String>(new TTest_ASWTools_String()));
    m_TestGroups.push_back(std::unique_ptr<TTest_ASWTools_Version>(new TTest_ASWTools_Version()));
    m_TestGroups.push_back(std::unique_ptr<TTest_TMersenneTwisterRandom>(new TTest_TMersenneTwisterRandom()));

    // ----- End adding classes to be tested
}
//---------------------------------------------------------------------------
/*
    TTestHandler::Run

    Returns the number of tests that failed.
*/
TTestResults TTestHandler::Run()
{
    TTestResults testResults;
    size_t groupNum = 0;
    size_t nGroups = m_TestGroups.size();
    std::chrono::high_resolution_clock::time_point const start = std::chrono::high_resolution_clock::now();

    Log("\n[" + GetUTCTimeISO8601() + "] Tests started.\n");

    for (ITestGroups::iterator it = m_TestGroups.begin(); it != m_TestGroups.end(); it++)
    {
        ITestGroup& testGroup = *it->get();
        std::string const& name = testGroup.GetTestGroupName();
        size_t nTestsInGroup = testGroup.GetTestCallbackList().size();

        // set up
        Log("--------------------------------------------------------------------------------");
        Log("[" + GetUTCTimeISO8601() + "] Setting up group " + std::to_string(++groupNum) + " of " +
            std::to_string(nGroups) + ": \"" + name + "\"");
        testGroup.SetUp_Group();

        // run
        Log("Running " + std::to_string(nTestsInGroup) + " test" + std::string((nTestsInGroup == 1) ? "." : "s."));
        testGroup.Run();
        TTestResults const& testGroupResults = testGroup.Results();
        Log("Done. Succeeded: " + std::to_string(testGroupResults.SuccessCount) + ", failed: " +
            std::to_string(testGroupResults.FailedCount));

        testResults.FailedCount += testGroupResults.FailedCount;
        testResults.SuccessCount += testGroupResults.SuccessCount;
        testResults.AddMessages(testGroupResults.Messages);

        // tear down
        Log("[" + GetUTCTimeISO8601() + "] Tearing down group: \"" + name + "\"");
        testGroup.TearDown_Group();
    }

    std::chrono::high_resolution_clock::time_point const end = std::chrono::high_resolution_clock::now();

    Log("--------------------------------------------------------------------------------");

    Log("\n[" + GetUTCTimeISO8601() + "] Tests done: Totals: succeeded: " + std::to_string(testResults.SuccessCount) +
        ", failed: " + std::to_string(testResults.FailedCount));

    // Get elapsed time
    std::chrono::milliseconds const elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Convert to hours, minutes, seconds, and milliseconds
    long long totalMilliseconds = elapsed.count();
    long long const hours = totalMilliseconds / (1000 * 60 * 60);
    totalMilliseconds %= (1000 * 60 * 60);
    long long const mins = totalMilliseconds / (1000 * 60);
    totalMilliseconds %= (1000 * 60);
    long long const secs = totalMilliseconds / 1000;
    long long const milliseconds = totalMilliseconds % 1000;

    // Display the result
    std::stringstream ss;
    ss << "Elapsed time: " << std::setfill('0') << std::setw(2) << hours << "h:" << std::setfill('0')
    << std::setw(2) << mins << "m:" << std::setfill('0') << std::setw(2) << secs << "s."
    << std::setfill('0') << std::setw(3) << milliseconds << "ms";
    Log(ss.str());

    return testResults;
}
//---------------------------------------------------------------------------

} // namespace ASWUnitTests
