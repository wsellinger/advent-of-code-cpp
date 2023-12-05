#include "StringUtils.h"
#include <sstream>
#include "StringUtils.h"

using std::string;
using std::vector;
using std::stringstream;

namespace AdventOfCodeLibrary
{
    namespace StringUtils
    {
        vector<string> Split(const string& input, const char delimiter)
        {
            return Split(input, delimiter, false);
        }

        vector<string> Split(const string& input, const char delimiter, bool trimTrailing)
        {
            vector<string> result;
            stringstream stream(input);
            string token;

            while (std::getline(stream, token, delimiter))
            {
                bool isFinalToken = stream.tellg() == stream.tellp();
                if (!trimTrailing || !isFinalToken || !token.empty())
                {
                    result.push_back(token);
                }
            }

            return result;
        }

        vector<string> Split(const string& input, const string& delimiter)
        {
            return Split(input, delimiter, false);
        }

        vector<string> Split(const string& input, const string& delimiter, bool trimTrailing)
        {
            vector<string> result;
            size_t start = 0, end = 0;

            while ((end = input.find(delimiter, start)) != string::npos)
            {
                size_t count = end - start;
                string token = input.substr(start, count);
                result.push_back(token);
                start = end + delimiter.length();
            }

            string finalToken = input.substr(start);
            if (!trimTrailing || !finalToken.empty())
            {
                result.push_back(finalToken);
            }

            return result;
        }

        vector<string> SplitOnNewLine(const string& input)
        {
            return SplitOnNewLine(input, false);
        }

        vector<string> SplitOnNewLine(const string& input, bool trimTrailing)
        {
            std::ostringstream oss;
            oss << std::endl;
            return Split(input, oss.str(), trimTrailing);
        }
    }
}
