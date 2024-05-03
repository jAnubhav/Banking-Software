#ifndef HELPER
#define HELPER

#include <string>
#include <vector>

std::vector<std::string> extractData(std::string);

std::vector<int> createLength(const std::vector<std::string> &);
std::vector<std::vector<std::string>> createType(const std::vector<std::string> &);

#endif