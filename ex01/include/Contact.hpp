
#ifndef Contact_HPP
#define Contact_HPP
#include <string>

using std::string;

class Contact {
    private:
        static const int DIPLAY_MAX = 10;
        int     id;
        string  first_name;
        string  last_name;
        string  nickname;
        string  phone_number;
        string  darkest_secret;
        bool    is_empty;
        string  omit_word(string str); 
    public:
        Contact();
        ~Contact(void);
        void    init(int id);
        void    end_input(void);
        int     get_id(void);
        bool    set_first_name(string first_name);
        string  get_first_name(bool);
        bool    set_last_name(string last_name);
        string  get_last_name(bool);
        bool    set_nickname(string nickname);
        string  get_nickname(bool);
        bool    set_phone_number(string phone_number);
        string  get_phone_number(bool);
        bool    set_darkest_secret(string darkest_secret);
        string  get_darkest_secret(bool);
        bool    is_display(void);
};

#endif
