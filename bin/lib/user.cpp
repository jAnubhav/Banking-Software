#include "../inc/helper.hpp"
#include "../inc/user.hpp"

const std::vector<std::pair<std::string, int>> words = extractData("utility/helping-words", functions::str_int);

const std::vector<std::function<accounts::AccountHolder(void)>> interactions = {login, createAccount};

int initializer(void) {
    int choice;


}