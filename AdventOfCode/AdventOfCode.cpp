// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <AdventOfCodeLibrary.h>
#include "Input.h"

int main()
{
    using std::string;

    ////Year 2015 Day 01 Part A
    //const string& input = Input::Year2015::Day01;
    //long result = AdventOfCodeLibrary::Year2015::Day01::PartA(input);
    //string output = std::to_string(result);
    //std::cout << output + "\n";

    ////Year 2015 Day 01 Part B
    //const string& input = Input::Year2015::Day01;
    //long result = AdventOfCodeLibrary::Year2015::Day01::PartB(input);
    //string output = std::to_string(result);
    //std::cout << output + "\n";

    //Year 2015 Day 02 Part A
    const string& input = Input::Year2015::Day02;
    long result = AdventOfCodeLibrary::Year2015::Day01::PartA(input);
    string output = std::to_string(result);
    std::cout << output + "\n";

    ////Year 2015 Day 02 Part B
    //const string& input = Input::Year2015::Day02;
    //long result = AdventOfCodeLibrary::Year2015::Day01::PartB(input);
    //string output = std::to_string(result);
    //std::cout << output + "\n";
}