// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <AdventOfCodeLibrary.h>
#include "Input.h"

int main()
{
    long result = AdventOfCodeLibrary::Year2015::Day01::PuzzleA(Input::Year2015::PuzzleA);
    std::string output = std::to_string(result);
    std::cout << output + "\n";
}