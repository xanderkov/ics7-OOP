#pragma once
#include <exception>
#include <string>

using string = std::string;


class ExceptionMatrix: public std::exception 
{
protected:
    string _errmsg;
public:
    ExceptionMatrix(const string time_info, const string file_info, string class_name,  const int line_info, 
                    const string errmsg = "No error message");
    virtual ~ExceptionMatrix() {};
    virtual const char *what() const noexcept override 
    {
        return _errmsg.c_str();
    };
};


class IndexError: public ExceptionMatrix
{
public:
    IndexError(const string time_info, const string file_info, string class_name, const int line_info, 
               const string errmsg = "No error message"):
               ExceptionMatrix(time_info, file_info, class_name, line_info, errmsg) 
    {
        _errmsg += " (error type: Index Error)";
    }
};


class MemoryError: public ExceptionMatrix 
{
public:
    MemoryError(const string time_info, const string file_info, string class_name, const int line_info, 
               const string errmsg = "No error message"):
               ExceptionMatrix(time_info, file_info, class_name, line_info, errmsg) 
    {
        _errmsg += " (error type: Memory Error)";
    }
};

class InvalidArgument: public ExceptionMatrix 
{
public:
    InvalidArgument(const string time_info, const string file_info, string class_name, const int line_info, 
               const string errmsg = "No error message"):
               ExceptionMatrix(time_info, file_info, class_name, line_info, errmsg) 
    {
        _errmsg += " (error type: Invalid Argument)";
    }
};

class IncompatibleElements: public ExceptionMatrix 
{
public:
    IncompatibleElements(const string time_info, const string file_info, string class_name, const int line_info, 
               const string errmsg = "No error message"):
               ExceptionMatrix(time_info, file_info, class_name, line_info, errmsg) 
    {
        _errmsg += " (error type: Incompatible Elements)";
    }
};

class InvalidState: public ExceptionMatrix 
{
public:
    InvalidState(const string time_info, const string file_info, string class_name, const int line_info, 
               const string errmsg = "No error message"):
               ExceptionMatrix(time_info, file_info, class_name, line_info, errmsg) 
    {
        _errmsg += " (error type: Invalid State)";
    }
};

class IteratorIndexError: public ExceptionMatrix
{
public:
    IteratorIndexError(const string time_info, const string file_info, string class_name, const int line_info, 
               const string errmsg = "No error message"):
               ExceptionMatrix(time_info, file_info, class_name, line_info, errmsg) 
    {
        _errmsg += " (error type: Iterator Index Error)";
    }
};

class IteratorValidationError: public ExceptionMatrix
{
public:
    IteratorValidationError(const string time_info, const string file_info, string class_name, const int line_info,
                            const string errmsg = "No error message"):
        ExceptionMatrix(time_info, file_info, class_name, line_info, errmsg)
        {
            _errmsg += " (error type: Iterator Validation Error)";
        }
};



#include "../implementation/exception.hpp"
