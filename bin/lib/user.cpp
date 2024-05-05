#include "../inc/user.hpp"

const std::vector<std::function<AccountHolder(void)>> interactions = {login, createAccount};