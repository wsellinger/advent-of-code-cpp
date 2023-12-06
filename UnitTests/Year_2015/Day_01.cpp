#include "..\IO_Fixture.h"
#include "..\pch.h"
#include <AdventOfCodeLibrary.h>

namespace Year_2015
{
    namespace Day_01
    {
        namespace Day01 = AdventOfCodeLibrary::Year2015::Day01;

        using testing::TestWithParam;
        using std::tuple;
        using std::string;

        #pragma region PartA
        class IO_Fixture_1501A : public IO_Fixture {};

        TEST_P(IO_Fixture_1501A, PartA_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            long actual = Day01::PartA(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartA_Suite, IO_Fixture_1501A,
            testing::Values(
                std::make_tuple("(())", 0),
                std::make_tuple("()()", 0),
                std::make_tuple("(((", 3),
                std::make_tuple("(()(()(", 3),
                std::make_tuple("))(((((", 3),
                std::make_tuple("())", -1),
                std::make_tuple("))(", -1),
                std::make_tuple(")))", -3),
                std::make_tuple(")())())", -3)
            ));
        #pragma endregion

        #pragma region PartB
        class IO_Fixture_1501B : public IO_Fixture {};

        TEST_P(IO_Fixture_1501B, PartB_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            long actual = Day01::PartB(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartB_Suite, IO_Fixture_1501B,
            testing::Values(
                std::make_tuple(")", 1),
                std::make_tuple("()())", 5),
                std::make_tuple("(", -1)
            ));
        #pragma endregion
    }
}