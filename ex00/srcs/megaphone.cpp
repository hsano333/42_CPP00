//#include <string>
#include <iostream>
//#include <vector>
//#include <algorithm>

/*
struct ToUpper {
        char operator()(char c) { return toupper(c); }
};
*/
struct ToUpper {
    void operator()(char& c) { c= std::toupper((unsigned char)c);}
};

struct ToString {
        std::string operator()(char *c) { 
            std::string str(c);
            return (c); 
        }
};

int main(int argc, char **argv) {

    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << std::endl;
        return (0);
    }

    std::string str;
    for (int i = 1; i < argc; i++)
    {
        str = argv[i];
        for_each(str.begin(), str.end(), ToUpper());
        std::cout << str;
        //str = argc[i];
    }
	/*
    for (int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);
        std::transform(
                str.cbegin(),
                str.cend(),
                str.begin(),
                [](const char e) { return std::toupper(e) ; });
        std::cout << str;
    }
	*/
        //std::string str(argv[i]);



    //std::string last = std::string(argv[argc - 1]);
    /*
    std::transform(
                argv[1],
                &(argv[argc - 1][strlen(argv[argc - 1])]),
                argv[1],
                ToUpper() 
                );
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i];
    }
    std::cout << std::endl;
    */

    std::cout << std::endl;
    return (0);
}
