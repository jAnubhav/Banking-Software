#ifndef HELPER
#define HELPER

#include <fstream>

#include <algorithm>

#include <string>
#include <vector>

namespace functions
{
    inline auto str_only(const std::string &str) { return str; }

    inline auto str_int(const std::string &str) { return std::make_pair(str, static_cast<int>(str.length())); }

    inline auto str_str(const std::string &str) { return std::make_pair(str, str.substr(0, 3)); }

    inline auto str_fir(const std::pair<std::string, std::string> &pair) { return pair.first; }
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

template <typename T>
int findLength(const std::vector<T> &vec, std::string (*func)(const T &))
{
    size_t len = 0;
    for (const auto &val : vec)
        len = std::max(len, func(val).length());
    return len;
}

#endif