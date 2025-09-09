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

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed res;
	res._num = this->_num + other._num;
	return Fixed(res);
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed res;
	res._num = this->_num - other._num;
	return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_num == other._num;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_num != other._num;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->_num > other._num;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_num < other._num;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_num >= other._num;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_num <= other._num;
}

Fixed& Fixed::operator++()
{
	this->_num += 1 << Fixed::_fractionalBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(this->toFloat());
	this->_num += 1 << Fixed::_fractionalBits;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->_num += 1 << Fixed::_fractionalBits;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(this->toFloat());
	this->_num += 1 << Fixed::_fractionalBits;
	return tmp;
}

float Fixed::toFloat() const {
	return this->_num / (float)(1 << Fixed::_fractionalBits);
}

int Fixed::toInt() const {
	return this->_num / pow(2, Fixed::_fractionalBits);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}
