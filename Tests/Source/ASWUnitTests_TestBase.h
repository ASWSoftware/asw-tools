/* **************************************************************************
ASWUnitTests_TestBase.h
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

#ifndef ASWUnitTests_TestBaseH
#define ASWUnitTests_TestBaseH
//---------------------------------------------------------------------------
#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestResults
//
// Stores test results.
// Provides common comparison methods that bump the counts on success/fail.
/////////////////////////////////////////////////////////////////////////////
class TTestResults
{
public:
    typedef std::vector<std::string> MsgList;

public:
    unsigned int FailedCount;
    unsigned int SuccessCount;
    MsgList Messages;

public:
    TTestResults();

    void AddMessages(MsgList const& list);
};


/////////////////////////////////////////////////////////////////////////////
// ITestGroup
//
// Interface for a test group.
/////////////////////////////////////////////////////////////////////////////
class ITestGroup
{
public:
    typedef std::function<void ()> TestCallback;
    typedef std::vector<TestCallback> TestCallbackList;

public:
    virtual ~ITestGroup()
    {
    }

    virtual TestCallbackList& GetTestCallbackList() = 0;
    virtual std::string const& GetTestGroupName() const = 0;
    virtual TTestResults const& Results() const = 0;
    virtual void Run() = 0;
    virtual void SetUp() = 0;
    virtual void TearDown() = 0;
};


/////////////////////////////////////////////////////////////////////////////
// TTestGroupBase
//
// Abstract class for a test group that contains limited members for
// assertion testing.
//
// - 'Assert' methods cause the test to immediately fail.
// - 'Check' methods allow multiple "asserts" per test.
/////////////////////////////////////////////////////////////////////////////
class TTestGroupBase : public ITestGroup
{
private:
    typedef ITestGroup inherited;

protected:
    bool m_ExceptionExpected;
    bool m_TestFailedCheck;
    std::string m_ExceptionExpectedText;
    std::string m_Name;
    TTestResults m_Results;
    TestCallbackList m_TestCallbacks;

    virtual void Log(std::string const& msg);
    virtual void RegisterTest(TestCallback callback);
    virtual void ResetTestFailedOneOrMoreChecks();
    virtual void SetExceptionExpected(bool expected, std::string const& method, int line, std::string const& msg);
    virtual void SetTestFailedCheck(std::string const& method, int line, std::string const& msg);
    virtual void SetTestFailedCheck(std::string const& method, int line, std::string const& expected,
        std::string const& actual, std::string const& msg);
    virtual void SetTestFailedCheckNotEquals(std::string const& method, int line, std::string const& msg);
    virtual void SetTestFailedCheckNotEquals(std::string const& method, int line, std::string const& value,
        std::string const& msg);
    virtual void Test(TestCallback callback); // Child classes call this for performing the test
    virtual bool TestFailedOneOrMoreChecks();

protected: // Assertion/Check methods - Equals
    virtual void AssertEquals(
        bool expected, bool actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        int64_t expected, int64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        uint64_t expected, uint64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        int32_t expected, int32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        uint32_t expected, uint32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        int16_t expected, int16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        uint16_t expected, uint16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        int8_t expected, int8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(
        uint8_t expected, uint8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertEquals(std::string const& expected, std::string const& actual, std::string const& method,
        int line, std::string const& msg);
    virtual void AssertEquals(std::wstring const& expected, std::wstring const& actual, std::string const& method,
        int line, std::string const& msg);

    virtual void CheckEquals(
        bool expected, bool actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        int64_t expected, int64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        uint64_t expected, uint64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        int32_t expected, int32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        uint32_t expected, uint32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        int16_t expected, int16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        uint16_t expected, uint16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        int8_t expected, int8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(
        uint8_t expected, uint8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckEquals(std::string const& expected, std::string const& actual, std::string const& method,
        int line, std::string const& msg);
    virtual void CheckEquals(std::wstring const& expected, std::wstring const& actual, std::string const& method,
        int line, std::string const& msg);

protected: // Assertion/Check methods - Not Equals
    virtual void AssertNotEquals(
        bool expected, bool actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        int64_t expected, int64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        uint64_t expected, uint64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        int32_t expected, int32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        uint32_t expected, uint32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        int16_t expected, int16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        uint16_t expected, uint16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        int8_t expected, int8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(
        uint8_t expected, uint8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void AssertNotEquals(std::string const& expected, std::string const& actual, std::string const& method,
        int line, std::string const& msg);
    virtual void AssertNotEquals(std::wstring const& expected, std::wstring const& actual, std::string const& method,
        int line, std::string const& msg);

    virtual void CheckNotEquals(
        bool expected, bool actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        int64_t expected, int64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        uint64_t expected, uint64_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        int32_t expected, int32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        uint32_t expected, uint32_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        int16_t expected, int16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        uint16_t expected, uint16_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        int8_t expected, int8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(
        uint8_t expected, uint8_t actual, std::string const& method, int line, std::string const& msg);
    virtual void CheckNotEquals(std::string const& expected, std::string const& actual, std::string const& method,
        int line, std::string const& msg);
    virtual void CheckNotEquals(std::wstring const& expected, std::wstring const& actual, std::string const& method,
        int line, std::string const& msg);

protected: // Assertion/Check methods - Boolean
    virtual void AssertFalse(bool testVal, std::string const& method, int line, std::string const& msg);
    virtual void AssertTrue(bool testVal, std::string const& method, int line, std::string const& msg);
    virtual void CheckFalse(bool testVal, std::string const& method, int line, std::string const& msg);
    virtual void CheckTrue(bool testVal, std::string const& method, int line, std::string const& msg);

public:
    TTestGroupBase(std::string const& name);

    TestCallbackList& GetTestCallbackList() override;
    std::string const& GetTestGroupName() const override;
    TTestResults const& Results() const override;
    void Run() override;
};

} // namespace ASWUnitTests

#endif // ASWUnitTests_TestBaseH
