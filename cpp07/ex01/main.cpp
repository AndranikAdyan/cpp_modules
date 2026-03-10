#include "iter.hpp"

template <typename T>
void display(const T& x) {
    std::cout << "[" << x << "] ";
}


void addOne(int& x) {
    x += 1;
}


void subtractOne(int& x) {
    x -= 1;
}

int main() {
    std::string fruits[] = {"orange", "kiwi", "mango"};
    size_t fruitsLen = sizeof(fruits) / sizeof(fruits[0]);

    std::cout << "String array contents: ";
    iter(fruits, fruitsLen, display<std::string>);
    std::cout << std::endl << std::endl;

    int numbers[] = {10, 20, 30, 40};
    size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original int array: ";
    iter(numbers, numbersLen, display<int>);
    std::cout << std::endl;

    iter(numbers, numbersLen, addOne);
    std::cout << "After addOne:       ";
    iter(numbers, numbersLen, display<int>);
    std::cout << std::endl;

    iter(numbers, numbersLen, subtractOne);
    std::cout << "After subtractOne:  ";
    iter(numbers, numbersLen, display<int>);
    std::cout << std::endl << std::endl;

    double decimals[] = {3.14, 2.71, 1.61};
    size_t decimalsLen = sizeof(decimals) / sizeof(decimals[0]);

    std::cout << "Double array: ";
    iter(decimals, decimalsLen, display<double>);
    std::cout << std::endl;

    return 0;
}