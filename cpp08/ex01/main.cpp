#include "Span.hpp"


int main()
{
    try
    {
        std::cout << "=== Basic Test ===" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << std::endl << "=== Overflow Test ===" << std::endl;
        try
        {
            sp.addNumber(42);
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << std::endl << "=== Large Range Test (Vector) ===" << std::endl;
        Span bigSpan(10000);
        std::vector<int> vec;
        for (int i = 0; i < 10000; ++i)
            vec.push_back(rand() % 100000);

        bigSpan.addRange(vec.begin(), vec.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

        std::cout << std::endl << "=== Large Range Test (List) ===" << std::endl;
        Span listSpan(10000);
        std::list<int> lst;
        for (int i = 0; i < 10000; ++i)
            lst.push_back(rand() % 100000);

        listSpan.addRange(lst.begin(), lst.end());
        std::cout << "Shortest span: " << listSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << listSpan.longestSpan() << std::endl;

        std::cout << std::endl << "=== Exception Test (Not Enough Numbers) ===" << std::endl;
        Span emptySpan(5);
        try
        {
            emptySpan.shortestSpan();
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}