#include "../inc/bank.hpp"
// #include "../inc/format.hpp"
#include "../inc/helper.hpp"

const std::vector<std::pair<std::string, std::string>> acc_types::types = extractData("utility/account-types", functions::str_str);