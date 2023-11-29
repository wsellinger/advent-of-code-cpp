#include "..\pch.h"
#include <AdventOfCodeLibrary.h>

namespace Year_2015
{
    namespace Day_01
    {
        using testing::TestWithParam;
        using std::tuple;
        using std::string;

        #pragma region PartA
        class PartA_Fixture : public TestWithParam<tuple<string, int>> {};

        TEST_P(PartA_Fixture, PartA_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            long actual = AdventOfCodeLibrary::Year2015::Day01::PartA(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartA_Suite, PartA_Fixture,
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
        class PartB_Fixture : public TestWithParam<tuple<string, int>> {};

        TEST_P(PartB_Fixture, PartB_Given_ValidInput_Returns_ExpectedResult)
        {
            auto& [input, expected] = GetParam();
            long actual = AdventOfCodeLibrary::Year2015::Day01::PartB(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartB_Suite, PartB_Fixture,
            testing::Values(
                std::make_tuple(")", 1),
                std::make_tuple("()())", 5),
                std::make_tuple("(", -1)
            ));
        #pragma endregion
    }
}