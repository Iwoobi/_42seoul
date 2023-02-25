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
	if (this->fill_n == this->n)
		throw  Span::error();
	std::vector<int>::iterator i = this->_data.begin();
	for (; i != this->_data.end(); i++)
	{
		if (*i == num)
			throw Span::sameerror();
	}

	this->_data.push_back(num);
	this->fill_n += 1;
}

const char* Span::error::what() const throw()
{
	return ("too much element");
}

const char* Span::differror::what() const throw()
{
	return ("too little element");
}

const char* Span::sameerror::what() const throw()
{
	return ("exist same element");
}

int	Span::getn() const
{
	return (this->n);
}
int Span::getfilln() const
{
	return (this->fill_n);
}

void Span::addmanyNumber(unsigned int num, int val)
{
	if (this->n < this->fill_n + num)
		throw error();
	for (unsigned int i = 0; i < num ; i++)
	{
		this->addNumber(val + i);
	} 
}

int Span::shortestSpan()
{
	if (this->fill_n < 2)
		throw differror();
	std::vector<int> v(this->_data);
	sort(v.begin(), v.end()); //애매

	std::vector<int>::iterator i;
	int val = *(v.begin() + 1) - *v.begin();
	for (i = v.begin(); i != v.end() - 1; i++)
	{
		if (val > (*(i + 1) - *i))
			val = (*(i + 1) - *i);
	}
	return (val);
}
int Span::longestSpan()
{
	if (this->fill_n < 2)
		throw differror();
	return (*max_element(this->_data.begin(), this->_data.end())
	- *min_element(this->_data.begin(), this->_data.end()));
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