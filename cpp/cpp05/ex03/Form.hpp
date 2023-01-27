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
		~Form();
		Form(std::string name, int grade);
		void	beSigned(Bureaucrat src);
		int getGrade() const;
		bool getSign() const;
		int getexec_Grade() const;
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
		class GradeFailException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class GradeexecFailException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		void 	execute(Bureaucrat const & executor) const;
		virtual  void	exec() const = 0;
		void	setGrade(int a);
		void	setGrade_exec(int a);
		void	setsign(bool a);
		void	setName(std::string name);
	private:
		bool				sign;
		const std::string	name;
		const int			grade;
		const int			exec_grade;
		Form &		operator=( Form const & rhs );
		Form( Form const & src );
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */