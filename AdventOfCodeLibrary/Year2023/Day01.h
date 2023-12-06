#pragma once
#include <string>

namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2023
        {
            class Day01
            {
            public:
                static long PartA(const std::string& input);
                static long PartB(const std::string& input);
            private:
                static int ConvertDigitsToInt(char firstDigit, char lastDigit);

                class PartASub
                {
                public:
                    static int GetCalibrationValue(std::string input);
                };
            };
        }
    }
}