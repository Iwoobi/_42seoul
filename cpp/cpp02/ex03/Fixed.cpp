#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->a = 0;
}

Fixed::Fixed( const Fixed & src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}


Fixed &				Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->a = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->a);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "Default constructor called" << std::endl;
	this->a = raw;
}

Fixed::Fixed(const int val)
{
	this->a = val * 256;
}

Fixed::Fixed(const float val)
{
	this->a =roundf(val * 256);
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

bool Fixed::operator<(const Fixed& l) const
{
	if (l.a > this->a)
		return (1);
	return (0);
}
bool Fixed::operator>(const Fixed& l) const
{
	if (l.a < this->a)
		return (1);
	return (0);
}
bool Fixed::operator>=(const Fixed& l) const
{
	if (l.a <= this->a)
		return (1);
	return (0);
}
bool Fixed::operator<=(const Fixed& l) const
{
	if (this->a <= l.a)
		return (1);
	return (0);
}
bool Fixed::operator==(const Fixed& l) const
{
	if (l.a == this->a)
		return (1);
	return (0);
}
bool Fixed::operator!=(const Fixed& l) const
{
	if (l.a != this->a)
		return (1);
	return (0);
}
Fixed Fixed::operator+(const Fixed& l) const
{
	Fixed b;
	b.a = l.a + this->a;
	return (b);
}
Fixed Fixed::operator-(const Fixed& l) const
{
	Fixed b;
	b.a = this->a - l.a;
	return (b);
}
Fixed Fixed::operator*(const Fixed& l) const
{
	Fixed b;
	b.a = roundf((l.a * this->a)/256);
	return (b);
}

Fixed Fixed::operator/(const Fixed& l) const
{
	Fixed b;
	b.a = roundf(((float)this->a / (float)l.a) * 256);
	return (b);
}
Fixed Fixed::operator++(void)
{
	this->a += 1;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed	b(*this);
	
	this->a += 1;
	return (b);
}

const Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.a > b.a)
		return (a);
	return (b);
}
const Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.a > b.a)
		return (b);
	return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.a > b.a)
		return (a);
	return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.a > b.a)
		return (b);
	return (a);
}
