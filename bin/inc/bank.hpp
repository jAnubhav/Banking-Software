#ifndef BANK
#define BANK

#include <string>
#include <vector>

class AccountHolder
{
    std::vector<std::string> account_data;

public:
    AccountHolder();
    AccountHolder(const std::vector<std::string> &);
};

#endif