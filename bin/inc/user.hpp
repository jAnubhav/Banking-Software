#ifndef USER
#define USER

#include "bank.hpp"

#include <functional>

#include <vector>

extern const std::vector<std::function<AccountHolder(void)>> interactions;

int initializer(void);
AccountHolder login(void), createAccount(void);

#endif