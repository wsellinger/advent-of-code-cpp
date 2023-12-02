#pragma once

#include <vector>
#include <string>

namespace AdventOfCodeLibrary
{
    namespace StringUtilities
    {
        std::vector<std::string> Split(const std::string& input, const char delimiter);
        std::vector<std::string> Split(const std::string& input, const std::string& delimiter);
    }
}