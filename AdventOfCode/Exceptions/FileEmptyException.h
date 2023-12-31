#pragma once

#include <exception>
#include <string>

class FileEmptyException : public std::exception
{
public:
    char const* what() const noexcept override
    {
        return "File Empty";
    }
};

