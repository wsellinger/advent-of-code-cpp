#include "StringUtils.h"
#include <sstream>
#include "StringUtils.h"
#include <algorithm>
#include <functional>

using std::string;
using std::string_view;
using std::vector;
using std::stringstream;

namespace AdventOfCodeLibrary
{
    namespace StringUtils
    {
        vector<string_view> Split(const string_view& input, const char delimiter)
        {
            string_view operableInput = input;
            vector<string_view> result;

            while (!operableInput.empty())
            {
                size_t iDelimiter = operableInput.find(delimiter);
                string_view substring = operableInput.substr(0, iDelimiter);
                result.push_back(substring);
                
                if (iDelimiter == string_view::npos)
                    break;

                operableInput.remove_prefix(iDelimiter + 1);
            }

            return result;
        }

        vector<string_view> Split(const string_view& input, const string_view& delimiter)
        {
            string_view operableInput = input;
            vector<string_view> result;

            while (!operableInput.empty())
            {
                size_t iDelimiter = operableInput.find(delimiter);
                string_view substring = operableInput.substr(0, iDelimiter);
                result.push_back(substring);

                if (iDelimiter == string_view::npos)
                    break;

                operableInput.remove_prefix(iDelimiter + delimiter.length());
            }

            return result;
        }

        string_view Trim(const string_view& input)
        {
            auto isNotSpaceLambda = [](unsigned char ch) { return std::isspace(ch); };
            auto firstIterator = std::find_if_not(input.begin(), input.end(), isNotSpaceLambda);
            auto lastIterator = std::find_if_not(input.rbegin(), input.rend(), isNotSpaceLambda);
            size_t iStart = std::distance(input.begin(), firstIterator);
            size_t length = std::distance(input.begin(), lastIterator.base()) - iStart;

            return input.substr(iStart, length);
        }

        string ToUpper(const string_view& input)
        {
            string result;
            result.reserve(input.length());

            for (unsigned char c : input)
                result += std::toupper(c);

            return result;
        }

        string ToLower(const string_view& input)
        {
            string result;
            result.reserve(input.length());

            for (unsigned char c : input)
                result += std::tolower(c);

            return result;
        }

        string& ToUpperInPlace(string& input)
        {
            std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return  std::toupper(c); });
            return input;
        }

        string& ToLowerInPlace(string& input)
        {
            std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return  std::tolower(c); });
            return input;
        }

    }
}
