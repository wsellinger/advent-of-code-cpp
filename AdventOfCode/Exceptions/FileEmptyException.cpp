#include "FileEmptyException.h"

char const* FileEmptyException::what() const noexcept
{
    return m_message.c_str();
}
