/* **************************************************************************
ASWUnitTests_TestBase.cpp
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
#include "ASWUnitTests_TestBase.h"
//---------------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <sstream>
//---------------------------------------------------------------------------
#include "ASWUnitTests_Exception.h"
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
