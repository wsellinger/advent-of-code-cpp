#include "FileUtils.h"
#include <fstream>
#include "../Exceptions/FileOpenFailedException.h"
#include "../Exceptions/FileEmptyException.h"

using std::string;
using std::ifstream;
using std::exception;

namespace AdventOfCode
{
    namespace FileUtils
    {
        void GetFileFirstLine(const string& name, string& output)
        {
            ifstream file(name);
            if (!file.is_open())
                throw new FileOpenFailedException();

            if (!std::getline(file, output))
                throw new FileEmptyException();
        }

        void GetFileStream(const std::string& name, std::ifstream& output)
        {
            output.open(name);
            if (!output.is_open())
                throw new FileOpenFailedException();
        }
    }
}

