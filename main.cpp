#include "bin/inc/user.hpp"

#include <iostream>

int main()
{
    int choice;
    accounts::AccountHolder holder;

    while ((choice = initialize()) and (choice % 3))
        holder = interactions.at(choice - 1)();

    std::cout << "Quiting...";
    return 0;
}