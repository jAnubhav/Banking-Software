#ifndef HELPER
#define HELPER

#include <fstream>

#include <string>
#include <vector>

namespace funcs
{
    inline auto str_int(const std::string &),
        str_onl(const std::string &),
        str_str(const std::string &),
        rChar(const char &, const int &);
}

template <typename T>
std::vector<T> extractData(std::string file_name, T (*func)(const std::string &))
{
    std::string tempStr;
    std::vector<T> tempVec;

    std::ifstream file("data/" + file_name + ".bin", std::ios_base::binary);

    while (std::getline(file, tempStr))
        tempVec.push_back(func(tempStr));

    return tempVec;
}

int findLength(const std::vector<std::string> &);

void printLine(const char &, const char &, const int &, const std::vector<std::string> &, const std::vector<int> &);

#endif