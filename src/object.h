#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string>

class Object
{
friend std::ostream& operator<< (std::ostream& os, const Object& obj);

private:
    std::string name;
    int quantity;
    std::string description;

public:
    Object();
    Object(std::string name);
    Object(std::string name, std::string description);
    ~Object() = default;
    std::string get_name() const;
    int get_quantity() const;
    std::string get_description() const;
    void add_one_quantity();
    void use();
    bool operator== (const Object obj);
    bool operator!= (const Object obj);
    bool operator> (const Object& obj);
};

#endif //_OBJECT_H_