#include "../inc/bank.hpp"
#include "../inc/helper.hpp"

const int pad = 1;
const char pl = '+', mn = '-', pp = '|', sp = ' ';

const auto words = extractData("utility/helping-words");
const auto types = extractData("utility/account-types");

const auto dataLengths = []()
{
    std::vector<int> tempVec;
    const auto data = extractData("utility/helping-words");

    for (const auto &val : data)
        tempVec.push_back(val.length());

    return tempVec;
}();

const auto lineData = rString(mn, dataLengths);

const auto dataTypes = []()
{
    int index = 1;
    std::vector<std::vector<std::string>> tempVec;

    for (const auto &val : types)
        tempVec.push_back({std::to_string(index++), val, val.substr(0, 3)});

    return tempVec;
}();

void printTypes(void)
{
    printLine(pl, mn, pad, dataLengths, lineData);
    printLine(pp, sp, pad, dataLengths, words);

    printLine(pl, mn, pad, dataLengths, lineData);

    for (const auto &val : dataTypes)
        printLine(pp, sp, pad, dataLengths, val);

    printLine(pl, mn, pad, dataLengths, lineData);
}