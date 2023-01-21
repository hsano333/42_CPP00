#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

using std::string;

class Operator
{
    private:
        PhoneBook book;
        //std::string get_info();
        void process_add(Contact *contact);
        void process_search();
        bool is_not_empty(string str);
        bool is_only_number(string str);
        string get_info(string prompt, bool only_number);
    public:
        void operate();
        Operator(void);
        ~Operator(void);
};

#endif
