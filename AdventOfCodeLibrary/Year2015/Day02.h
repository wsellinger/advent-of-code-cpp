#pragma once
#include <string>
#include <vector>

namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2015
        {
            class Day02
            {
            public:
                static long PartA(const std::string& input);
                static long PartB(const std::string& input);

            private:
                static const std::string NEWLINE;

                struct Box
                {
                    const long Length = 0;
                    const long Width = 0;
                    const long Height = 0;

                    static Box GetBoxFromInput(std::string input);

                    long GetAreaLengthWidth() const { return Length * Width; }
                    long GetAreaWidthHeight() const { return Width * Height; }
                    long GetAreaHeightLength() const { return Height * Length; }
                    long GetVolume() const { return Length * Width * Height; }

                    long GetSurfaceArea() const;
                    long GetSmallestSideArea() const;

                    long GetShortestPerimeter() const;
                };

                static std::vector<Box> GetBoxVector(std::string input);
                static std::string SanitizeInput(std::string input);
            };
        }
    }
}