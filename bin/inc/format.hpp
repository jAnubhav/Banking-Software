#ifndef FORMAT
#define FORMAT

#include <iostream>
#include <iomanip>

#include <string>

inline std::string rChar(int len) { return std::string(len + 2, '-'); }

inline void makeT(const char &sep, const int &len, bool end)
{
    std::cout << sep << rChar(len);
    if (end)
        std::cout << sep << std::endl;
}

inline void makeLine(const char &sep, const int &len) { makeT(sep, len, true); }

template <typename... Args>
void makeLine(const char &sep, const int &len, Args... args)
{
    makeT(sep, len, false);
    makeLine(sep, args...);
}

template <typename T>
inline void printT(const char &sep, const T &value, const int &len, bool end)
{
    std::cout << sep << ' ' << std::setw(len) << std::left << value << ' ';
    if (end)
        std::cout << sep << std::endl;
}

template <typename T>
inline void printLine(const char &sep, const T &value, const int &len) { printT(sep, value, len, true); }

template <typename T, typename... Args>
void printLine(const char &sep, const T &value, const int &len, Args... args)
{
    printT(sep, value, len, false);
    printLine(sep, args...);
}

#endif