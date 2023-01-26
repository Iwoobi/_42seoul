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
		this->grade = -1;
		std::cerr << e.what() << ", check " << this->name << std::endl;
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
	try
	{
		if (i.getGrade() == -1)
			throw Bureaucrat::GradeWrongException();
		o << i.getName() << " bureaucrat grade " << i.getGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ", check " << i.getName() << std::endl;
	}
	return o;
}


void	Bureaucrat::upgrade()
{
	try
	{
		if (this->grade == 1)
			throw Bureaucrat::GradeTooHighException();
		else if (this->grade == -1)
			throw Bureaucrat::GradeWrongException();
		this->grade -= 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ", check " << this->name << std::endl;
	}
}
void	Bureaucrat::downgrade()
{
	try
	{
		if (this->grade == 150)
			throw Bureaucrat::GradeTooLowException();
		else if (this->grade == -1)
			throw Bureaucrat::GradeWrongException();
		this->grade += 1;
	}
	catch(const std::exception& e)

	{
		std::cerr << e.what() << ", check " << this->name << std::endl;
	}
}

void	Bureaucrat::signForm(Form &src)
{
	try
	{
		if (this->grade > 150 || this->grade < 1)
			throw Bureaucrat::GradeWrongException();
		src.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " , check Bureaucrat" <<std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{	
	return ("too high grade");
}

const char* Bureaucrat::GradeWrongException::what() const throw()
{	
	return ("Wrong grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */