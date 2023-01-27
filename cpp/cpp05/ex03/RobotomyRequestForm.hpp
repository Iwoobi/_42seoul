#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		void exec() const;
		class GrademissException : public std::exception
		{
			public:
			const char* what() const throw();
		};

	private:
	RobotomyRequestForm( RobotomyRequestForm const & src );
	RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

};

// std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */