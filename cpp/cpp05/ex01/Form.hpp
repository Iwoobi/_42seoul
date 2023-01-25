#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{

	public:

		Form();
		Form( Form const & src );
		~Form();
		Form(std::string name, int grade);
		void	beSigned(Bureaucrat src);
		int getGrade() const;
		bool getSign() const;
		std::string getName() const;
		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const throw();	
		};
		class GradeWrongException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const throw();
		};
	private:
		bool	sign;
		const std::string name;
		const int		grade;
		Form &		operator=( Form const & rhs );
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */