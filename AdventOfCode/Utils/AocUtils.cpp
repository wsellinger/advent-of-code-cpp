#include "AocUtils.h"
#include "FileUtils.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using std::string;
using std::ifstream;
using std::stringstream;

namespace AdventOfCode
{
    void AocUtils::GetSingleLineInput(int year, int day, string& output)
    {
        string name;
        GetFileName(year, day, name);
        FileUtils::GetFileFirstLine(name, output);
    }

    void AocUtils::GetFileStreamInput(int year, int day, ifstream& output)
    {
        string name;
        GetFileName(year, day, name);
        FileUtils::GetFileStream(name, output);
    }

    void AocUtils::LogOutput(long input)
    {
        std::cout << std::to_string(input) << std::endl;
    }

    void AocUtils::GetFileName(int year, int day, string& output)
    {
        stringstream stream;
        stream << "Input/Year_" << year << "__Day_" << std::setw(2) << std::setfill('0') << day << ".txt";
        output = stream.str();
    }
}

