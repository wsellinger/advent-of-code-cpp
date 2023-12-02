#include "StringUtilities.h"
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

namespace AdventOfCodeLibrary
{
    namespace StringUtilities
    {
        vector<string> Split(const string& input, const char delimiter)
        {
            vector<string> result;
            stringstream stream(input);
            string token;

            while (std::getline(stream, token, delimiter))
            {
                result.push_back(token);
            }

            return result;
        }

        vector<string> Split(const string& input, const string& delimiter)
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
            result.push_back(finalToken);

            return result;
        }

    }
}
