#pragma once

#include <exception>
#include <string>

class InvalidInputException : public std::exception
{
public:
    char const* what() const noexcept override
    {
        return "Invalid Input";
    }
};

