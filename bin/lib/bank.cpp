#include "../inc/bank.hpp"
#include "../inc/helper.hpp"

const char pl = '+', mn = '-', pp = '|', sp = ' ';
const int pad = 2;

const auto types = extractData("utility/account-types");

const auto typesLength = createLength(types);
const auto typesData = createType(types);

const auto lineData = rString(mn, typesLength);

void printTypes(void)
{
    printLine(pl, mn, pad, typesLength, lineData);
    printLine(pl, mn, pad, typesLength, lineData);
    printLine(pl, mn, pad, typesLength, lineData);
}