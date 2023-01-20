#ifndef PhoneBook_HPP
#define PhoneBook_HPP
#include "Contact.hpp"
#define MAX_CONTACT_SIZE 8

class PhoneBook{
    private:
        Contact contacts[MAX_CONTACT_SIZE];
        int cur_id;
    public:
        Contact *give_contact(void);
        void add(Contact contact);
        void search();
        void exit();
        PhoneBook(void);
        //void &operator=(Contact p, const Contact &q);
};

#endif
