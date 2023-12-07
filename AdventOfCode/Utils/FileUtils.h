#pragma once
#include <string>
#include <fstream>

namespace AdventOfCode
{
    namespace FileUtils
    {
        void GetFileFirstLine(const std::string& name, std::string& output);
        void GetFileStream(const std::string& name, std::ifstream& output);
    }
}