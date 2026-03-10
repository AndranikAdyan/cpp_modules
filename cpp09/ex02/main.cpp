#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe program;
        program.run(argc, argv);
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
    }
}