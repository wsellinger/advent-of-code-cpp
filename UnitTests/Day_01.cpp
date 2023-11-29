#include "pch.h"
#include <AdventOfCodeLibrary.h>

namespace Year_2015
{
    namespace Day_01
    {
        using testing::TestWithParam;
        using std::tuple;
        using std::string;

        class Fixture : public TestWithParam<tuple<string, int>> {};

        TEST_P(Fixture, PartA)
        {
            auto& [input, expected] = GetParam();
            long actual = AdventOfCodeLibrary::Year2015::Day01::PartA(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PartA_Suite, Fixture,
            testing::Values(
                std::make_tuple("(())", 0),
                std::make_tuple("()()", 0),
                std::make_tuple("(((", 3),
                std::make_tuple("(()(()(", 3),
                std::make_tuple("))(((((", 3),
                std::make_tuple("())", -1),
                std::make_tuple("))(", -1),
                std::make_tuple(")))", -3),
                std::make_tuple(")())())", -3)));
    }
}