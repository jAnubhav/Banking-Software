#ifndef USER
#define USER

#include "bank.hpp"

#include <functional>

#include <vector>

extern const std::vector<std::function<accounts::AccountHolder(void)>> interactions;

int initializer(void);
accounts::AccountHolder login(void), createAccount(void);

#endif