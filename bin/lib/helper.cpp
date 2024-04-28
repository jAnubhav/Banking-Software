#include "../inc/helper.hpp"

#include <iostream>
#include <iomanip>

inline auto funcs::str_fir(const std::pair<std::string, std::string> &pair) { return pair.first; }
inline auto funcs::str_int(const std::string &str) { return std::make_pair(str, str.length()); }
inline auto funcs::str_onl(const std::string &str) { return str; }
inline auto funcs::str_str(const std::string &str) { return std::make_pair(str, str.substr(0, 3)); }

inline auto funcs::rChar(const char &ch, const int &len) { return std::string(len, ch); }

void printLine(const char &ch1, const char &ch2, const int &pad, const std::vector<std::string> &val, const std::vector<int> &len)
{
    for (int i = 0; i < val.size(); i++)
        std::cout << ch1 << funcs::rChar(ch2, pad / 2) << std::left << std::setw(len.at(i)) << val.at(i) << funcs::rChar(ch2, pad / 2);
    std::cout << ch1 << std::endl;
}