#include "RobotomyRequestForm.hpp"

#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"

#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() {
	throw std::invalid_argument( "RobotomyRequestForm: default constructor is not allowed" );
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) :
	AForm( "Robotomy Request Form", 72, 45 ), _target( target ) {
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) :
	AForm( copy ), _target( copy._target ) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &assign ) {
	if ( this != &assign ) {
		AForm::operator=( assign );
	}
	return *this;
}

void RobotomyRequestForm::execute( const Bureaucrat &executor ) const {
	if ( getGradeToExecute() < executor.getGrade() )
		throw GradeTooLowException();
	std::cout << "Drilling noises" << std::endl;
	if ( rand() % 2 )
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}