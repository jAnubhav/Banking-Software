#ifndef FORMAT
#define FORMAT

#include <iostream>
#include <iomanip>

#include <string>

template <typename T>
void printParent(const char &ch1, const char &ch2, const int &pad,  const T&val, const int &len) {
    std::cout << ch1 << rChar(ch2, pad/2) << std::left << std::setw(len) << val << rChar(ch2, pad/2);
}

// void makeLine(const char &ch1, const char &ch2, const int &pad, const int &len) {
//     printParent(ch1, ch2, pad, rChar(ch2, len), len);
// }

// template <typename Args>
// void makeLine(const char &ch1, const char &ch2, const int &pad, const int &len, Args args...) {
//     printParent(ch1, ch2, pad, rChar(ch2, len), len);
//     makeLine(ch1, ch2, pad, args...);
// }

template<typename T>
void printLine(const char &ch1, const char &ch2, const int &pad, const T &val, const int &len) {
    printParent(ch1, ch2, pad, val, len);
}

template<typename T, typename Args>
void printLine(const char &ch1, const char &ch2, const int &pad, const T &val, const int &len, Args args...) {
    printParent(ch1, ch2, pad, val, len);
    printLine(ch1, ch2, pad, args...);
}

#endif