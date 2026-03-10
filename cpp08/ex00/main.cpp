#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(-5);
    v.push_back(9);
    v.push_back(2);
    v.push_back(6);
    
    try {
        std::cout << "Value: " << *easyfind(v, 2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::vector<int> d;
    d.push_back(1);
    d.push_back(-5);
    d.push_back(9);
    d.push_back(2);
    d.push_back(6);
    
    
    try {
        std::cout << "Value: " << *easyfind(d, 11) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}