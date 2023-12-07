#pragma once

#include <string>

namespace AdventOfCode
{
    class AocUtils
    {
    public:
        static void GetSingleLineInput(int year, int day, std::string& output);
        static void GetFileStreamInput(int year, int day, std::ifstream& output);
        static void LogOutput(long input);

    private:
        static void GetFileName(int year, int day, std::string& output);
    };
}

