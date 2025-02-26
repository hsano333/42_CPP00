
#include "../include/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::setw;

PhoneBook::PhoneBook()
{
    for(int i=0; i<MAX_CONTACT_SIZE; i++)
        this->contacts[i].init(i);
    this->cur_id = 0;
    this->is_empty = true;
}

Contact *PhoneBook::give_contact(void)
{
    return (&(this->contacts[this->cur_id]));
}

bool PhoneBook::display_all(void)
{
    if (this->is_empty)
    {
        cout << "Book is empty!" << endl;
        return (false);
    }
    cout << "+--+----------+----------+----------+" << endl;
    cout << "|id|first name| last name|  nickname|" << endl;
    cout << "+--+----------+----------+----------+" << endl;
    for(int i=0; i<MAX_CONTACT_SIZE; i++)
    {
        if (this->contacts[i].is_display())
        {
            Contact book = this->contacts[i];
            cout << "|" << setw(2) << book.get_id();
            cout << "|" << setw(10) << book.get_first_name(false);
            cout << "|" << setw(10) << book.get_last_name(false);
            cout << "|" << setw(10) << book.get_nickname(false);
            cout << "|" << endl;
        }
    }
    cout << "+--+----------+----------+----------+" << std::endl;
    return (true);
}
bool PhoneBook::display_detail(int id)
{
    if (id <= 0 || id > 8)
        return (false);
    Contact book = this->contacts[id - 1];
    if (!book.is_display())
        return (false);
    cout << "id:" << book.get_id() << endl;
    cout << "first name:" << book.get_first_name(true) << endl;
    cout << "last name:" << book.get_last_name(true) << endl;
    cout << "nickname:" << book.get_nickname(true) << endl;
    cout << "phone number:" << book.get_phone_number(true) << endl;
    cout << "darkest secret:" << book.get_darkest_secret(true) << endl;
    cout << endl;
    return (true);
}

void PhoneBook::added(void)
{
    this->is_empty = false;
    this->cur_id++;
    if (this->cur_id >= MAX_CONTACT_SIZE)
        this->cur_id = 0;
}

int PhoneBook::get_max_valid_id(void)
{
    if (is_empty)
        return (0);
    for (int i = 0; i < MAX_CONTACT_SIZE; i++)
    {
        if (this->contacts[i].is_display() == false)
            return (i);
    }
    return (MAX_CONTACT_SIZE);
}
