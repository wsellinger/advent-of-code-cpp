#pragma once

#include <exception>
#include <string>

class FileOpenFailedException : public std::exception
{
public:
    char const* what() const noexcept override
    {
        return "File Open Failed";
    }
};

