#include "..\IO_Fixture.h"
#include "..\pch.h"
#include <AdventOfCodeLibrary.h>
#include <sstream>

namespace Year_2023
{
    namespace Day_01
    {
        namespace Day01 = AdventOfCodeLibrary::Year2023::Day01;

        using testing::TestWithParam;
        using std::tuple;
        using std::string;
        using std::stringstream;


        #pragma region PartA
        class IO_Fixture_2301A : public IO_Fixture {};

        TEST_P(IO_Fixture_2301A, PartA_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            stringstream stream(input);
            long actual = Day01::PartA(stream);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartA_Suite, IO_Fixture_2301A,
            testing::Values(
                std::make_tuple("1abc2", 12),
                std::make_tuple("pqr3stu8vwx", 38),
                std::make_tuple("a1b2c3d4e5f", 15),
                std::make_tuple("treb7uchet", 77),
                std::make_tuple("pqr3stu8vwx\r\na1b2c3d4e5f", 53),
                std::make_tuple("1abc2\r\ntreb7uchet", 89),
                std::make_tuple("1abc2\r\npqr3stu8vwx\r\na1b2c3d4e5f\r\ntreb7uchet", 142)
            ));
        #pragma endregion

        #pragma region PartB
        class IO_Fixture_2301B : public IO_Fixture {};

        TEST_P(IO_Fixture_2301B, PartB_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            stringstream stream(input);
            long actual = Day01::PartB(stream);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartB_Suite, IO_Fixture_2301B,
            testing::Values(
                std::make_tuple("two1nine", 29),
                std::make_tuple("eightwothree", 83),
                std::make_tuple("abcone2threexyz", 13),
                std::make_tuple("xtwone3four", 24),
                std::make_tuple("4nineeightseven2", 42),
                std::make_tuple("zoneight234", 14),
                std::make_tuple("7pqrstsixteen", 76),
                std::make_tuple("two1nine\r\nzoneight234", 43),
                std::make_tuple("two1nine\r\neightwothree\r\nabcone2threexyz\r\nxtwone3four\r\n4nineeightseven2\r\nzoneight234\r\n7pqrstsixteen", 281)
            ));
        #pragma endregion
    }
}