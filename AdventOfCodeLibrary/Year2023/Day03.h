#pragma once

#include <iostream>
#include <string>
#include "../Models/Range.h"

namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2023
        {
            class Day03
            {
            public:
                static long PartA(std::istream& input);
                static long PartB(std::istream& input);

            private:
                class LineSet
                {
                public:
                    LineSet(std::istream& input) : 
                        m_Stream(input), m_previous(""), m_current("")
                    {
                        std::getline(m_Stream, m_next);
                    }

                    bool Advance();
                
                protected:
                    std::string_view Previous() const { return m_previous; }
                    std::string_view Current() const { return m_current; }
                    std::string_view Next() const { return m_next; }

                private:
                    std::istream& m_Stream;

                    std::string m_previous = "";
                    std::string m_current = "";
                    std::string m_next = "";
                };

                class SchematicParser : public LineSet
                {
                public:
                    SchematicParser(std::istream& input) :
                        LineSet(input), m_index(0) {}

                    bool GetNextPartNumber(int& output); 
                    bool GetNextGearRatio(int& output);

                private:
                    static const char EMPTY = '.';
                    static const char GEAR = '*';

                    size_t m_index = 0;

                    //Part Number Helpers
                    bool GetNextNumberRange(Range& output);
                    bool ValidateNumberRange(const Range& range) const;

                    static bool IsValid(size_t i, std::string_view s);
                    static bool IsSymbol(char ch);

                    //Gear Ratio Helpers
                    bool GetNextGearIndex(size_t& output);
                    bool GetGearRatio(size_t iGear, int& output);
                    static int GetPartNumber(size_t i, std::string_view s);
                    static int GetPartNumberAndUpdateIndex(size_t& i, std::string_view s);
                    static bool IsDigit(size_t i, std::string_view s);
                };
            };

        }
    }
}