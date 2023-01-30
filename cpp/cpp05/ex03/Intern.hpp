#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
class Intern
{

	public:

		Intern();
		AForm* makeForm(std::string form, std::string target);
		~Intern();
		class NotExistException : public std::exception
		{
			public:
			const char* what() const throw();
		};

	private:
		Intern( Intern const & src );
		Intern &		operator=( Intern const & rhs );
};

#endif /* ********************************************************** INTERN_H */