#pragma once

#include "includes.hpp"

class Exception : public std::exception
{
public:
    explicit Exception(const char *message) : message(message) {}
    explicit Exception(const std::string &message) : message(message) {}
    virtual ~Exception() throw() {}

    virtual const char *what() const throw() { return this->message.c_str(); }

protected:
    std::string message;
};