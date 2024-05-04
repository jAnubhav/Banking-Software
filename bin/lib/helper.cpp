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
    {
        tempVec.push_back(tempStr);
    }
    file.close();

    return tempVec;
}

std::string rChar(const char &ch, const int &len) { return std::string(len, ch); }

std::vector<std::string> rString(const char &ch, const std::vector<int> &lens)
{
    std::vector<std::string> tempVec;

    for (const int &len : lens)
        tempVec.push_back(rChar(ch, len));

    return tempVec;
}

void printLine(const char &ch1, const char &ch2, const int &pad, const std::vector<int> &lens, const std::vector<std::string> &data)
{
    for (int i = 0; i < lens.size(); i++)
        std::cout << ch1 << rChar(ch2, pad) << std::left << std::setw(lens.at(i)) << data.at(i) << rChar(ch2, pad);
    std::cout << ch1 << std::endl;
}