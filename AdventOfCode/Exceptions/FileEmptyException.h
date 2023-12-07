#pragma once

#include <exception>
#include <string>

class FileEmptyException : public std::exception
{
public:
    char const* what() const noexcept override;

private:
    std::string m_message = "File Empty";
};

