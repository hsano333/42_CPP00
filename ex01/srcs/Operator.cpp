#include <Operator.hpp>
#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::flush;

Operator::Operator()
{
    PhoneBook phone_book;
    this->book = phone_book;
}
Operator::~Operator(void)
{
    ;
}

bool Operator::is_not_empty(const string str)
{
    for(size_t i = 0; i < str.length(); i++)
        if (str[i] > 0x20)
            return (true);
    return (false);
}

bool Operator::is_only_number(const string str)
{
    for(size_t i = 0; i < str.length(); i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

string Operator::get_info(string prompt, bool only_number)
{
    string str;
    std::cout << prompt << ":" << flush;
    while (getline(cin, str))
    {
        if (is_not_empty(str))
        {
            if (!only_number || (only_number && is_only_number(str)))
                break ;
            else
                cout << "Enter only number." << endl;
        }
        else
            cout << "Enter something. No blanks." << endl;
        cout << prompt << ":";
    }
    return (str);
}

void Operator::process_add(Contact *contact)
{
    cout << "making new contact." << endl;
    contact->set_first_name(this->get_info("first name", false));
    contact->set_last_name(this->get_info("last name", false));
    contact->set_nickname(this->get_info("nickname", false));
    contact->set_phone_number(this->get_info("phone_number", true));
    contact->set_darkest_secret(this->get_info("darkest_secret", false));
    contact->end_input();
    this->book.added();
    cout << "Success. New contact is added!" << endl << endl;
}

void Operator::process_search()
{
    int id;
    string str_id;

    if (!this->book.display_all())
        return ;
    std::cout << "select contact:" << endl;
    while (1)
    {

        str_id = this->get_info("contact index", true);
        if (str_id.size() == 1)
        {
            id = str_id[0] - '0';
            if (this->book.display_detail(id))
                return ;
        }
        std::cout << "Error:enter only number 1 to " << this->book.get_max_valid_id() << endl;
    }
}

void Operator::operate(void)
{
    string str;

    cout << "Input command is only 'ADD', 'SEARCH', 'EXIT'" << endl;
    cout << "PhoneBook:" << flush;
    while (getline(cin, str))
    {
        if (str == "ADD")
            this->process_add((this->book.give_contact()));
        else if (str == "SEARCH")
            this->process_search();
        else if (str == "EXIT")
            break ;
        else
            cout << "Valid command is only 'ADD' , 'SEARCH' , 'EXIT'" << endl;
        cout << "PhoneBook:" << flush;
    }
    cout << "Exit" << endl;
}
