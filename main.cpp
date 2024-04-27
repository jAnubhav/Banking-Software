#include "bin\inc\helper.hpp"

#include <iostream>

int main()
{
    auto vec = extractData("utility/account-types", functions::str_str);
    for (auto &v : vec)
        std::cout << v.second << std::endl;
}