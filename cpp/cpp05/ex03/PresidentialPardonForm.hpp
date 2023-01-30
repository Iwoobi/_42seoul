#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
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


#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */