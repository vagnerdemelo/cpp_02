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
	Fixed(const int num);
	Fixed(const float num);
	Fixed& operator= (const Fixed& obj);
	Fixed operator+ (const Fixed& obj) const;
	Fixed operator- (const Fixed& obj) const;
	Fixed operator* (const Fixed& obj) const;
	Fixed operator/ (const Fixed& obj) const;
	Fixed operator++ ();
	Fixed operator++ (int);
	Fixed operator-- ();
	Fixed operator-- (int);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw);
	int toInt( void ) const;
	float toFloat( void ) const;
	bool operator< (const Fixed& other) const;
	bool operator> (const Fixed& other) const;
	bool operator<= (const Fixed& other) const;
	bool operator>= (const Fixed& other) const;
	bool operator== (const Fixed& other) const;
	bool operator!= (const Fixed& other) const;
};

std::ostream& operator<< (std::ostream& out, const Fixed& obj);

#endif
