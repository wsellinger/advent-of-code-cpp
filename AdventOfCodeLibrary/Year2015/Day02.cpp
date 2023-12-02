#include "../Utilities/StringUtilities.h"
#include "Day02.h"
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
using std::string;
using std::exception;

/// <summary>
/// -- - Day 2: I Was Told There Would Be No Math-- -
/// 
/// The elves are running low on wrapping paper, and so they need to submit an order for more.They have a list of the dimensions(length l, 
/// width w, and height h) of each present, and only want to order exactly as much as they need.
/// 
/// Fortunately, every present is a box(a perfect right rectangular prism), which makes calculating the required wrapping paper for each gift 
/// a little easier : find the surface area of the box, which is 2 * l * w + 2 * w * h + 2 * h * l.The elves also need a little extra paper 
/// for each present : the area of the smallest side.
/// 
/// For example :
/// 
/// A present with dimensions 2x3x4 requires 2 * 6 + 2 * 12 + 2 * 8 = 52 square feet of wrapping paper plus 6 square feet of slack, for a 
/// total of 58 square feet.
/// A present with dimensions 1x1x10 requires 2 * 1 + 2 * 10 + 2 * 10 = 42 square feet of wrapping paper plus 1 square foot of slack, for a 
/// total of 43 square feet.
/// 
/// All numbers in the elves' list are in feet. How many total square feet of wrapping paper should they order?
/// 
/// Your puzzle answer was 1588178.
/// -- - Part Two-- -
/// 
/// The elves are also running low on ribbon.Ribbon is all the same width, so they only have to worry about the length they need to order, 
/// which they would again like to be exact.
/// 
/// The ribbon required to wrap a present is the shortest distance around its sides, or the smallest perimeter of any one face.Each present 
/// also requires a bow made out of ribbon as well; the feet of ribbon required for the perfect bow is equal to the cubic feet of volume of 
/// the present.Don't ask how they tie the bow, though; they'll never tell.
/// 
/// For example :
/// 
/// A present with dimensions 2x3x4 requires 2 + 2 + 3 + 3 = 10 feet of ribbon to wrap the present plus 2 * 3 * 4 = 24 feet of ribbon 
/// for the bow, for a total of 34 feet.
/// A present with dimensions 1x1x10 requires 1 + 1 + 1 + 1 = 4 feet of ribbon to wrap the present plus 1 * 1 * 10 = 10 feet of ribbon 
/// for the bow, for a total of 14 feet.
/// 
/// How many total feet of ribbon should they order ?
/// 
/// 
/// </summary>
/// 
namespace AdventOfCodeLibrary
{
    namespace Implementation
    {
        namespace Year2015
        {
            long Day02::PartA(const std::string& input)
            {
                vector<Box> boxVector = GetBoxVector(input);

                return std::accumulate(boxVector.begin(), boxVector.end(), 0,
                    [](int sum, const Box& box)
                    {
                        return sum + (box.GetSurfaceArea() + box.GetSmallestSideArea());
                    });
            }

            long Day02::PartB(const std::string& input)
            {
                vector<Box> boxVector = GetBoxVector(input);

                return std::accumulate(boxVector.begin(), boxVector.end(), 0,
                    [](int sum, const Box& box)
                    {
                        return sum + (box.GetShortestPerimeter() + box.GetVolume());
                    });
            }

            const string Day02::NEWLINE = "\r\n";

            vector<Day02::Box> Day02::GetBoxVector(string input)
            {
                vector<Box> result;
                                
                string sanitizedInput = SanitizeInput(input);
                vector<string> inputVector = StringUtilities::Split(sanitizedInput, NEWLINE);

                for (const string token : inputVector)
                {
                    Box box = Box::GetBoxFromInput(token);
                    result.push_back(box);
                }

                return result;
            }

            string Day02::SanitizeInput(string input)
            {
                size_t lastTwoIndex = input.size() - 2;
                string lastTwoChars = input.substr(lastTwoIndex);

                if (lastTwoChars == NEWLINE)
                {
                    return input.substr(0, lastTwoIndex);
                }
                else
                {
                    return input;
                }
            }

            Day02::Box Day02::Box::GetBoxFromInput(string input)
            {                
                const char DELIMITER = 'x';

                vector<string> inputVector = StringUtilities::Split(input, DELIMITER);

                if (inputVector.size() == 3)
                {
                    return
                    {
                        std::stol(inputVector[0]), //Length 
                        std::stol(inputVector[1]), //Width
                        std::stol(inputVector[2]) //Height
                    };
                }
                else
                    throw exception("Not Implemented");
            }

            long Day02::Box::GetSurfaceArea() const
            {
                return
                    (2 * GetAreaLengthWidth()) +
                    (2 * GetAreaWidthHeight()) +
                    (2 * GetAreaHeightLength());
            }

            long Day02::Box::GetSmallestSideArea() const
            {
                return std::min({ GetAreaLengthWidth(), GetAreaWidthHeight(), GetAreaHeightLength()});
            }

            long Day02::Box::GetShortestPerimeter() const
            {
                vector<int> sides = { Length, Width, Height };
                std::sort(sides.begin(), sides.end());
                
                return (sides[0] + sides[1]) * 2;
            }

        }
    }
}