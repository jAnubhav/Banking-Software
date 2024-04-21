#ifndef HELPER
#define HELPER

#include <fstream>

#include <algorithm>
#include <type_traits>

#include <string>
#include <vector>

struct sec_value
{
    std::string value;
};

template <typename T, typename U = std::string>
std::vector<T> extractData(std::string file_name, const U &str = "")
{
    std::string tempStr;
    std::vector<T> vec;

    std::ifstream file("data/usable/" + file_name + ".bin", std::ios_base::binary);
    while (std::getline(file, tempStr))
        if constexpr (std::is_same<T, std::string>::value)
            vec.push_back(tempStr);
        else if constexpr (std::is_same<T, std::pair<std::string, int>>::value)
            vec.push_back(std::make_pair(tempStr, tempStr.length()));
        else if constexpr (std::is_same<U, sec_value>::value)
            vec.push_back(std::make_pair(tempStr, str.value));
        else
        {
            std::string tempStr2;
            std::getline(file, tempStr2);
            vec.push_back(std::make_pair(tempStr + ((str.empty()) ? str : " " + str), tempStr2));
        }

    file.close();
    return vec;
}

template <typename T>
int findMaxLength(const std::vector<T> &vec)
{
    size_t maxLength = 0;
    for (const T &tempVar : vec)
        if constexpr (std::is_same<T, std::string>::value)
            maxLength = std::max(maxLength, tempVar.length());
        else
            maxLength = std::max(maxLength, tempVar.first.length());
    return maxLength;
}

#endif