#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
	AForm::setGrade(72);
	AForm::setGrade_exec(45);
	AForm::setName(target);
	AForm::setsign(0);
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	this->setsign(src.getSign());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->setsign(rhs.getSign());
	}
	return *this;
}

void	RobotomyRequestForm::exec() const
{
	std::cout << " executed RobotomyRequestForm" << std::endl;
	srand(time(NULL));
	try
	{
		if (rand() % 2 == 1)
			throw 	RobotomyRequestForm::GrademissException();
		std::cout << "drrrrrrrrrrrr" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

const char* RobotomyRequestForm::GrademissException::what() const throw()
{
	return ("fail");
}

// std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
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