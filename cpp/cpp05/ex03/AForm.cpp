#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : name("") , grade(150), exec_grade(0)
{
	this->sign = 0;
}

AForm::AForm( const AForm & src ) : name(src.name) ,grade(src.grade), exec_grade(src.exec_grade)
{
	this->sign = src.sign;
}

AForm::AForm(std::string name, int grade) : name(name), grade(grade), exec_grade(0)
{
	try
	{
		this->sign = 0;
		if (grade > 150)
			throw AForm::GradeTooLowException();
		else if ( grade < 1)
			throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	this->sign = rhs.sign;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	try
	{
		if (i.getGrade() > 150 || i.getGrade() < 1)
			throw AForm::GradeWrongException();
		o << "-------------------\n"
		<< "name : " << i.getName()
		<< "\nrequired grade : " << i.getGrade()
		<< "\nrequired exec_grade : " << i.getexec_Grade()
		<< "\nsign : ";
		if (i.getSign() == 1)
			o << "o\n";
		else
			o << "x\n";
		return o;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return o;
}

bool AForm::getSign() const 
{
	return (this->sign);
}

int	AForm::getGrade() const 
{
	return (this->grade);
}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getexec_Grade() const
{
	return (this->exec_grade);
}

void	AForm::beSigned(Bureaucrat src)
{
	try
	{
		if (this->grade > 150 || this->grade < 1)
			throw AForm::GradeWrongException();
		else if (src.getGrade() > this->grade)
			throw AForm::GradeFailException();
		this->sign = true;
		std::cout << src.getName() << " singed " << this->name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << src.getName() << " couldn’t sign " << this->name << " because " << e.what() << std::endl;
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (this->grade > 150 || this->grade < 1)
			throw AForm::GradeWrongException();
		else if (executor.getGrade() > this->exec_grade)
			throw AForm::GradeFailException();
		else if (this->sign != 1)
			throw AForm::GradeexecFailException();
		std::cout << executor.getName();
		this->exec();
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn’t execute " << this->name << " because " << e.what() << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("too high grade, check Form");
}

const char* AForm::GradeFailException::what() const throw()
{
	return ("you don't have permission");
}

const char* AForm::GradeexecFailException::what() const throw()
{
	return ("Form be not signed");
}

const char* AForm::GradeWrongException::what() const throw()
{	
	return ("wrong Form grade, check Form");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("too low grade, check Form");
}

void	AForm::setGrade(int a)
{
	int &ref = const_cast<int&>(this->grade);
	ref = a;
}

void	AForm::setGrade_exec(int a)
{
	int &ref = const_cast<int&>(this->exec_grade);
	ref = a;
}

void	AForm::setsign(bool a)
{
	this->sign = a;
}
void	AForm::setName(std::string name)
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