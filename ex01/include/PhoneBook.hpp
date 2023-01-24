#ifndef PhoneBook_HPP
#define PhoneBook_HPP
#include "Contact.hpp"
//#define MAX_CONTACT_SIZE 8

class PhoneBook{
    private:
        static const int MAX_CONTACT_SIZE = 8;
        Contact contacts[MAX_CONTACT_SIZE];
        size_t cur_id;
        bool is_empty;
    public:
        PhoneBook(void);
        Contact *give_contact(void);
        bool display_all(void);
        bool display_detail(int id);
        void added(void);
        int get_max_valid_id(void);
        //void &operator=(Contact p, const Contact &q);
};

#endif
