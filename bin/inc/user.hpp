#ifndef USER
#define USER

#include "bank.hpp"

#include <functional>

#include <vector>

int initializer(void);

AccountHolder login(void), createAccount(void);

extern const std::vector<std::function<AccountHolder(void)>> interactions;

#endif