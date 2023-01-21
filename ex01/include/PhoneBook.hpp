#ifndef PhoneBook_HPP
#define PhoneBook_HPP
#include "Contact.hpp"
//#define MAX_CONTACT_SIZE 8

class PhoneBook{
    private:
        static const int MAX_CONTACT_SIZE = 8;
        Contact contacts[MAX_CONTACT_SIZE];
        int cur_id;
        bool is_empty;
    public:
        PhoneBook(void);
        Contact *give_contact(void);
        void display_all(void);
        void add(Contact contact);
        void search();
        void exit();
        void added(void);
        //void &operator=(Contact p, const Contact &q);
};

#endif
