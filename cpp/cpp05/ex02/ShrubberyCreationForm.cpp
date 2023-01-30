#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
{
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
	AForm::setGrade(145);
	AForm::setGrade_exec(137);
	AForm::setName(target);
	AForm::setsign(0);
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
	this->setsign(src.getSign());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->setsign(rhs.getSign());
	}
	return *this;
}

void	ShrubberyCreationForm::exec() const
{
	std::ofstream		write;
	std::cout << " executed ShrubberyCreationForm" << std::endl;
	write.open(AForm::getName() + "_shrubbery");
	if (!write.is_open())
	{
		std::cout << "file error" << std::endl;
		return ;
	}
	write << "    oxoxoo    ooxoo\n"
<<"  ooxoxo oo  oxoxooo\n"
<< " oooo xxoxoo ooo ooox\n"
<< " oxo o oxoxo  xoxxoxo\n"
<<  "  oxo xooxoooo o ooo\n"
<< "    ooo\\oo\\  /o/o\n"
<< "        \\  \\/ /\n"
<< "         |   /\n"
<< "         |  |\n"
<< "         | D|\n"
<< "         |  |\n"
<< "         |  |\n"
<< "  ______/____\\____"<< std::endl;
	write.close();
}

// std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
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