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
            namespace Day01
            {
                void PartA()
                {
                    string input;
                    AocUtils::GetSingleLineInput(2015, 1, input);
                    long result = AdventOfCodeLibrary::Year2015::Day01::PartA(input);
                    AocUtils::LogOutput(result);
                }

                void PartB()
                {
                    string input;
                    AocUtils::GetSingleLineInput(2015, 1, input);
                    long result = AdventOfCodeLibrary::Year2015::Day01::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }

            namespace Day02
            {
                void PartA()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(2015, 2, input);
                    long result = AdventOfCodeLibrary::Year2015::Day02::PartA(input);
                    AocUtils::LogOutput(result);
                }
                void PartB()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(2015, 2, input);
                    long result = AdventOfCodeLibrary::Year2015::Day02::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }
        }

        namespace Year2023
        {
            namespace Day01
            {
                void PartA()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(2023, 1, input);
                    long result = AdventOfCodeLibrary::Year2023::Day01::PartA(input);
                    AocUtils::LogOutput(result);
                }
                void PartB()
                {
                    ifstream input;
                    AocUtils::GetFileStreamInput(2023, 1, input);
                    long result = AdventOfCodeLibrary::Year2023::Day01::PartB(input);
                    AocUtils::LogOutput(result);
                }
            }
        }
    }
}