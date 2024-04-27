#include "../inc/user.hpp"

const std::vector<std::function<accounts::AccountHolder(void)>> interactions = {login, createAccount};