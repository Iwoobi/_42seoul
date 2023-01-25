#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name("") , grade(150)
{
	this->sign = 0;
}

Form::Form( const Form & src ) : name(src.name) ,grade(src.grade)
{
	this->sign = src.sign;
}

Form::Form(std::string name, int grade) : name(name), grade(grade)
{
	try
	{
		this->sign = 0;
		if (grade > 150)
			throw Form::GradeTooLowException();
		else if (grade < 1)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		int &ref = const_cast<int&>(this->grade);
		ref = -1;
		std::cerr << e.what() << std::endl;
		std::cout << this->grade << std::endl;
	}
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	this->sign = rhs.sign;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "-------------------\n"
	<< "name : " << i.getName()
	<< "\nrequired grade : " << i.getGrade()
	<< "\nsign : ";
	if (i.getSign() == 1)
		o << "o\n";
	else
		o << "x\n";
	return o;
}

bool Form::getSign() const 
{
	return (this->sign);
}

int	Form::getGrade() const 
{
	return (this->grade);
}

std::string Form::getName() const
{
	return (this->name);
}

void	Form::beSigned(Bureaucrat src)
{
	try
	{
		// src.signForm(*this);
		if (src.getGrade() == -1)
			throw Form::GradeWrongException();
		if (src.getGrade() > this->grade)
			throw Form::GradeTooLowException();
		this->sign = 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("too high grade, check Form");
}

const char* Form::GradeWrongException::what() const throw()
{	
	return ("wrong grade, check Form");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("too low grade, check Form");
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */