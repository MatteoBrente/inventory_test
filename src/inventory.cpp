#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "inventory.h"
#include "object.h"

//CONSTRUCTORS & DESTRUCTORS

Inventory::Inventory() {current_obj_it = inventory_array.end();}

Inventory::~Inventory() {}

//PRIVATE FUNCTIONS

void Inventory::obj_selection_switch(char c)
{
    switch (c)
    {
    case 'U':
        use_current_object();
        break;
    case 'B':
        break;
    default:
        std::cout << "Selection not valid, try again" << std::endl;
        break;
    }
}

void Inventory::print_selected_object()
{
    if (current_obj_it != inventory_array.end())
    {
        std::cout << *current_obj_it;
        std::cout << "Press U if you want to use this object" << std::endl
        << "Press B if you want to go back to the inventory" << std::endl
        << "Enter your selection: ";
        char selection{};
        
        do {
            std::cin.sync();
            std::cin >> selection;
            selection = toupper(selection);
            obj_selection_switch(selection);
        } while (selection != 'B' && selection != 'U');
    }
    else
        std::cerr << "Couldn't find object with said name in inventory" << std::endl;
}

void Inventory::use_current_object()
{
        //Use the current object, then delete it if its quantity is less than 1
        current_obj_it->use();

        if (current_obj_it->get_quantity() < 1)
        {
            *current_obj_it = Object{};
            rearrange_inventory();
            current_obj_it = inventory_array.end();
        }
}

void Inventory::create_new_object(std::string obj_name)
{
    std::string description {};
    std::cout << "Enter the description of the object: ";
    std::cin.sync();
    std::getline(std::cin, description);

    current_obj_it = std::find(inventory_array.begin(), inventory_array.end(), Object{"EMPTY"});
    if (current_obj_it != inventory_array.end())
        *current_obj_it = Object {obj_name, description};
    else
        std::cout << "Your inventory is full!";
}

//PUBLIC FUNCTIONS

void Inventory::rearrange_inventory()
{
    //Rearrange the inventory, moving all non-empty objects at the its start
    while (*(current_obj_it+1) != Object{})
    {
        *current_obj_it = *(current_obj_it+1);
        *(current_obj_it+1) = Object{};
        current_obj_it++;
    }
}

void Inventory::select_object()
{
    std::string name_to_find{};
    std::cout << "Enter the name of the object you want to select: ";
    std::cin.sync();
    std::getline (std::cin, name_to_find);
    std::transform(name_to_find.begin(), name_to_find.end(),name_to_find.begin(), ::toupper);

    if (name_to_find == "EMPTY")
        std::cout << "You can't select an empty object!" << std::endl;
    else
    {
        current_obj_it = std::find(inventory_array.begin(), inventory_array.end(), Object {name_to_find});
        print_selected_object();
    }
}

void Inventory::add_object()
{
    std::string name{};

    std::cout << "Enter the name of the object (15 characters max): ";
    std::cin.sync();
    std::getline(std::cin, name);
    if (name.length() > 15)
    {
        std::cout << "Name too long, needs to be 15 characters max!" << std::endl;
        return;
    }
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    current_obj_it = std::find(inventory_array.begin(), inventory_array.end(), Object {name});

    if (current_obj_it != inventory_array.end())
        current_obj_it->add_one_quantity();
    else
        create_new_object(name);
}

//FRIEND FUNCTIONS

std::ostream& operator<<(std::ostream& os, const Inventory& inv)
{
    for (size_t i {0}; i<9; i++)
    {
        if ((i+1)%3 == 1)
            std::cout << std::left << std::setw(15) << inv.inventory_array[i].get_name() << " ";
        else
            std::cout << std::setw(15) << inv.inventory_array[i].get_name() << " ";
        if ((i+1)%3 == 0)
            std::cout << std::endl;
    }
    return os;
}