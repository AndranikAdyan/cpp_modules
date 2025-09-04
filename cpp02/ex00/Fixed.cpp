#include "Fixed.hpp"

Fixed::Fixed() {
	this->num = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(Fixed& other) {
	other.num = this->num;
}