#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN rpn;
    int res;

    if (argc != 2) {
        std::cout << "Invalid arguments count" << std::endl;
        return 1;
    }

    try {
        res = rpn.solve(std::string(argv[1]));
        std::cout << res << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}