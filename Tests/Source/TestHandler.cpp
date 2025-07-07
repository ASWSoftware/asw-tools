/* **************************************************************************
TestHandler.cpp
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
#include "TestHandler.h"
//---------------------------------------------------------------------------
#include <chrono>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
//---------------------------------------------------------------------------
#include "TestException.h"
//---------------------------------------------------------------------------
#include "ASWTools_Version_Tests.h"
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestGroupBase
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTestGroupBase::TTestGroupBase(std::string const& name)
    : m_ExceptionExpected(false),
      m_Name(name)
{
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    bool expected, char actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = (expected ? "true" : "false");
        std::string actualStr = (actual ? "true" : "false");
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    char expected, char actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr(1, expected);
        std::string actualStr(1, actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    int64_t expected, int64_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    uint64_t expected, uint64_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    int32_t expected, int32_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    uint32_t expected, uint32_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    int16_t expected, int16_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    uint16_t expected, uint16_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    int8_t expected, int8_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    uint8_t expected, uint8_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(
    std::string const& expected, std::string const& actual, std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        throw TExceptEquals("Expected \"" + expected + "\" but was \"" + actual + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertEquals(std::wstring const& expected, std::wstring const& actual,
    std::string const& method, int line, std::string const& msg)
{
    if (expected != actual)
    {
        throw TExceptEquals("Expected same values. " + method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertFalse(bool testVal, std::string const& method, int line, std::string const& msg)
{
    if (testVal)
        throw TExceptFalse(method + "(" + std::to_string(line) + "): " + msg);
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    bool expected, char actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = (expected ? "true" : "false");
        std::string actualStr = (actual ? "true" : "false");
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    char expected, char actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr(1, expected);
        std::string actualStr(1, actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    int64_t expected, int64_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    uint64_t expected, uint64_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    int32_t expected, int32_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    uint32_t expected, uint32_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    int16_t expected, int16_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    uint16_t expected, uint16_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    int8_t expected, int8_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    uint8_t expected, uint8_t actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        std::string expectedStr = std::to_string(expected);
        std::string actualStr = std::to_string(actual);
        throw TExceptNotEquals("Expected \"" + expectedStr + "\" but was \"" + actualStr + "\". " +
            method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(
    std::string const& expected, std::string const& actual, std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        throw TExceptNotEquals("Expected different values. " + method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertNotEquals(std::wstring const& expected, std::wstring const& actual,
    std::string const& method, int line, std::string const& msg)
{
    if (expected == actual)
    {
        throw TExceptNotEquals("Expected different values. " + method + "(" + std::to_string(line) + "): " + msg);
    }
}
//---------------------------------------------------------------------------
void TTestGroupBase::AssertTrue(bool testVal, std::string const& method, int line, std::string const& msg)
{
    if (!testVal)
        throw TExceptFalse(method + "(" + std::to_string(line) + "): " + msg);
}
//---------------------------------------------------------------------------
void TTestGroupBase::Log(std::string const& msg)
{
    std::cout << msg << std::endl;
}
//---------------------------------------------------------------------------
/*
    TTestGroupBase::RegisterTest

    Developer: Call this method from the child of 'TTestGroupBase', in the constructor.
*/
void TTestGroupBase::RegisterTest(TestCallback callback)
{
    m_TestCallbacks.push_back(callback);
}
//---------------------------------------------------------------------------
TTestGroupBase::TestCallbackList& TTestGroupBase::GetTestCallbackList()
{
    return m_TestCallbacks;
}
//---------------------------------------------------------------------------
std::string const& TTestGroupBase::GetTestGroupName()
{
    return m_Name;
}
//---------------------------------------------------------------------------
TTestResults const& TTestGroupBase::Results()
{
    return m_Results;
}
//---------------------------------------------------------------------------
void TTestGroupBase::Run()
{
    //Test(std::bind(&TTestGroup_ASWTools_Version_Tests::Test_SetVersion, this, std::placeholders::_1));

    for (TestCallbackList::iterator it = m_TestCallbacks.begin(); it != m_TestCallbacks.end(); it++)
    {
        Test(*it);
    }
}
//---------------------------------------------------------------------------
/*
    TTestGroupBase::SetExceptionExpected

    Call with a value of true in a test where an exception is expected.
*/
void TTestGroupBase::SetExceptionExpected(bool expected, std::string const& method, int line, std::string const& msg)
{
    m_ExceptionExpected = expected;
    m_ExceptionExpectedText = method + "(" + std::to_string(line) + "): " + msg;
}
//---------------------------------------------------------------------------
/*
    TTestGroupBase::Test

    Runs the test call back and sets success/error counts and messages.
*/
void TTestGroupBase::Test(TestCallback callback)
{
    try
    {
        SetExceptionExpected(false, "", 0, "");

        callback();

        if (m_ExceptionExpected)
        {
            m_ExceptionExpected = false;
            throw TExceptExpected(m_ExceptionExpectedText);
        }

        m_Results.SuccessCount++;
    }
    catch (TTestException const& ex)
    {
        if (m_ExceptionExpected)
        {
            m_Results.SuccessCount++;
        }
        else
        {
            m_Results.FailedCount++;
            std::string msg = "***Test failed: \"" + m_Name + "\": " + ex.what();
            m_Results.Messages.push_back(msg);
            Log(msg);
        }
    }
    catch (...)
    {
        if (m_ExceptionExpected)
        {
            m_Results.SuccessCount++;
        }
        else
        {
            m_Results.FailedCount++;
            throw; // Unexpected failure
        }
    }
}
//---------------------------------------------------------------------------


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
    std::cout << "Initializing test handler and registering test groups..." << std::endl;
    RegisterTestGroups();

    std::cout << "Test groups registered: " << m_TestGroups.size() << std::endl;

    size_t totalTests = 0;

    for (ITestGroups::iterator it = m_TestGroups.begin(); it != m_TestGroups.end(); it++)
    {
        ITestGroup& testGroup = *it->get();
        totalTests += testGroup.GetTestCallbackList().size();
    }

    std::cout << "Total tests registered: " << totalTests << std::endl;
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

    m_TestGroups.push_back(std::unique_ptr<TTestGroup_ASWTools_Version_Tests>(new TTestGroup_ASWTools_Version_Tests()));

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
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\n[" << GetUTCTimeISO8601() << "] Tests started." << std::endl << std::endl;

    for (ITestGroups::iterator it = m_TestGroups.begin(); it != m_TestGroups.end(); it++)
    {
        ITestGroup& testGroup = *it->get();
        std::string const& name = testGroup.GetTestGroupName();
        size_t nTestsInGroup = testGroup.GetTestCallbackList().size();

        // set up
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "[" << GetUTCTimeISO8601() << "] Setting up group " << ++groupNum << " of "
        << nGroups << ": \"" << name << "\"" << std::endl;
        testGroup.SetUp();

        // run
        std::cout << "Running " << nTestsInGroup << " test" << (nTestsInGroup == 1 ? ". " : "s. ") << std::endl;
        testGroup.Run();
        TTestResults const& testGroupResults = testGroup.Results();
        std::cout << "Done. Succeeded: " << testGroupResults.SuccessCount
        << ", failed: " << testGroupResults.FailedCount << std::endl;

        testResults.FailedCount += testGroupResults.FailedCount;
        testResults.SuccessCount += testGroupResults.SuccessCount;
        testResults.AddMessages(testGroupResults.Messages);

        // tear down
        std::cout << "[" << GetUTCTimeISO8601() << "] Tearing down group: \"" << name << "\"" << std::endl;
        testGroup.TearDown();
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    std::cout << "\n[" << GetUTCTimeISO8601() << "] Tests done: Totals: succeeded: " << testResults.SuccessCount
    << ", failed: " << testResults.FailedCount << std::endl;

    // Get elapsed time
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Convert to hours, minutes, seconds, and milliseconds
    long long totalMilliseconds = elapsed.count();
    long long hours = totalMilliseconds / (1000 * 60 * 60);
    totalMilliseconds %= (1000 * 60 * 60);
    long long mins = totalMilliseconds / (1000 * 60);
    totalMilliseconds %= (1000 * 60);
    long long secs = totalMilliseconds / 1000;
    long long milliseconds = totalMilliseconds % 1000;

    // Display the result
    std::cout << "Elapsed time: " << std::setfill('0') << std::setw(2) << hours << "h:" << std::setfill('0')
    << std::setw(2) << mins << "m:" << std::setfill('0') << std::setw(2) << secs << "s."
    << std::setfill('0') << std::setw(3) << milliseconds << "ms\n";

    return testResults;
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
// TTestResults
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTestResults::TTestResults()
    : FailedCount(0),
      SuccessCount(0)
{
}
//---------------------------------------------------------------------------
void TTestResults::AddMessages(MsgList const& list)
{
    if (&list == &Messages)
        return;

    for (MsgList::const_iterator it = list.begin(); it != list.end(); it++)
    {
        Messages.push_back(*it);
    }
}
//---------------------------------------------------------------------------

} // namespace ASWUnitTests
