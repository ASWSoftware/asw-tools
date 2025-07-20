/* **************************************************************************
ASWUnitTests_Exception.cpp
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
#include "ASWUnitTests_Exception.h"
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestException
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TTestException::TTestException()
{
}
//---------------------------------------------------------------------------
TTestException::TTestException(std::string const& msg)
    : m_Message(msg)
{
}
//---------------------------------------------------------------------------
const char* TTestException::what() const noexcept
{
    return m_Message.c_str();
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
// TExceptExpected
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TExceptExpected::TExceptExpected(std::string const& msg)
{
    m_Message = "Exception expected: " + msg;
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
// TExceptEquals
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TExceptEquals::TExceptEquals(std::string const& msg)
{
    m_Message = "Values not equal: " + msg;
}
//---------------------------------------------------------------------------
TExceptEquals::TExceptEquals(std::string const& method, int line, std::string const& msg)
{
    m_Message = "Values not equal: " + method + " (" + std::to_string(line) + "): " + msg;
}
//---------------------------------------------------------------------------
TExceptEquals::TExceptEquals(
    std::string const& method, int line, std::string const& expected, std::string const& actual, std::string const& msg)
{
    m_Message = "Values not equal: " + method + " (" + std::to_string(line) + "): Expected: \"" + expected +
        "\" but was \"" + actual + "\". " + msg;
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
// TExceptFalse
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TExceptFalse::TExceptFalse(std::string const& msg)
{
    m_Message = "Expected false but was true: " + msg;
}
//---------------------------------------------------------------------------
TExceptFalse::TExceptFalse(std::string const& method, int line, std::string const& msg)
{
    m_Message = "Expected false but was true: " + method + " (" + std::to_string(line) + "): " + msg;
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
// TExceptNotEquals
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TExceptNotEquals::TExceptNotEquals(std::string const& msg)
{
    m_Message = "Values are equal: " + msg;
}
//---------------------------------------------------------------------------
TExceptNotEquals::TExceptNotEquals(std::string const& method, int line, std::string const& msg)
{
    m_Message = "Values are equal: " + method + " (" + std::to_string(line) + "): " + msg;
}
//---------------------------------------------------------------------------
TExceptNotEquals::TExceptNotEquals(
    std::string const& method, int line, std::string const& value, std::string const& msg)
{
    m_Message = "Values are equal: " + method + " (" + std::to_string(line) + "): Value: \"" + value + "\". " + msg;
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
// TExceptTrue
/////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
TExceptTrue::TExceptTrue(std::string const& msg)
{
    m_Message = "Expected true but was false: \"" + msg + "\"";
}
//---------------------------------------------------------------------------
TExceptTrue::TExceptTrue(std::string const& method, int line, std::string const& msg)
{
    m_Message = "Expected true but was false: " + method + " (" + std::to_string(line) + "): " + msg;
}
//---------------------------------------------------------------------------

} // namespace ASWUnitTests
