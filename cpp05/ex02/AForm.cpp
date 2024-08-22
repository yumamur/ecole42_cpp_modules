#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "FormAlreadySignedException.hpp"

AForm::AForm() : _name( "default" ), _signed( false ), _gradeToSign( 150 ), _gradeToExecute( 150 ) {
}

AForm::AForm( const std::string name, int gradeToSign, int gradeToExecute ) :
    _name( name ),
	_signed( false ),
	_gradeToSign( gradeToSign ),
    _gradeToExecute( gradeToExecute ) {
  if ( gradeToSign < 1 || gradeToExecute < 1 )
    throw GradeTooHighException();
  else if ( gradeToSign > 150 || gradeToExecute > 150 )
    throw GradeTooLowException();
}

AForm::AForm( const AForm &copy ) :
    _name( copy.getName() ),
	_signed( copy.isSigned() ),
	_gradeToSign( copy.getGradeToSign() ),
    _gradeToExecute( copy.getGradeToExecute() ) {
}

AForm::~AForm() {
}

AForm &AForm::operator=( const AForm &assign ) {
  ( void ) assign;
  return *this;
}

const std::string &AForm::getName() const {
  return _name;
}

bool AForm::isSigned() const {
  return _signed;
}

int AForm::getGradeToSign() const {
  return _gradeToSign;
}

int AForm::getGradeToExecute() const {
  return _gradeToExecute;
}

void AForm::beSigned( const Bureaucrat &bureaucrat ) {
  if ( bureaucrat.getGrade() > _gradeToSign )
	throw GradeTooLowException("asd");
  else if ( _signed )
    throw FormAlreadySignedException();
  _signed = true;
}

std::ostream &operator<<( std::ostream &out, const AForm &form ) {
  out << "AForm " << form.getName() << " is " << ( form.isSigned() ? "" : "not " )
	  << "signed. Grade to sign: " << form.getGradeToSign()
	  << ". Grade to execute: " << form.getGradeToExecute();
  return out;
}
