#include "../inc/helper.hpp"

#include <fstream>

std::vector<std::string> extractData(std::string file_name)
{
    std::string tempStr;
    std::vector<std::string> tempVec;

    std::ifstream file("data/" + file_name + ".bin", std::ios_base::binary);

    while (std::getline(file, tempStr))
        tempVec.push_back(tempStr);

    return tempVec;
}

std::vector<int> createLength(const std::vector<std::string> &data)
{
    std::vector<int> lengths;

    for (const std::string &val : data)
        lengths.push_back(val.length());
    return lengths;
}

std::vector<std::vector<std::string>> createType(const std::vector<std::string> &data)
{
    int index = 1;
    std::vector<std::string> tempVec;

    std::vector<std::vector<std::string>> completeData;

    for (const std::string &val : data)
        completeData.push_back({std::to_string(index++), val, val.substr(0, 3)});

    return completeData;
}