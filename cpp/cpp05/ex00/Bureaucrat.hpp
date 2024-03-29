#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);

		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void	upgrade();
		void	downgrade();
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
	
		const std::string name;
		int grade;
		Bureaucrat &		operator=( Bureaucrat const & rhs );
		Bureaucrat( Bureaucrat const & src );
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */