#ifndef HELPER
#define HELPER

#include <string>
#include <vector>

std::vector<std::string> extractData(std::string);

std::string rChar(const char &, const int &);
std::vector<std::string> rString(const char &, const std::vector<int> &);

void printLine(const char &, const char &, const int &, const std::vector<int> &, const std::vector<std::string> &);

#endif