#include "..\IO_Fixture.h"
#include "..\pch.h"
#include <AdventOfCodeLibrary.h>
#include <sstream>

namespace Year_2023
{
    namespace Day_02
    {
        namespace Day02 = AdventOfCodeLibrary::Year2023::Day02;

        using testing::TestWithParam;
        using std::tuple;
        using std::string;
        using std::stringstream;


#pragma region PartA
        class IO_Fixture_2302A : public IO_Fixture {};

        TEST_P(IO_Fixture_2302A, PartA_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            stringstream stream(input);
            long actual = Day02::PartA(stream);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartA_Suite, IO_Fixture_2302A,
            testing::Values(
                std::make_tuple("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green", 1),
                std::make_tuple("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue", 2),
                std::make_tuple("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red", 0),
                std::make_tuple("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red", 0),
                std::make_tuple("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", 5),
                std::make_tuple(
                    "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\r\n"
                    "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red", 2),
                std::make_tuple(
                    "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\r\n"
                    "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\r\n"
                    "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\r\n"
                    "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\r\n"
                    "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", 8)
            ));
#pragma endregion

#pragma region PartB
        class IO_Fixture_2302B : public IO_Fixture {};

        TEST_P(IO_Fixture_2302B, PartB_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            stringstream stream(input);
            long actual = Day02::PartB(stream);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartB_Suite, IO_Fixture_2302B,
            testing::Values(
                std::make_tuple("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green", 48),
                std::make_tuple("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue", 12),
                std::make_tuple("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red", 1560),
                std::make_tuple("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red", 630),
                std::make_tuple("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", 36),
                std::make_tuple(
                    "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\r\n"
                    "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red", 1572),
                std::make_tuple(
                    "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\r\n"
                    "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\r\n"
                    "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\r\n"
                    "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\r\n"
                    "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", 2286)
            ));
#pragma endregion
    }
}