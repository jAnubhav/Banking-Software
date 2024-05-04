#include "../inc/helper.hpp"

#include <iostream>
#include <iomanip>
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

std::string rChar(const char &ch, const int &len) { return std::string(len, ch); }

std::vector<std::string> rString(const char &ch, const std::vector<int> &data)
{
    std::vector<std::string> tempVec;

    for (const int &val : data)
        tempVec.push_back(rChar(ch, val));

    return tempVec;
}

void printLine(const char &ch1, const char &ch2, const std::vector<std::string> &data, const std::vector<int> &lengths, const int &pad)
{
    for (int i = 0; i < data.size(); i++)
        std::cout << ch1 << rChar(ch2, pad / 2) << std::left << std::setw(lengths.at(i)) << data.at(i) << rChar(ch2, pad / 2);
    std::cout << ch1 << std::endl;
}