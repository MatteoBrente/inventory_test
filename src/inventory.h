#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include <iostream>
#include <string>
#include <array>
#include <memory>
#include "object.h"

class Inventory
{
friend std::ostream& operator<<(std::ostream& os, const Inventory& inv);

private:
    std::array<Object, 9> inventory_array;
    std::array<Object, 9>::iterator current_obj_it;

    void obj_selection_switch(char c);
    void print_selected_object();
    void use_current_object();
    void rearrange_inventory();
    void create_new_object(std::string obj_name);

public:
    Inventory();
    void select_object();
    void add_object();
};
#endif //_INVENTORY_H_