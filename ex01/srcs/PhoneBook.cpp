
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
    for(int i=0; i<MAX_CONTACT_SIZE; i++)
        this->contacts[i].init();
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
//void &operator=(Contact p, const Contact &q)
//{

//}
