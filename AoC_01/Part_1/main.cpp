//Advent of Code 2023 Day 1 [Part 1]

#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>

int main() {

	int total = 0;

    //open file and read lines
    std::ifstream file("test.txt");
    int current_line = 0;
    std::string input_line;

    std::string read_line[1000];

    while (current_line < 1000) {

        current_line++;
        getline(file, input_line);
        read_line[current_line] = input_line;

    //remove letters from the strings
        boost::erase_all(read_line[current_line], "a");
        boost::erase_all(read_line[current_line], "b");
        boost::erase_all(read_line[current_line], "c");
        boost::erase_all(read_line[current_line], "d");
        boost::erase_all(read_line[current_line], "e");
        boost::erase_all(read_line[current_line], "f");
        boost::erase_all(read_line[current_line], "g");
        boost::erase_all(read_line[current_line], "h");
        boost::erase_all(read_line[current_line], "i");
        boost::erase_all(read_line[current_line], "j");
        boost::erase_all(read_line[current_line], "k");
        boost::erase_all(read_line[current_line], "l");
        boost::erase_all(read_line[current_line], "m");
        boost::erase_all(read_line[current_line], "n");
        boost::erase_all(read_line[current_line], "o");
        boost::erase_all(read_line[current_line], "p");
        boost::erase_all(read_line[current_line], "q");
        boost::erase_all(read_line[current_line], "r");
        boost::erase_all(read_line[current_line], "s");
        boost::erase_all(read_line[current_line], "t");
        boost::erase_all(read_line[current_line], "u");
        boost::erase_all(read_line[current_line], "v");
        boost::erase_all(read_line[current_line], "w");
        boost::erase_all(read_line[current_line], "x");
        boost::erase_all(read_line[current_line], "y");
        boost::erase_all(read_line[current_line], "z");

        std::stringstream create_digits;

        int chars = read_line[current_line].length();
		int tempnum[1000];

        if (read_line[current_line].length() > 2) {

            char digit_first = read_line[current_line].at(0);
            char digit_last = read_line[current_line].at(chars-1);

            create_digits << digit_first << digit_last;
            read_line[current_line] = create_digits.str();

			tempnum[current_line] = std::stoi(read_line[current_line]);
			tempnum[current_line] = tempnum[current_line];

        } else if (read_line[current_line].length() < 2) {

            char digit_first, digit_last;
            digit_first = digit_last = read_line[current_line].at(0);

            create_digits << digit_first << digit_last;
            read_line[current_line] = create_digits.str();
			tempnum[current_line] = std::stoi(read_line[current_line]);

        } else {

			tempnum[current_line] = std::stoi(read_line[current_line]);

		}

        total = total + tempnum[current_line];

        std::cout << tempnum[current_line] << std::endl;

    }

	std::cout << total << std::endl;

    file.close();

    return 0;


}