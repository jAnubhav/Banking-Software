#ifndef BANK
#define BANK

#include <string>
#include <vector>

namespace acc_types
{
    extern const std::vector<std::pair<std::string, std::string>> types;
}

namespace accounts
{
    class AccountHolder
    {
        std::vector<std::string> account_data;

    public:
        AccountHolder();
        AccountHolder(const std::vector<std::string> &);
    };
}

#endif