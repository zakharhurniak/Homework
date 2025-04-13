#include "wordcounter.h"
#include <sstream>

void collectWords(std::istream& in, std::map<std::string, int>& wordCount, bool stopOnEmptyLine) {
    while (true) {
        std::string line;
        if (!std::getline(in, line)) {
            // End of file or stream error
            break;
        }
        if (stopOnEmptyLine && line.empty()) {
            // Stop if an empty line is found
            break;
        }
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            ++wordCount[word];
        }
    }
}
