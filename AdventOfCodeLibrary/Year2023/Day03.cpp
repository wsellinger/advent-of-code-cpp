#include "Day03.h"
#include "../Exceptions/NotImplementedException.h"
#include <vector>
#include <numeric>
#include <string>

using std::vector;
using std::string;
using std::string_view;

/// <summary>
/// --- Day 3: Gear Ratios ---
///
///    You and the Elf eventually reach a gondola lift station; he says the gondola lift will take you up to the water source, but this 
///    is as far as he can bring you. You go inside.
///    
///    It doesn't take long to find the gondolas, but there seems to be a problem: they're not moving.
///    
///    "Aaah!"
///
///    You turn around to see a slightly-greasy Elf with a wrench and a look of surprise. "Sorry, I wasn't expecting anyone! The 
///    gondola lift isn't working right now; it'll still be a while before I can fix it." You offer to help.
///
///    The engineer explains that an engine part seems to be missing from the engine, but nobody can figure out which one. If you can 
///    add up all the part numbers in the engine schematic, it should be easy to work out which part is missing.
///
///    The engine schematic (your puzzle input) consists of a visual representation of the engine. There are lots of numbers and 
///    symbols you don't really understand, but apparently any number adjacent to a symbol, even diagonally, is a "part number" and 
///    should be included in your sum. (Periods (.) do not count as a symbol.)
///
///    Here is an example engine schematic:
///
///    467..114..
///    ...*......
///    ..35..633.
///    ......#...
///    617*......
///    .....+.58.
///    ..592.....
///    ......755.
///    ...$.*....
///    .664.598..
///
///    In this schematic, two numbers are not part numbers because they are not adjacent to a symbol: 114 (top right) and 58 (middle 
///    right). Every other number is adjacent to a symbol and so is a part number; their sum is 4361.
///    
///    Of course, the actual engine schematic is much larger. What is the sum of all of the part numbers in the engine schematic?
///    
///    --- Part Two ---
///    
///    The engineer finds the missing part and installs it in the engine! As the engine springs to life, you jump in the closest 
///    gondola, finally ready to ascend to the water source.
///    
///    You don't seem to be going very fast, though. Maybe something is still wrong? Fortunately, the gondola has a phone labeled 
///    "help", so you pick it up and the engineer answers.
///    
///    Before you can explain the situation, she suggests that you look out the window. There stands the engineer, holding a phone in 
///    one hand and waving with the other. You're going so slowly that you haven't even left the station. You exit the gondola.
///    
///    The missing part wasn't the only issue - one of the gears in the engine is wrong. A gear is any * symbol that is adjacent to 
///    exactly two part numbers. Its gear ratio is the result of multiplying those two numbers together.
///    
///    This time, you need to find the gear ratio of every gear and add them all up so that the engineer can figure out which gear 
///    needs to be replaced.
///    
///    Consider the same engine schematic again:
///
///    467..114..
///    ...*......
///    ..35..633.
///    ......#...
///    617*......
///    .....+.58.
///    ..592.....
///    ......755.
///    ...$.*....
///    .664.598..
/// 
///    In this schematic, there are two gears. The first is in the top left; it has part numbers 467 and 35, so its gear ratio is 
///    16345.The second gear is in the lower right; its gear ratio is 451490. (The * adjacent to 617 is not a gear because it is only 
///    adjacent to one part number.) Adding up all of the gear ratios produces 467835.
///
///    What is the sum of all of the gear ratios in your engine schematic ?
///
/// </summary>
namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2023
        {
            long Day03::PartA(std::istream& input)
            {
                vector<int> partNumbers;
                SchematicParser parser(input);
                while (parser.Advance())
                {
                    int partNumber = 0;
                    while (parser.GetNextPartNumber(partNumber))
                    {
                        partNumbers.push_back(partNumber);
                    }
                }

                return std::accumulate(partNumbers.begin(), partNumbers.end(), 0);
            }

            long Day03::PartB(std::istream& input)
            {
                vector<int> gearRatios;
                SchematicParser parser(input);
                while (parser.Advance())
                {
                    int gearRatio = 0;
                    while (parser.GetNextGearRatio(gearRatio))
                    {
                        gearRatios.push_back(gearRatio);
                    }
                }

                return std::accumulate(gearRatios.begin(), gearRatios.end(), 0);
            }

            //Private Classes

            bool Day03::LineSet::Advance()
            {
                m_previous = std::move(m_current);
                m_current = std::move(m_next);

                if (!std::getline(m_Stream, m_next))
                    m_next = "";

                return !m_current.empty();
            }

            bool Day03::SchematicParser::GetNextPartNumber(int& output)
            {
                output = 0;

                if (Current().empty())
                    return false;

                Range range;
                while (GetNextNumberRange(range))
                {
                    if (ValidateNumberRange(range))
                    {
                        string_view partNumber = Current().substr(range.Start, range.Count());
                        output = atoi(partNumber.data());
                        return true;
                    }
                }

                return false;
            }

            bool Day03::SchematicParser::GetNextGearRatio(int& output)
            {
                output = 0;

                if (Current().empty())
                    return false;
                
                size_t iGear = 0;
                while (GetNextGearIndex(iGear))
                    if (GetGearRatio(iGear, output))
                        return true;

                return false;
            }

            //Private Class Methods

            //Part Number Helpers
            bool Day03::SchematicParser::GetNextNumberRange(Range& output)
            {
                size_t iStart = 0;
                bool isStarted = false;
                for (; m_index < Current().length(); m_index++)
                {
                    if (isdigit(Current()[m_index])) //start of digits
                    {
                        if (!isStarted)
                        {
                            iStart = m_index;
                            isStarted = true;
                        }
                    }
                    else if (isStarted) //end of digits
                    {
                        output = { iStart, m_index };
                        return true;
                    }
                }

                if (isStarted) //number at end of line
                {
                    output = { iStart, m_index };
                    return true;
                }

                m_index = 0;
                output = { 0, 0 };
                return false;
            }

            bool Day03::SchematicParser::ValidateNumberRange(const Range& range) const
            {
                size_t iStart = range.Start > 0 ? range.Start - 1 : 0;
                if (IsValid(iStart, Current()))
                    return true;

                size_t iEnd = range.End;
                if (IsValid(iEnd, Current()))
                    return true;

                for (size_t i = iStart; i <= iEnd; i++)
                    if (IsValid(i, Previous()) || IsValid(i, Next()))
                        return true;

                return false;
            }

            bool Day03::SchematicParser::IsValid(size_t i, string_view s)
            {
                return i < s.length() && IsSymbol(s[i]);
            }

            bool Day03::SchematicParser::IsSymbol(char ch)
            {
                return ch != EMPTY && !isdigit(ch);
            }

            //Gear Ratio Helpers

            bool Day03::SchematicParser::GetNextGearIndex(size_t& output)
            {
                for (; m_index < Current().length(); ++m_index)
                {
                    if (Current()[m_index] == GEAR)
                    {
                        output = m_index++; //increment index post assignment to start after it next time
                        return true;
                    }
                }

                m_index = 0;
                output = 0;

                return false;
            }

            bool Day03::SchematicParser::GetGearRatio(size_t iGear, int& output)
            {
                vector<int> partNumbers;
                output = 0;

                size_t iStart = iGear > 0 ? iGear - 1 : 0;
                if (IsDigit(iStart, Current()))
                    partNumbers.push_back(GetPartNumber(iStart, Current()));

                size_t iEnd = iGear + 1;
                if (IsDigit(iEnd, Current()))
                    partNumbers.push_back(GetPartNumber(iEnd, Current()));

                for (size_t i = iStart; i <= iEnd && partNumbers.size() < 2; i++)
                    if (IsDigit(i, Previous()))
                        partNumbers.push_back(
                            GetPartNumberAndUpdateIndex(i, Previous()));

                for (size_t i = iStart; i <= iEnd && partNumbers.size() < 2; i++)
                    if (IsDigit(i, Next()))
                        partNumbers.push_back(
                            GetPartNumberAndUpdateIndex(i, Next()));

                if (partNumbers.size() < 2)
                    return false;

                //Multiply
                output = std::accumulate(partNumbers.begin(), partNumbers.end(), 1,
                    [](int acc, int x) { return acc * x; });

                return true;
            }

            int Day03::SchematicParser::GetPartNumber(size_t i, string_view s)
            {
                return GetPartNumberAndUpdateIndex(i, s);
            }

            int Day03::SchematicParser::GetPartNumberAndUpdateIndex(size_t& i, string_view s)
            {
                auto riStart = s.rend() - i;
                size_t iLeft = std::find_if(riStart, s.rend(), [](size_t x) { return !isdigit(x); }).base() - s.begin();

                auto iStart = s.begin() + i;
                size_t iRight = std::find_if(iStart, s.end(), [](size_t x) { return !isdigit(x); }) - s.begin();
                size_t count = iRight - iLeft;

                i = iRight;

                return atoi(s.substr(iLeft, count).data());
            }

            bool Day03::SchematicParser::IsDigit(size_t i, string_view s)
            {
                return i < s.length() && isdigit(s[i]);
            }

            //General Helpers
        }
    }
}

