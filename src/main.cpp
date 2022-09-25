#include <iostream>
#include <string>
#include "inventory.h"

void print_menu(Inventory& inv);
void menu_switch(Inventory& inv, char c);
char read_value(std::string str);

int main ()
{
    char selection{};
    Inventory user_inventory;

    do
    {
        print_menu(user_inventory);
        std::cin.sync();
        std::cin >> selection;
        std::cout << "-----------------------------------------" << std::endl;
        selection = toupper(selection);
        menu_switch(user_inventory, selection);
    } while (selection != 'Q');

    return 0;
}

void print_menu (Inventory& inv)
{
    std::cout << "============== INVENTORY ==============" << std::endl;
    std::cout << inv;
    std::cout << "=======================================" << std::endl
    << "Press S to select an object" << std::endl
    << "Press A to add an object" << std::endl
    << "Press Q to quit" << std::endl
    << "ENTER YOUR SELECTION: ";
}

void menu_switch (Inventory& inv, char c)
{
    std::cin.ignore(1, '\n');
    switch (c)
    {
        case 'S':
            inv.select_object();
            break;
        case 'A':
            inv.add_object();
            break;
        case 'Q':
            break;
        default:
            std::cout << "Selection not valid, try again" << std::endl;
            break;
    }
}