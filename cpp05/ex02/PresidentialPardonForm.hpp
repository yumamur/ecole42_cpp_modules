#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
	const std::string _target;

  public:
	PresidentialPardonForm();
	PresidentialPardonForm( const std::string target );
	PresidentialPardonForm( const PresidentialPardonForm &copy );
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=( const PresidentialPardonForm &assign );

	void execute( const Bureaucrat &executor ) const;
};

#endif