#include "../inc/format.hpp"
#include "../inc/helper.hpp"
#include "../inc/user.hpp"

inline std::string rChar(const char &ch, const int &len) { return std::string(len, ch); }

const auto words = extractData("utility/helping-words", functions::str_int);
const auto initials = extractData("utility/initials", functions::str_only);
const auto types = extractData("utility/account-types", functions::str_str);

void printTypes(void) {
    int pad = 2;

}

const std::vector<std::function<AccountHolder(void)>> interactions = {login, createAccount};

int initializer(void) {
    int choice;


}

AccountHolder login(void) {
    return AccountHolder();
}

AccountHolder createAccount(void) {
    return AccountHolder();
}