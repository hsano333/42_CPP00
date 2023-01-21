
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
    //this->p++;
    //if (this->p > MAX_CONTACT_SIZE)
        //this->p = 0;
    //if (typeid(this->contacts[this->p]) == typeid(Contact))
        //delete (this->contacts[this->p]);
    //this->contacts[this->p] = contact;
}

Contact *PhoneBook::give_contact(void)
{
    return (&(this->contacts[this->cur_id]));
}

void PhoneBook::add(Contact contact)
{
    this->cur_id++;
    if (this->cur_id > MAX_CONTACT_SIZE)
        this->cur_id = 0;
    this->contacts[this->cur_id] = contact;
}

void PhoneBook::search(void)
{
    std::cout << "search\n";
}

void PhoneBook::exit(void)
{
    std::cout << "exit\n";
}

void PhoneBook::display_all(void)
{
    if (cur_id == 0)
    {
        cout << "Book is empty!" << endl;
        return ;
    }
    cout << "+--+----------+----------+----------+" << endl;
    cout << "|id|first name| last name|  nickname|" << endl;
    cout << "+--+----------+----------+----------+" << endl;
    for(int i=0; i<MAX_CONTACT_SIZE; i++)
    {
        if (this->contacts[i].is_display())
        {
            Contact book = this->contacts[i];
            cout << "|" << setw(10) << book.get_first_name();
            cout << "|" ;
            cout << setw(10) << book.get_last_name();
            cout << "|" << book.get_nickname();
            cout << "|" << endl;
        }
    }
    cout << "+--+----------+----------+----------+" << std::endl;
}

void PhoneBook::increment_id(void)
{
	this->cur_id++;
}
//void &operator=(Contact p, const Contact &q)
//{

//}
