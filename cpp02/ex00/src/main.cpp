#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << "---------- Before setRawBits: ----------" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	a.setRawBits(42);
	b.setRawBits(42);
	c.setRawBits(42);

	std::cout << std::endl << "---------- After setRawBits: ----------" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
