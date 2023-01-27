#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <iostream>
# include <string>
# include "Form.hpp"

class Form;
class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();


		std::string getName() const;
		int getGrade() const;
		void	signForm(Form &src);

		void	upgrade();
		void	downgrade();
		void	executeForm(Form const & form) const;
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
		Bureaucrat &		operator=( Bureaucrat const & rhs );
		Bureaucrat( Bureaucrat const & src );
		const std::string name;
		int grade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */