#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(5.5f);
	Fixed b(2.5f);

	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}