
#ifndef Contact_HPP
#define Contact_HPP
#include <string>

using std::string;


class Contact {
    private:
        string first_name;
        string last_name;
        string nickname;
        string phone_number;
        string darkest_secret;
    public:
        void init(void);
        Contact();
        ~Contact(void);
        void set_first_name(string first_name);
        string get_first_name(void);
        void set_last_name(string last_name);
        string get_last_name(void);
        void set_nickname(string nickname);
        string get_nickname(void);
        void set_phone_number(string phone_number);
        string get_phone_number(void);
        void set_darkest_secret(string darkest_secret);
        string get_darkest_secret(void);
        bool is_empty;
};

#endif
