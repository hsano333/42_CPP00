#include "Contact.hpp"
#include <iostream>
#include <string>

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

string Contact::get_phone_number(bool raw)
{
    if (raw)
        return (this->first_name);
    return (omit_word(this->phone_number));
}

bool Contact::set_darkest_secret(string darkest_secret)
{
    this->darkest_secret = darkest_secret;
    return (true);
}

string Contact::get_darkest_secret(bool raw)
{
    if (raw)
        return (this->first_name);
    return (this->darkest_secret);
}

int Contact::get_id(void)
{
    return (this->id + 1);
}

string Contact::omit_word(string str)
{
    std::string rep = ".";
    if (str.size() > DIPLAY_MAX)
        str.replace(DIPLAY_MAX - 1, 1, rep);
    return (str.substr(0, 10));
}

string Contact::get_first_name(bool raw)
{
    if (raw)
        return (this->first_name);
    return (omit_word(this->first_name));
}

bool Contact::set_last_name(string last_name)
{
    this->last_name = last_name;
    return (true);
}

string Contact::get_last_name(bool raw)
{
    if (raw)
        return (this->first_name);
    return (omit_word(this->last_name));
}

bool Contact::set_nickname(string nickname)
{
    this->nickname = nickname;
    return (true);
}

string Contact::get_nickname(bool raw)
{
    if (raw)
        return (this->first_name);
    return (omit_word(this->nickname));
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

