#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>

namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2023
        {
            class Day02
            {
            public:
                static long PartA(std::istream& input);
                static long PartB(std::istream& input);

            private:
                enum class CubeColor { None, Red, Green, Blue };

                struct CubeResult
                {
                public:
                    const CubeColor Color = CubeColor::None;
                    const int Amount = 0;

                    static CubeResult GetCubeResult(const std::string_view& input);

                private:
                    static const std::map<std::string, CubeColor> m_colorMap;
                    static CubeColor GetCubeColor(const std::string_view& input);
                };

                using GameResults = std::vector<std::vector<CubeResult>>;

                struct GameRecord
                {
                public:
                    const int Id = 0;
                    const GameResults Results;

                    static GameRecord GetGameRecord(const std::string_view& input);

                private:
                    static GameResults GetResultRecords(const std::string_view& input);
                };

                static std::vector<GameRecord> GetGameRecords(std::istream& input);
            };
        }
    }
}