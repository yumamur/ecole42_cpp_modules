#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  private:
	const std::string _target;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( const std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm &copy );
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &assign );

	virtual void execute( const class Bureaucrat &executor );
};

#endif
