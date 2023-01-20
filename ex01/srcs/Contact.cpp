#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
    ;
}
Contact::~Contact(void)
{
    ;
}
void Contact::init(void)
{
    this->is_empty = true;
}

void Contact::set_first_name(string first_name)
{
    std::cout << "set first_name" << std::endl;
    std::cout << first_name << std::endl;
    this->first_name = first_name;
}

string Contact::get_first_name(void)
{
    return (this->first_name);
}

void Contact::set_last_name(string last_name)
{
    this->last_name = last_name;
}

string Contact::get_last_name(void)
{
    return (this->last_name);
}

void Contact::set_nickname(string nickname)
{
    this->nickname = nickname;
}

string Contact::get_nickname(void)
{
    return (this->nickname);
}

void Contact::set_phone_number(string phone_number)
{
    this->phone_number = phone_number;
}

string Contact::get_phone_number(void)
{
    return (this->phone_number);
}

void Contact::set_darkest_secret(string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

string Contact::get_darkest_secret(void)
{
    return (this->darkest_secret);
}

