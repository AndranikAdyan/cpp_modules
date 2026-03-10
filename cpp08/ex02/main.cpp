#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Basic MutantStack Test ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nIterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n=== Compare with std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating through std::list:" << std::endl;
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << std::endl;

    std::cout << "\n=== Edge Case Tests ===" << std::endl;

    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
    if (emptyStack.begin() == emptyStack.end())
        std::cout << "Empty stack iterator test passed." << std::endl;

    MutantStack<int> oneStack;
    oneStack.push(42);
    std::cout << "Single element: " << *oneStack.begin() << std::endl;
    if (++oneStack.begin() == oneStack.end())
        std::cout << "Single element iterator test passed." << std::endl;

    return 0;
}
