#ifndef HELPER
#define HELPER

#include <fstream>

#include <functional>

#include <vector>
#include <string>

inline std::pair<std::string, int> str_len(const std::string &str) { return std::make_pair(str, str.length()); }
inline std::pair<std::string, std::string> str_str(const std::string &str) { return std::make_pair(str, str.substr(0, 3)); }

template <typename T>
std::vector<T> extractData(
    std::string file_name,
    const std::function<T(const std::string &)> func = [](const std::string &str)
    { return str; })
{
    std::string tempStr;
    std::vector<std::string> tempVec;

    std::ifstream file("data/" + file_name + ".bin", std::ios_base::binary);

    while (std::getline(file, tempStr))
        tempVec.push_back(func(tempStr));

    return tempVec;
}

#endif