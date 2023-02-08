#include "Span.hpp"
#include <numeric>
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
	this->n = 0;
}

Span::Span( const Span & src )
{
	this->n = src.getn();
	this->fill_n = src.getfilln();
	this->_data = src.getdata();
}

Span::Span( unsigned int n)
{
	this->n = n;
	this->fill_n = 0;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_data = rhs.getdata();
		this->n = rhs.getn();
		this->fill_n = rhs.getfilln();
	}
	return *this;
}

void Span::addNumber(int num)
{
	try
	{
		if (this->fill_n == this->n)
			throw  Span::error();
		this->_data.push_back(num);
		this->fill_n += 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char* Span::error::what() const throw()
{
	return ("too much element");
}

const char* Span::differror::what() const throw()
{
	return ("too little element");
}

int	Span::getn() const
{
	return (this->n);
}
int Span::getfilln() const
{
	return (this->fill_n);
}

int Span::shortestSpan()
{
	try
	{
		if (this->fill_n < 2)
			throw differror();
		std::vector<int> v(this->_data);
		std::adjacent_difference(v.begin(), v.end(), v.begin());
		std::vector<int>::iterator i;
		int val = abs(*v.begin());
		for (i = v.begin(); i != v.end(); i++)
		{
			if (val > abs(*i))
				val = abs(*i);
		}
		return (val);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
int Span::longestSpan()
{
	try
	{
		if (this->fill_n < 2)
			throw differror();
		return (*max_element(this->_data.begin(), this->_data.end())
		- *min_element(this->_data.begin(), this->_data.end()));
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

std::vector<int> Span::getdata() const
{
	return (this->_data);
}
// std::ostream &			operator<<( std::ostream & o, Span const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */