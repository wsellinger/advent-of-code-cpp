#pragma once
#include <string>
#include <vector>

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
                using CalibrationMethod = int (*)(const std::string&);

                class PartASub
                {
                public:
                    static int GetCalibrationValue(const std::string& input);
                };

                class PartBSub
                {
                public:
                    static int GetCalibrationValue(const std::string& input);
                private:
                    static char GetFirstDigit(const std::string& input);
                    static char GetLastDigit(const std::string& input);
                    static bool GetDigitAtIndex(const std::string& input, size_t index, char& output);
                };

                static long GetCalibrationSum(const std::string& input, CalibrationMethod method);
                static int ConvertDigitsToInt(char firstDigit, char lastDigit);

                static const std::vector<std::string> DIGIT_WORDS;
            };
        }
    }
}