#pragma once
#include <string>

namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2015
        {
            class Day01
            {
            public:
                static long PartA(const std::string& input);
                static long PartB(const std::string& input);
            private:
                static long UpdateFloor(char input, long result);
            };
        }
    }
}