#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		void exec() const;
	private:
		PresidentialPardonForm();
		std::string target;
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
};

// std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */