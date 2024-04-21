#ifndef BANK
#define BANK

#include <string>
#include <vector>

namespace accounts
{
    struct Address
    {
        int pincode;
        std::string city, district, state;
    };

    class BankAccount
    {
        double balance, rate, minimum_balance, transaction_limit, overdraft;
        std::string acc_no, acc_type, date_of_creation;

    protected:
        BankAccount(double, double, double, double, double, std::string, std::string, std::string);
    };

    class CurrentAccount : public BankAccount
    {
    public:
        CurrentAccount(double, std::string, std::string);
    };

    class SavingsAccount : public BankAccount
    {
    public:
        SavingsAccount(double, std::string, std::string);
    };

    class SalaryAccount : public BankAccount
    {
    public:
        SalaryAccount(double, std::string, std::string);
    };

    class FixedDepositAccount : public BankAccount
    {
    public:
        FixedDepositAccount(double, std::string, std::string);
    };

    class ZeroBalanceAccount : public BankAccount
    {
    public:
        ZeroBalanceAccount(double, std::string, std::string);
    };

    class AccountHolder
    {
        std::string first_name, last_name, email_address, phone_number, date_of_birth, job_title, pancard_number;
        Address address;
        BankAccount account;

    public:
        AccountHolder(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int, std::string);
    };

    inline std::string createAccountNo(char, char, std::string, const std::string &);
}

namespace acc_types
{
    extern const int maxLength;
    extern const std::vector<std::pair<std::string, std::string>> types;

    void printTypes(void);
}

#endif