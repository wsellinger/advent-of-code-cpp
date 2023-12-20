#pragma once

#include <vector>
#include <string>

namespace AdventOfCodeLibrary
{
    namespace StringUtils
    {
        std::vector<std::string_view> Split(std::string_view input, const char delimiter);
        std::vector<std::string_view> Split(std::string_view input, std::string_view delimiter);

        std::string_view Trim(std::string_view input);

        std::string ToUpper(std::string_view input);
        std::string ToLower(std::string_view input);

        std::string& ToUpperInPlace(std::string& input);
        std::string& ToLowerInPlace(std::string& input);
    }
}