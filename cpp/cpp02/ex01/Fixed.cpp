#include "Fixed.hpp"
#include <cmath>
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->a = 0;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->a = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->a);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "Default constructor called" << std::endl;
	this->a = raw;
}

Fixed::Fixed(const int val)
{
	this->a = roundf(val * 256);
}

Fixed::Fixed(const float val)
{
	this->a = roundf(val * 256);
}

float Fixed::toFloat( void ) const
{
	float result;
	result = (float)this->a / 256;
	return (result);
}

int Fixed::toInt( void ) const
{
	return (this->a/256);
}

std::ostream& operator<<(std::ostream& os, const Fixed& val)
{
	os << val.toFloat();
	return (os);
}