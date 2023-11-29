#include "pch.h"
#include <AdventOfCodeLibrary.h>

namespace Year2015
{
    namespace Day01
    {
        using testing::TestWithParam;
        using std::tuple;
        using std::string;

        class Fixture : public TestWithParam<tuple<string, int>> {};

        TEST_P(Fixture, PuzzleA)
        {
            auto& [input, expected] = GetParam();
            long actual = AdventOfCodeLibrary::Year2015::Day01::PuzzleA(input);
            EXPECT_EQ(actual, expected);
        }

        INSTANTIATE_TEST_CASE_P(PuzzleASuite, Fixture,
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