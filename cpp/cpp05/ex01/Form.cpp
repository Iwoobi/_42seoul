#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : grade(150), name("")
{
	this->sign = 0;
}

Form::Form( const Form & src ) : grade(src.grade), name(src.name)
{
	this->sign = src.sign;
}

Form::Form(std::string name, int grade) : grade(grade), name(name)
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
		std::cerr << e.what() << '\n';
		const_cast<int&>(this->grade) = 150;
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
	o << "-------------------"
	<< "name : " << i.getName()
	<< "\nrequired grade : " << i.getGrade()
	<< "\nsign : ";
	if (i.getSign() == 1)
		o << "sign : o\n";
	else
		o << ":sign : x\n";
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
		src.signForm(*this);
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
	return ("too high grade, Form\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("too low grade, Form\n");
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */