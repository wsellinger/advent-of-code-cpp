#include "../Utils/StringUtils.h"
#include "Day01.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

using std::vector;
using std::string;
using std::istream;
using std::exception;

/// <summary>
/// --- Day 1: Trebuchet?! ---
///
/// Something is wrong with global snow production, and you've been selected to take a look. The Elves have even given you a map; on it, 
/// they've used stars to mark the top fifty locations that are likely to be having problems.
/// 
/// You've been doing this long enough to know that to restore snow operations, you need to check all fifty stars by December 25th.
/// 
/// Collect stars by solving puzzles.Two puzzles will be made available on each day in the Advent calendar; the second puzzle is 
/// unlocked when you complete the first.Each puzzle grants one star. Good luck!
/// 
/// You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you ("the sky") and 
/// why your map looks mostly blank("you sure ask a lot of questions") and hang on did you just say the sky("of course, where do you 
/// think snow comes from") when you realize that the Elves are already loading you into a trebuchet ("please hold still, we need to 
/// strap you in").
/// 
/// As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a 
/// very young Elf who was apparently just excited to show off her art skills. Consequently, the Elves are having trouble reading the 
/// values on the document.
/// 
/// The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that 
/// the Elves now need to recover.On each line, the calibration value can be found by combining the first digit and the last digit (in 
/// that order) to form a single two-digit number.
///     For example:
/// 
/// 1abc2
///     pqr3stu8vwx
/// a1b2c3d4e5f
///     treb7uchet
/// 
/// In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.
/// 
/// Consider your entire calibration document.What is the sum of all of the calibration values?
/// 
/// --- Part Two ---
///
///     Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".
/// 
/// Equipped with this new information, you now need to find the real first and last digit on each line.For example:
/// 
/// two1nine
/// eightwothree
/// abcone2threexyz
/// xtwone3four
/// 4nineeightseven2
/// zoneight234
/// 7pqrstsixteen
/// 
/// In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.
/// 
/// What is the sum of all of the calibration values?
/// 
/// </summary>
namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2023
        {
            long Day01::PartA(istream& input)
            {
                return GetCalibrationSum(input, PartASub::GetCalibrationValue);
            }

            long Day01::PartB(istream& input)
            {
                return GetCalibrationSum(input, PartBSub::GetCalibrationValue);
            }

            long Day01::GetCalibrationSum(istream& input, CalibrationMethod GetCalibrationValue)
            {
                vector<int> calibrations;
                string line;

                while (std::getline(input, line))
                {
                    int value = GetCalibrationValue(line);
                    calibrations.push_back(value);
                }

                return accumulate(calibrations.begin(), calibrations.end(), 0);
            }

            int Day01::PartASub::GetCalibrationValue(const string& input)
            {
                char firstDigit = *find_if(input.begin(), input.end(), [](int x) { return isdigit(x); });
                char lastDigit = *find_if(input.rbegin(), input.rend(), [](int x) { return isdigit(x); });

                return ConvertDigitsToInt(firstDigit, lastDigit);
            }

            int Day01::PartBSub::GetCalibrationValue(const string& input)
            {
                char firstDigit = GetFirstDigit(input);
                char lastDigit = GetLastDigit(input);

                return ConvertDigitsToInt(firstDigit, lastDigit);
            }

            char Day01::PartBSub::GetFirstDigit(const string& input)
            {
                for (size_t i = 0; i < input.length(); i++)
                {
                    char digit = '\0';
                    if (GetDigitAtIndex(input, i, digit))
                    {
                        return digit;
                    }
                }

                throw new exception("No Digit Found In Line");
            }

            char Day01::PartBSub::GetLastDigit(const string& input)
            {
                for (size_t ri = input.length(); ri > 0; ri--)
                {
                    size_t i = ri - 1;
                    char digit = '\0';
                    if (GetDigitAtIndex(input, i, digit))
                    {
                        return digit;
                    }
                }

                throw new exception("No Digit Found In Line");
            }

            bool Day01::PartBSub::GetDigitAtIndex(const string& input, size_t index, char& output)
            {
                if (isdigit(input[index]))
                {
                    output = input[index];
                    return true;
                }
                else
                {
                    for (size_t i = 0; i < DIGIT_WORDS.size(); i++)
                    {
                        string word = DIGIT_WORDS[i];
                        if (index + word.length() <= input.length())
                        {
                            if (word == input.substr(index, word.length()))
                            {
                                output = (char)(i + 1 + '0');
                                return true;
                            }
                        }
                    }
                }

                output = '\0';
                return false;
            }

            int Day01::ConvertDigitsToInt(char firstDigit, char lastDigit)
            {
                char digits[] = { firstDigit, lastDigit };
                return atoi(digits);
            }

            const vector<string> Day01::DIGIT_WORDS = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        }
    }
}