#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point( const Point & src )
{
	this->x = src.x;
	this->y = src.y;
}


Point::~Point()
{

}

Point&				Point::operator=( const Point & rhs )
{
	if ( this != &rhs )
	{
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return (*this);
}

float Point::getValueX() const
{
	return(this->x.toFloat());
}
float Point::getValueY() const
{
	return(this->y.toFloat());
}

std::ostream &			operator<<( std::ostream & o, const Point & i )
{
	o << "x : " << i.getValueX() << "  y : " << i.getValueY();
	return o;
}

Point::Point(float x, float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point 		Point::operator-( Point const & rhs ) const
{
	Point tmp;
	tmp.x = this->x - rhs.x;
	tmp.y = this->y - rhs.y;
	return (tmp);
}
int		Point::operator*( Point const & rhs )	const
{
	if (this->x * rhs.y - this->y * rhs.x == 0)
		return (0);
	else if(this->x * rhs.y - this->y * rhs.x > 0)
		return (1);
	return (-1);
}

/* ************************************************************************** */