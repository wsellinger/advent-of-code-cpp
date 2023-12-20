#include "..\IO_Fixture.h"
#include "..\pch.h"
#include <AdventOfCodeLibrary.h>
#include <sstream>

namespace Year_2023
{
    namespace Day_03
    {
        namespace Day03 = AdventOfCodeLibrary::Year2023::Day03;

        using testing::TestWithParam;
        using std::tuple;
        using std::string;
        using std::stringstream;


#pragma region PartA
        class IO_Fixture_2303A : public IO_Fixture {};

        TEST_P(IO_Fixture_2303A, PartA_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            stringstream stream(input);
            long actual = Day03::PartA(stream);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartA_Suite, IO_Fixture_2303A,
            testing::Values(
                std::make_tuple(
                    "467..114..\r\n"
                    "...*......\r\n"
                    "..35..633.\r\n"
                    "......#...\r\n"
                    "617*......\r\n"
                    ".....+.58.\r\n"
                    "..592.....\r\n"
                    "......755.\r\n"
                    "...$.*....\r\n"
                    ".664.598..", 4361),
                std::make_tuple(
                    "...*...\r\n"
                    ".37.301\r\n"
                    ".......", 338)
            ));
#pragma endregion

#pragma region PartB
        class IO_Fixture_2303B : public IO_Fixture {};

        TEST_P(IO_Fixture_2303B, PartB_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            stringstream stream(input);
            long actual = Day03::PartB(stream);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartB_Suite, IO_Fixture_2303B,
            testing::Values(
                std::make_tuple(
                    "467..114..\r\n"
                    "...*......\r\n"
                    "..35..633.\r\n"
                    "......#...\r\n"
                    "617*......\r\n"
                    ".....+.58.\r\n"
                    "..592.....\r\n"
                    "......755.\r\n"
                    "...$.*....\r\n"
                    ".664.598..", 467835),
                std::make_tuple(
                    "...*...\r\n"
                    ".37.301\r\n"
                    ".......", 11137)
            ));
#pragma endregion
    }
}