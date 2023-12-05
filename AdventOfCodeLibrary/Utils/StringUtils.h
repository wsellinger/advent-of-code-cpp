#pragma once

#include <vector>
#include <string>

namespace AdventOfCodeLibrary
{
    namespace StringUtils
    {
        std::vector<std::string> Split(const std::string& input, const char delimiter);
        std::vector<std::string> Split(const std::string& input, const char delimiter, bool trimTrailing);

        std::vector<std::string> Split(const std::string& input, const std::string& delimiter);
        std::vector<std::string> Split(const std::string& input, const std::string& delimiter, bool trimTrailing);

        std::vector<std::string> SplitOnNewLine(const std::string& input);
        std::vector<std::string> SplitOnNewLine(const std::string& input, bool trimTrailing);
    }
}