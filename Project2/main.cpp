#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <limits>
#include "wordcounter.h"

int main() {
    std::cout << "Choose input source (1 for console, 2 for file): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::map<std::string, int> wordCount;

    if (choice == 2) {
        std::cout << "Enter file path: ";
        std::string filePath;
        if (!std::getline(std::cin, filePath)) {
            std::cerr << "Error reading file path." << std::endl;
            return 1;
        }
        std::ifstream inFile(filePath);
        if (!inFile) {
            std::cerr << "Error opening file." << std::endl;
            return 1;
        }
        collectWords(inFile, wordCount, /*stopOnEmptyLine=*/true);
    }
    else {
        std::cout << "Enter text (press Enter on an empty line to stop):" << std::endl;
        collectWords(std::cin, wordCount, /*stopOnEmptyLine=*/true);
    }

    // Output word counts
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
