#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_number = 0;
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << '\n';

	this->_number = obj._number;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << '\n';

	if (this != &obj)
		this->_number = obj._number;
	return *this;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << '\n';
	int result = 1 << this->_fractional;

	this->_number = num * result;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << '\n';
	int result = 1 << this->_fractional;

	this->_number = roundf(num * result);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << '\n';
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << '\n';
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

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	return out << obj.toFloat();
}
