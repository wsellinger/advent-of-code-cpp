#pragma once

#include <exception>
#include <string>

class NotImplementedException : public std::exception
{
public:
    char const* what() const noexcept override
    {
        return "Not Implemented";
    }
};

