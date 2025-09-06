#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_num = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->_num = num << Fixed::_fractionalBits;
}

Fixed::Fixed(const float fnum) {
	std::cout << "Float constructor called" << std::endl;
	this->_num = (int)roundf(fnum  * (1 << Fixed::_fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_num = other._num;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_num = raw;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_num;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_num = other._num;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return out;
}


float Fixed::toFloat() const {
	return this->_num / (float)(1 << Fixed::_fractionalBits);
}

int Fixed::toInt() const {
	return this->_num / pow(2, Fixed::_fractionalBits);
}