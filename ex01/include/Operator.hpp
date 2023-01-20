#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include <string>
#include "Contact.hpp"

using std::string;

class Operator
{
    private:
        //std::string get_info();
        void process_add(Contact *contact);
        void process_search();
        bool is_not_empty(string str);
        string get_info(string prompt);
    public:
        void operate();
};

#endif
