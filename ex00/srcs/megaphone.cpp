#include <string>
#include <iostream>

int main(int argc, char **argv) {

    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
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
    std::cout << "\n";
    return (0);
}
