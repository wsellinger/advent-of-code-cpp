// AdventOfCodeLibrary.cpp : Defines the functions for the static library.
//

#include "AdventOfCodeLibrary.h"
#include "Year2015/Day01.h"
#include "Year2015/Day02.h"
#include "Year2023/Day01.h"

using std::string;

namespace AdventOfCodeLibrary
{
    namespace Year2015
    {
        namespace Day01
        {
            long PartA(const string& input)
            {
                return Implementation::Year2015::Day01::PartA(input);
            }

            long PartB(const string& input)
            {
                return Implementation::Year2015::Day01::PartB(input);
            }
        }

        namespace Day02
        {
            long PartA(const string& input)
            {
                return Implementation::Year2015::Day02::PartA(input);
            }

            long PartB(const string& input)
            {
                return Implementation::Year2015::Day02::PartB(input);
            }
        }
    }

    namespace Year2023
    {
        namespace Day01
        {
            long PartA(const string& input)
            {
                return Implementation::Year2023::Day01::PartA(input);
            }

            long PartB(const string& input)
            {
                return Implementation::Year2023::Day01::PartB(input);
            }
        }
    }
}
