//Advent of Code 2023 Day 1 [Part 2]

#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

const std::string cur = "=> ";
int total = 0;

int main(int argc, char* argv[]) {

    //convert char* argv[1] to a string
    std::stringstream unconv_path;
    std::string path;

    unconv_path << argv[1];
    unconv_path >> path;

    //try to open provided file path
    std::ifstream input(path);
    if (!input) {

        std::cout << cur << "invalid input file" << std::endl;
        return 0;

    }

    std::string read_line;
    std::string input_line[1000];

    for (int i = 0; i < 1000; i++) {

        getline(input, read_line);
        input_line[i] = read_line;

        std::cout << "Line [1] [" << i << "]: " << input_line[i] << std::endl;

        //get rid of overlaping numbers
        std::string overlap_vals[2][8] {
            { "oneight", "twone", "threeight", "fiveight", "sevenine", "eightwo", "eighthree", "nineight"},
            { "1", "2", "3", "5", "7", "8", "8", "9"}
        };

        for (int l = 0; l < 8; l++) {

            if (input_line[i].find(overlap_vals[0][l]) != std::string::npos){

                boost::replace_all(input_line[i], overlap_vals[0][l], overlap_vals[1][l]);

            }

        }

        std::cout << "Line [1] [" << i << "]: " << input_line[i] << std::endl;

        //replace text with numbers
        std::string values[2][9] {
            { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" },
            { "1", "2", "3", "4", "5", "6", "7", "8", "9" }
        };

        for (int j = 0; j < 9; j++) {

           if (input_line[i].find(values[0][j]) != std::string::npos){

            boost::replace_all(input_line[i], values[0][j], values[1][j]);

           }

        }

        std::cout << "Line [2] [" << i << "]: " << input_line[i] << std::endl;

        //erase the unneeded letters
        std::string unwanted_chars[26]{
            "a", "b", "c", "d", "e", "f", "g",
            "h", "i", "j", "k", "l", "m", "n",
            "o", "p", "q", "r", "s", "t", "u",
            "v", "w", "x", "y", "z"
        };

        for (int k = 0; k < 26; k++) {

            boost::erase_all(input_line[i], unwanted_chars[k]);

        }

        std::cout << "Line [3] [" << i << "]: " << input_line[i] << std::endl;

        //convert strings to numbers
        std::stringstream create_digits;
        int tempnum[1000];
        int line_length = input_line[i].length();

        if (input_line[i].length() > 2) {

            char digit_first = input_line[i].at(0);
            char digit_last = input_line[i].at(line_length-1);

            create_digits << digit_first << digit_last;
            input_line[i] = create_digits.str();

            tempnum[i] = std::stoi(input_line[i]);

        } else if (input_line[i].length() < 2) {

            char digit_first, digit_last;
            digit_first = digit_last = input_line[i].at(0);

            create_digits << digit_first << digit_last;
            input_line[i] = create_digits.str();

            tempnum[i] = std::stoi(input_line[i]);

        } else {

            tempnum[i] = std::stoi(input_line[i]);

        }

        total = total + tempnum[i];

        std::cout << "Line [4] [" << i << "]: " << input_line[i] << std::endl;

    }

    input.close();

    std::cout << cur << "total is: " << total - 2 << std::endl;

    return 0;

}