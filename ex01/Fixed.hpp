#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _number;
	static const int _fractional = 8;
public:
	Fixed();
	Fixed(const Fixed& obj);
	Fixed& operator= (const Fixed& obj);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw);
	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream& operator<< (std::ostream& out, const Fixed& obj);
#endif
