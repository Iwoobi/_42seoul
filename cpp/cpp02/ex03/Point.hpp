#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point( Point const & src );
		~Point();
		Point(float x, float y);
		float getValueX() const;
		float getValueY() const;

		Point &		operator=( Point const & rhs );
		Point 		operator-( Point const & rhs ) const;
		int		operator*( Point const & rhs ) const;

	private:

		Fixed x;
		Fixed y;

};

std::ostream &			operator<<( std::ostream & o, Point const & i );
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif /* *********************************************************** POINT_H */