#include <iostream>
#include <string>
#include "object.h"

Object::Object()
    :name("EMPTY"), quantity (0), description ("No Description") {}

Object::Object(std::string name)
    :name(name), quantity (1), description ("None") {}

Object::Object(std::string name, std::string description)
    :name(name), quantity (1), description (description) {}

void Object::add_one_quantity() 
{
    quantity++;
    std::cout << "Added one " << name << " to the inventory" << std::endl;
}

std::string Object::get_name() const {return name;}

int Object::get_quantity() const {return quantity;}

std::string Object::get_description() const {return description;}

bool Object::operator== (const Object obj)
{
    return (this->get_name() == obj.get_name());
}

bool Object::operator!= (const Object obj)
{
    return (this-> get_name() != obj.get_name());
}

void Object::use()
{
    if (quantity > 0)
        quantity--;
    else
        std::cerr << "Can't remove object, quantity less than one\n";
}

std::ostream& operator<< (std::ostream& os, const Object& obj)
{
    os << "Object: " << obj.get_name()
    << "\nQuantity: " << obj.get_quantity()
    << "\nDescription: " << obj.get_description()
    << "\n========================================" << std::endl;

    return os;
}