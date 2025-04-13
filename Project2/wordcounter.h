#pragma once
#include <map>
#include <string>
#include <istream>

void collectWords(std::istream& in, std::map<std::string, int>& wordCount, bool stopOnEmptyLine);
