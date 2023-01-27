#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name("") , grade(150), exec_grade(0)
{
	this->sign = 0;
}

Form::Form( const Form & src ) : name(src.name) ,grade(src.grade), exec_grade(src.exec_grade)
{
	this->sign = src.sign;
}

Form::Form(std::string name, int grade) : name(name), grade(grade), exec_grade(0)
{
	try
	{
		this->sign = 0;
		if (grade > 150)
			throw Form::GradeTooLowException();
		else if ( grade < 1)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
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
	<< "target : " << i.getName()
	<< "\nrequired grade : " << i.getGrade()
	<< "\nrequired exec grade : " << i.getexec_Grade()
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

int Form::getexec_Grade() const
{
	return (this->exec_grade);
}

void	Form::beSigned(Bureaucrat src)
{
	try
	{
		if (this->grade > 150 || this->grade < 1)
			throw Form::GradeWrongException();
		else if (src.getGrade() > this->grade)
			throw Form::GradeFailException();
		this->sign = true;
		std::cout << src.getName() << " singed " << this->name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << src.getName() << " couldn’t sign " << this->name << " because " << e.what() << std::endl;
	}
}

void	Form::execute(Bureaucrat const & executor) const
{
	try
	{
		if (this->grade > 150 || this->grade < 1)
			throw Form::GradeWrongException();
		else if (executor.getGrade() > this->grade)
			throw Form::GradeFailException();
		else if (this->sign != 1)
			throw Form::GradeexecFailException();
		std::cout << executor.getName();
		this->exec();
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn’t execute " << this->name << " because " << e.what() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("too high grade, check Form");
}

const char* Form::GradeFailException::what() const throw()
{
	return ("you don't have permission");
}

const char* Form::GradeexecFailException::what() const throw()
{
	return ("Form be not signed");
}

const char* Form::GradeWrongException::what() const throw()
{	
	return ("wrong Form grade, check Form");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("too low grade, check Form");
}

void	Form::setGrade(int a)
{
	int &ref = const_cast<int&>(this->grade);
	ref = a;
}

void	Form::setGrade_exec(int a)
{
	int &ref = const_cast<int&>(this->exec_grade);
	ref = a;
}

void	Form::setsign(bool a)
{
	this->sign = a;
}
void	Form::setName(std::string name)
{
	std::string &ref = const_cast<std::string&>(this->name);
	ref = name;
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */