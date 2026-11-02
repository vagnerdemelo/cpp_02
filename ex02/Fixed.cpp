#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_number = 0;
	// std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << '\n';

	this->_number = obj._number;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << '\n';
	int result = 1 << this->_fractional;

	this->_number = num * result;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << '\n';
	int result = 1 << this->_fractional;

	this->_number = roundf(num * result);
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Copy assignment operator called" << '\n';

	if (this != &obj)
		this->_number = obj._number;
	return *this;
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;

	result.setRawBits(this->_number + obj._number);
	return result;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result;

	result.setRawBits(this->_number - obj._number);
	return result;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result;
	long rawValue = static_cast<long>(this->_number) * obj._number;
	result.setRawBits(rawValue / (1 << this->_fractional));

	return result;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	float base = ((1 << this->_fractional) * 1.0f);
	Fixed result((this->_number / base) / (obj._number / base));
	return result;
}

Fixed Fixed::operator++()
{
	++this->_number;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(this->_number);
	
	return tmp;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << '\n';
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << '\n';
	return this->_number;
}

void Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

int Fixed::toInt(void) const
{
	return this->_number / (1 << this->_fractional);
}

float Fixed::toFloat(void) const
{
	return this->_number / ((1 << this->_fractional) * 1.0f);
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_number < other._number;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_number > other._number;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_number <= other._number;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_number >= other._number;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_number == other._number;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_number != other._number;
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	return out << obj.toFloat();
}
