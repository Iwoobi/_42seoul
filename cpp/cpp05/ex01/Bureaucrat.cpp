#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name("")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		this->grade = 150;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : name(src.name)
{
	this->grade = src.grade;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->grade = rhs.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << " bureaucrat grade " << i.getGrade();
	return o;
}


void	Bureaucrat::upgrade()
{
	try
	{
		if (this->grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade -= 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void	Bureaucrat::downgrade()
{
	try
	{
		if (this->grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade += 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{	
	return ("too high grade");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}


void	Bureaucrat::signForm(Form form)
{
	try
	{
		if (this->grade <= form.getGrade())
		{
			std::cout << this->name << " signed " << form.getName() << std::endl;
		}
		else
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
	
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */