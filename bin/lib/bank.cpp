#include "../inc/bank.hpp"
#include "../inc/format.hpp"
#include "../inc/helper.hpp"

namespace
{
    const char sep1 = '+', sep2 = '|';
    const std::vector<std::pair<std::string, int>> words = extractData<std::pair<std::string, int>>("helping-words");

    const int &len1 = words.at(0).second, &len2 = acc_types::maxLength, &len3 = words.at(2).second;

    accounts::BankAccount decideAccount(int balance, std::string acc_type, std::string date_of_creation) {
        // if (acc_type == acc_types::types.at(0).second) 
    }
}

accounts::BankAccount::BankAccount(double balance, double rate, double minimum_balance, double transaction_limit, double overdraft, std::string acc_no, std::string acc_type, std::string date_of_creation) : balance(balance), rate(rate), minimum_balance(minimum_balance), transaction_limit(transaction_limit), overdraft(overdraft), acc_no(acc_no), acc_type(acc_type), date_of_creation(date_of_creation)
{
}

accounts::CurrentAccount::CurrentAccount(double balance, std::string acc_no, std::string date_of_creation) : BankAccount(balance, 0, 50000, -1, 1000000, acc_no, acc_types::types.at(0).second, date_of_creation) {}

accounts::SavingsAccount::SavingsAccount(double balance, std::string acc_no, std::string date_of_creation) : BankAccount(balance, 7, 10000, 250000, 0, acc_no, acc_types::types.at(1).second, date_of_creation) {}

accounts::SalaryAccount::SalaryAccount(double balance, std::string acc_no, std::string date_of_creation) : BankAccount(balance, 5, 10000, -1, 250000, acc_no, acc_types::types.at(2).second, date_of_creation) {}

accounts::FixedDepositAccount::FixedDepositAccount(double balance, std::string acc_no, std::string date_of_creation) : BankAccount(balance, 12, 50000, 0, balance * 1.5, acc_no, acc_types::types.at(3).second, date_of_creation) {}

accounts::ZeroBalanceAccount::ZeroBalanceAccount(double balance, std::string acc_no, std::string date_of_creation) : BankAccount(balance, 3, 0, 100000, 0, acc_no, acc_types::types.at(4).second, date_of_creation) {}


// accounts::AccountHolder::AccountHolder(std::string first_name, std::string last_name, std::string email_address, std::string phone_number, std::string date_of_birth, std::string job_title, std::string pancard_number, std::string city, std::string district, std::string state, int pincode, std::string acc_type,) : first_name(first_name), last_name(last_name), email_address(email_address), phone_number(phone_number), date_of_birth(date_of_birth), job_title(job_title), pancard_number(pancard_number), address {pincode, city, state, district}, account(decideAccount(b)) {}


inline std::string accounts::createAccountNo(char f, char l, std::string num, const std::string &type) { return type + num + f + l; }

const std::vector<std::pair<std::string, std::string>> acc_types::types =
    extractData<std::pair<std::string, std::string>>("account-types", words.at(3).first);

const int acc_types::maxLength = findMaxLength(acc_types::types);

void acc_types::printTypes(void)
{
    int index = 1;

    makeLine(sep1, len1, len2, len3);
    printLine(sep2, words.at(0).first, len1, words.at(1).first, len2, words.at(2).first, len3);
    makeLine(sep1, len1, len2, len3);

    for (const auto pair : acc_types::types)
        printLine(sep2, index++, len1, pair.first, len2, pair.second, len3);
    makeLine(sep1, len1, len2, len3);
}