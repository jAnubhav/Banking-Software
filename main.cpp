#include "bin\inc\user.hpp"

#include <iostream>

int main()
{
    int choice;
    accounts::AccountHolder holder;

    while ((choice = initializer()) && choice % 3)
        holder = interactions.at(choice)();

    std::cout << "Quiting...";
    return 0;
}