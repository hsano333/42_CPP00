#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct ToUpper {
        char operator()(char c) { return toupper(c); }
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


    /*

    std::string last = std::string(argv[argc - 1]);
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

    std::string src =argv[1];

    std::string dst = src;



    std::transform(src.begin(), src.end(), dst.begin(), toupper);
    std::cout << dst;




        std::vector<int> vec;

            vec.push_back(3); vec.push_back(2); vec.push_back(6);

                vec.push_back(4); vec.push_back(1); vec.push_back(5);



                    std::sort(vec.begin(), vec.end());   // ソート
                                                         //
                                                         //
                                                         //
                                                         //     for (std::vector<int>::iterator it = vec.begin();
                                                         //
                                                         //             it != vec.end(); ++it)
                                                         //
                                                         //                     std::cout << *it << std::endl;  // 出力: 1, 2, 3, 4, 5, 6
                                                         //
                                                         //
                                                         //
                                                         //                         return 0;





    return (0);
}
