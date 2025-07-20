/* **************************************************************************
ASWUnitTests_Exception.h
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
#ifndef ASWUnitTests_ExceptionH
#define ASWUnitTests_ExceptionH
//---------------------------------------------------------------------------
#include <exception>
#include <string>
//---------------------------------------------------------------------------

namespace ASWUnitTests
{

/////////////////////////////////////////////////////////////////////////////
// TTestException
/////////////////////////////////////////////////////////////////////////////
class TTestException : public std::exception
{
protected:
    std::string m_Message;

protected:
    TTestException();

public:
    TTestException(std::string const& msg);

    const char* what() const noexcept override;
};


/////////////////////////////////////////////////////////////////////////////
// TExceptExpected
/////////////////////////////////////////////////////////////////////////////
class TExceptExpected : public TTestException
{
public:
    TExceptExpected(std::string const& msg);
};

/////////////////////////////////////////////////////////////////////////////
// TExceptEquals
/////////////////////////////////////////////////////////////////////////////
class TExceptEquals : public TTestException
{
public:
    TExceptEquals(std::string const& msg);
    TExceptEquals(std::string const& method, int line, std::string const& msg);
    TExceptEquals(std::string const& method, int line, std::string const& expected, std::string const& actual,
        std::string const& msg);
};

/////////////////////////////////////////////////////////////////////////////
// TExceptNotEquals
/////////////////////////////////////////////////////////////////////////////
class TExceptNotEquals : public TTestException
{
public:
    TExceptNotEquals(std::string const& msg);
    TExceptNotEquals(std::string const& method, int line, std::string const& msg);
    TExceptNotEquals(std::string const& method, int line, std::string const& value, std::string const& msg);
};

/////////////////////////////////////////////////////////////////////////////
// TExceptFalse
/////////////////////////////////////////////////////////////////////////////
class TExceptFalse : public TTestException
{
public:
    TExceptFalse(std::string const& msg);
    TExceptFalse(std::string const& method, int line, std::string const& msg);
};

/////////////////////////////////////////////////////////////////////////////
// TExceptTrue
/////////////////////////////////////////////////////////////////////////////
class TExceptTrue : public TTestException
{
public:
    TExceptTrue(std::string const& msg);
    TExceptTrue(std::string const& method, int line, std::string const& msg);
};

} // namespace ASWUnitTests

//---------------------------------------------------------------------------
#endif // #ifndef ASWUnitTests_ExceptionH
