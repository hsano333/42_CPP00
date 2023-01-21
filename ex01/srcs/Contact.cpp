#include "Contact.hpp"
#include <iostream>

using std::string;

Contact::Contact()
{
    ;
}
Contact::~Contact(void)
{
    ;
}
void Contact::init(int id)
{
    this->is_empty = true;
    this->id = id;
}

bool Contact::set_first_name(string first_name)
{
    std::cout << "set first_name" << std::endl;
    std::cout << first_name << std::endl;
    this->first_name = first_name;
    return (true);
}

string Contact::get_phone_number(void)
{
    return (this->phone_number);
}

bool Contact::set_darkest_secret(string darkest_secret)
{
    this->darkest_secret = darkest_secret;
    return (true);
}

string Contact::get_darkest_secret(void)
{
    return (this->darkest_secret);
}


string Contact::get_first_name(void)
{
    return (this->first_name);
}

bool Contact::set_last_name(string last_name)
{
    this->last_name = last_name;
    return (true);
}

string Contact::get_last_name(void)
{
    return (this->last_name);
}

bool Contact::set_nickname(string nickname)
{
    this->nickname = nickname;
    return (true);
}

string Contact::get_nickname(void)
{
    return (this->nickname);
}

bool Contact::set_phone_number(string phone_number)
{
    for(size_t i = 0; i < phone_number.length(); i++)
        if (phone_number[i] > 0x20)
            return (false);
    this->phone_number = phone_number;
    return (true);
}

void Contact::end_input(void)
{
    this->is_empty = false;
}

bool Contact::is_display(void)
{
    return (!this->is_empty);
}

