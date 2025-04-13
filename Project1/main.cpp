#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "parentheses.h"

int main() {
    std::cout << "Choose input source (1 for console, 2 for file): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 2) {
        std::cout << "Enter file path: ";
        std::string filePath;
        std::getline(std::cin, filePath);

        std::ifstream inFile(filePath);
        if (!inFile) {
            std::cerr << "Error opening file." << std::endl;
            return 1;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            if (areParenthesesBalanced(line))
                std::cout << line << " -> Balanced" << std::endl;
            else
                std::cout << line << " -> Not Balanced" << std::endl;
        }
    }
    else {
        std::cout << "Enter parentheses to check: ";
        std::string input;
        std::getline(std::cin, input);

        if (areParenthesesBalanced(input))
            std::cout << "Balanced" << std::endl;
        else
            std::cout << "Not Balanced" << std::endl;
    }

    return 0;
}
