#include "Fixed.hpp"
#include <iostream>

// int main( void )
// {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;

// return 0;
// }

int main(void) {

	Fixed a(42.42f);
	Fixed b(21.21f);
	Fixed c;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	
	std::cout << "----------------------------------" << std::endl;

	// test operator+
	c = a + b;
	std::cout << "a + b = " << c << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator-
	c = a - b;
	std::cout << "a - b = " << c << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator*
	c = a * b;
	std::cout << "a * b = " << c << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator/
	c = a / b;
	std::cout << "a / b = " << c << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator>   1 if a >, 0 if b >
	bool gt = (a > b);
	std::cout << "a > b ? " << gt << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator>=
	bool gte = (a >= b);
	std::cout << "a >= b ? " << gte << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator<
	bool lt = (a < b);
	std::cout << "a < b ? " << lt << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator<=
	bool lte = (a <= b);
	std::cout << "a <= b ? " << lte << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator==
	bool eq = (a == b);
	std::cout << "a == b ? " << eq << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator!=
	bool neq = (a != b);
	std::cout << "a != b ? " << neq << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator++
	std::cout << "a pre-increment: " << a << std::endl;
	std::cout << "a after pre-increment: " << ++a << std::endl;
	std::cout << "a post-increment: " << a++ << std::endl;
	std::cout << "a after post-increment: " << a << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test operator--
	std::cout << "b pre-decrement: " << b << std::endl;
	std::cout << "b after pre-decrement: " << --b << std::endl;
	std::cout << "b post-decrement: " << b-- << std::endl;
	std::cout << "b after post-decrement: " << b << std::endl;
	std::cout << "----------------------------------" << std::endl;

	// test min e max
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	return 0;
}
