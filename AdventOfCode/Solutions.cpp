#include "Solutions.h"
#include "Utils/AocUtils.h"
#include <AdventOfCodeLibrary.h>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;

namespace AdventOfCode
{
    namespace Solutions
    {
        namespace Year2015
        {
            const int YEAR = 2015;

            namespace Day01
            {
                const int DAY = 1;

                void PartA()
                {
                    string input;
                    AocUtils::GetSingleLineInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2015::Day01::PartA(input);
                    AocUtils::LogOutput(result);
                }

                void PartB()
                {
                    string input;
                    AocUtils::GetSingleLineInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2015::Day01::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }

            namespace Day02
            {
                const int DAY = 2;

                void PartA()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2015::Day02::PartA(input);
                    AocUtils::LogOutput(result);
                }
                void PartB()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2015::Day02::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }
        }

        namespace Year2023
        {
            const int YEAR = 2023;

            namespace Day01
            {
                const int DAY = 1;

                void PartA()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2023::Day01::PartA(input);
                    AocUtils::LogOutput(result);
                }
                void PartB()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2023::Day01::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }

            namespace Day02
            {
                const int DAY = 2;

                void PartA()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2023::Day02::PartA(input);
                    AocUtils::LogOutput(result);
                }
                void PartB()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2023::Day02::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }


            namespace Day03
            {
                const int DAY = 3;

                void PartA()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2023::Day03::PartA(input);
                    AocUtils::LogOutput(result);
                }
                void PartB()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(YEAR, DAY, input);
                    long result = AdventOfCodeLibrary::Year2023::Day03::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }
        }
    }
}