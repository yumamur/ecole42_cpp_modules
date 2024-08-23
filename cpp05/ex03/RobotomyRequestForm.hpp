#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
	const std::string _target;

  public:
	RobotomyRequestForm();
	RobotomyRequestForm( const std::string target );
	RobotomyRequestForm( const RobotomyRequestForm &copy );
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=( const RobotomyRequestForm &assign );

	virtual void execute( const class Bureaucrat &executor );
};

#endif
