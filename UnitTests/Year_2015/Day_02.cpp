#include "..\IO_Fixture.h"
#include "..\pch.h"
#include <AdventOfCodeLibrary.h>

namespace Year_2015
{
    namespace Day_02
    {
        namespace Day02 = AdventOfCodeLibrary::Year2015::Day02;

        using testing::TestWithParam;
        using std::tuple;
        using std::string;

        #pragma region PartA
        class IO_Fixture_1502A : public IO_Fixture {};

        TEST_P(IO_Fixture_1502A, PartA_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            long actual = Day02::PartA(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartA_Suite, IO_Fixture_1502A,
            testing::Values(
                std::make_tuple("2x3x4", 58),
                std::make_tuple("1x1x10", 43),
                std::make_tuple("2x3x4\r\n1x1x10\r\n", 101)
            ));
        #pragma endregion

        #pragma region PartB
        class IO_Fixture_1502B : public IO_Fixture {};

        TEST_P(IO_Fixture_1502B, PartB_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            long actual = Day02::PartB(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartB_Suite, IO_Fixture_1502B,
            testing::Values(
                std::make_tuple("2x3x4", 34),
                std::make_tuple("1x1x10", 14),
                std::make_tuple("2x3x4\r\n1x1x10\r\n", 48)
            ));
        #pragma endregion
    }
}