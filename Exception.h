#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object.h"

namespace DataLib
{

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

class Exception : public Object
{
protected:
    char* m_message;
    char* m_location;

    void init(const char* message, const char* file, int line);

public:
    Exception(const char* message);
    Exception(const char* file, int len);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& e);
    Exception& operator = (const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0;
};

class ArithmeticException : public Exception
{
public:
    ArithmeticException() : Exception(0) { }
    ArithmeticException(const char* message) : Exception(message) { }
    ArithmeticException(const char* file, int len) : Exception(file, len) { }
    ArithmeticException(const char* message, const char* file, int len) : Exception(message, file, len) { }

    ArithmeticException(const ArithmeticException& e) : Exception(e) { }
    ArithmeticException& operator = (const ArithmeticException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class NullPointerException : public Exception
{
public:
    NullPointerException() : Exception(0) { }
    NullPointerException(const char* message) : Exception(message) { }
    NullPointerException(const char* file, int len) : Exception(file, len) { }
    NullPointerException(const char* message, const char* file, int len) : Exception(message, file, len) { }

    NullPointerException(const NullPointerException& e) : Exception(e) { }
    NullPointerException& operator = (const NullPointerException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() : Exception(0) { }
    IndexOutOfBoundsException(const char* message) : Exception(message) { }
    IndexOutOfBoundsException(const char* file, int len) : Exception(file, len) { }
    IndexOutOfBoundsException(const char* message, const char* file, int len) : Exception(message, file, len) { }

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e) { }
    IndexOutOfBoundsException& operator = (const IndexOutOfBoundsException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(0) { }
    NoEnoughMemoryException(const char* message) : Exception(message) { }
    NoEnoughMemoryException(const char* file, int len) : Exception(file, len) { }
    NoEnoughMemoryException(const char* message, const char* file, int len) : Exception(message, file, len) { }

    NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e) { }
    NoEnoughMemoryException& operator = (const NoEnoughMemoryException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() : Exception(0) { }
    InvalidParameterException(const char* message) : Exception(message) { }
    InvalidParameterException(const char* file, int len) : Exception(file, len) { }
    InvalidParameterException(const char* message, const char* file, int len) : Exception(message, file, len) { }

    InvalidParameterException(const InvalidParameterException& e) : Exception(e) { }
    InvalidParameterException& operator = (const InvalidParameterException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class InvalidOpeartorException : public Exception
{
public:
    InvalidOpeartorException() : Exception(0) { }
    InvalidOpeartorException(const char* message) : Exception(message) { }
    InvalidOpeartorException(const char* file, int len) : Exception(file, len) { }
    InvalidOpeartorException(const char* message, const char* file, int len) : Exception(message, file, len) { }

    InvalidOpeartorException(const InvalidOpeartorException& e) : Exception(e) { }
    InvalidOpeartorException& operator = (const InvalidOpeartorException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

}


#endif // EXCEPTION_H
