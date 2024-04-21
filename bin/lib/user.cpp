#include "../inc/user.hpp"
#include "../inc/helper.hpp"

#include <iostream>
#include <fstream>

#include <string>

namespace
{
    sec_value operator""_V(const char *value, size_t) { return sec_value{value}; }

    const std::vector<std::string> initials = extractData<std::string>("initials");
    
    std::vector<std::pair<std::string, std::string>> inputable = extractData<std::pair<std::string, std::string>>("inputable", ""_V);
}

const std::vector<std::function<accounts::AccountHolder(void)>> interactions = {login, createAccount};

int initialize(void)
{
    int choice;
    std::string tempStr;

    std::cout << "\nWelcome to the Banking Software" << std::endl
              << std::endl;
    while (true)
    {
        int index = 1;
        for (const auto &str : initials)
            std::cout << index++ << ") " << str << std::endl;
        std::cout << "\nEnter your Choice: ";
        std::cin >> tempStr;

        try
        {
            if ((choice = std::stoi(tempStr)) and 1 <= choice and choice <= 3)
                break;
            else
                throw std::exception();
        }
        catch (std::exception)
        {
            std::cout << "\nEnter correct choice!!!" << std::endl
                      << std::endl;
        }
    }
    return choice;
}

accounts::AccountHolder login(void)
{
    bool flag = true;
    std::string tempStr1, tempStr2;
    std::vector<std::pair<std::string, std::string>> cred = {{"Username", ""}, {"Password", ""}};

    std::ifstream file("data/accounts/accounts.bin", std::ios_base::binary);

    std::cout << "\nBanking Software : Login" << std::endl
              << std::endl;
    while (flag)
    {
        for (auto &pair : cred)
        {
            std::cout << "\nEnter your " << pair.first << ": ";
            std::cin >> pair.second;
        }

        while (flag and std::getline(file, tempStr1) and std::getline(file, tempStr2))
            if ((cred.at(0).second == tempStr1) and (cred.at(1).second == tempStr2))
                flag = false;

        if (flag)
            std::cout << "\nEither wrong username or wrong password.\nRetry Again" << std::endl;
    }
    file.close();

    const std::vector<std::string> user_data = extractData<std::string>(cred.at(0).second);

    return accounts::AccountHolder();
}

accounts::AccountHolder createAccount(void)
{
    std::cout << "\nBanking Software : Create Account" << std::endl
              << std::endl;
    for (auto &pair : inputable)
    {
        std::cout << "\nEnter your " << pair.first << ": ";
        std::cin >> pair.second;
    }



    // std::ofstream file()

    return accounts::AccountHolder();
}