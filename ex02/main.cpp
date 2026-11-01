#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}


// void testComparisons(const Fixed &a, const Fixed &b)
// {
//     std::cout << "\na = " << a << " | b = " << b << std::endl;

//     std::cout << "a <  b: " << (a < b) << std::endl;
//     std::cout << "a >  b: " << (a > b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;
// }

// int main(void)
// {
//     std::cout << std::boolalpha;

//     std::cout << "\n=== Test 1: Different values ===" << std::endl;
//     Fixed a(10);
//     Fixed b(20);
//     testComparisons(a, b);

//     std::cout << "\n=== Test 2: Equal values ===" << std::endl;
//     Fixed c(10);
//     Fixed d(10);
//     testComparisons(c, d);

//     std::cout << "\n=== Test 3: Negative values ===" << std::endl;
//     Fixed e(-10);
//     Fixed f(5);
//     testComparisons(e, f);

//     std::cout << "\n=== Test 4: Same object ===" << std::endl;
//     testComparisons(a, a);

//     std::cout << "\n=== Test 5: Fractional values ===" << std::endl;
//     Fixed g(1.5f);
//     Fixed h(1.25f);
//     testComparisons(g, h);

// 	std::cout << "\n" << g.getRawBits() << "\n" << h.getRawBits() << '\n';

//     return 0;
// }
