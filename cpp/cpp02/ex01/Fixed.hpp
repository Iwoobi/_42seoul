#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
class Fixed
{
	private:
		int a;
		const static int b = 8; 
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed( Fixed const & src );
		~Fixed();
		Fixed &		operator=( Fixed const & rhs );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& val);

#endif