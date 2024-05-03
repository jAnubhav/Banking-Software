#ifndef HELPER
#define HELPER

#include <string>
#include <vector>

std::vector<std::string> extractData(std::string);

std::vector<int> createLength(const std::vector<std::string> &);
std::vector<std::vector<std::string>> createType(const std::vector<std::string> &);

std::string rChar(const char &, const int &);
std::vector<std::string> rString(const char &, const std::vector<int> &);

void printLine(const char &, const char &, const std::vector<std::string> &, const std::vector<int> &, const int &);

#endif