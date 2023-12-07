#include "FileOpenFailedException.h"

char const* FileOpenFailedException::what() const noexcept
{
    return m_message.c_str();
}
