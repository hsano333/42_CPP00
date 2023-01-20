#include <Operator.hpp>
#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

bool Operator::is_not_empty(const string str)
{
    for(size_t i = 0; i < str.length(); i++)
        if (str[i] > 0x20)
            return (true);
    return (false);
}

string Operator::get_info(string prompt)
{
    string str;
    std::cout << prompt << ":";
    std::cout << "test No.1\n";
    while (getline(cin, str))
    {
        if (is_not_empty(str))
            break ;
        cout << "Enter something. No blanks." << endl;
        cout << prompt << ":";
    }
    std::cout << "test No.2:" << str << endl;
    return (str);
}

void Operator::process_add(Contact *contact)
{
    /*
    std::cout << "test first No.1\n";
    std::cout << this->get_info("first name");
    std::cout << "test first No.3\n";
    std::cout << contact->is_empty;
    std::cout << "test first No.4\n";
    std::cout << contact->get_first_name();



    contact->set_first_name("test");
    //contact->set_first_name(this->get_info("first name"));
    //std::cout << contact.get_first_name();
    //string str("test");
    //contact.set_first_name(str);
    //contact.set_last_name("str");
    */
    contact->set_first_name(this->get_info("first name"));
    contact->set_last_name(this->get_info("last name"));
    contact->set_nickname(this->get_info("nickname"));
    contact->set_phone_number(this->get_info("phone_number"));
    contact->set_darkest_secret(this->get_info("darkest_secret"));
}

void Operator::process_search(void)
{
    std::cout << "search process\n";
}

void Operator::operate(void)
{
    string str;
    PhoneBook phone_book;

    while (getline(cin, str))
    {
        if (str == "ADD")
            this->process_add((phone_book.give_contact()));
        else if (str == "SEARCH")
            this->process_search();
        else if (str == "EXIT")
            break ;
    }
}
