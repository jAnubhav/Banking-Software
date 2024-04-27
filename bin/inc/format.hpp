#ifndef FORMAT
#define FORMAT

#include <iostream>
#include <iomanip>

#include <string>

inline std::string rChar(const char &ch, const int &len) { return std::string(len, ch); }

template <typename T>
void printParent(const char &ch1, const T &val, const int &len, char ch2, bool end = false)
{
    int pad = 2;
    std::cout << ch1 << rChar(ch2, pad / 2) << std::left << std::setw(len) << val << rChar(ch2, pad / 2);
    if (end)
        std::cout << ch1 << std::endl;
}

void makeLine(const char &ch, const int &len) { printParent('+', rChar(ch, len), len, ch, true); }

template <typename... Args>
void makeLine(const char &ch, const int &len, Args... args)
{
    printParent('+', rChar(ch, len), len, ch);
    makeLine(ch, args...);
}

template <typename T>
void printLine(const char &ch, const T &val, const int &len) { printParent(ch, val, len, ' ', true); }

template <typename T, typename... Args>
void printLine(const char &ch, const T &val, const int &len, Args... args)
{
    printParent(ch, val, len, ' ');
    printLine(ch, args...);
}

#endif