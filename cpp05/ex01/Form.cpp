#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "FormAlreadySignedException.hpp"

Form::Form() : _name( "default" ), _signed( false ), _gradeToSign( 150 ), _gradeToExecute( 150 ) {
}

Form::Form( const std::string name, int gradeToSign, int gradeToExecute ) :
    _name( name ),
	_signed( false ),
	_gradeToSign( gradeToSign ),
    _gradeToExecute( gradeToExecute ) {
  if ( gradeToSign < 1 || gradeToExecute < 1 )
    throw GradeTooHighException();
  else if ( gradeToSign > 150 || gradeToExecute > 150 )
    throw GradeTooLowException();
}

Form::Form( const Form &copy ) :
    _name( copy.getName() ),
	_signed( copy.isSigned() ),
	_gradeToSign( copy.getGradeToSign() ),
    _gradeToExecute( copy.getGradeToExecute() ) {
}

Form::~Form() {
}

Form &Form::operator=( const Form &assign ) {
  ( void ) assign;
  return *this;
}

const std::string &Form::getName() const {
  return _name;
}

bool Form::isSigned() const {
  return _signed;
}

int Form::getGradeToSign() const {
  return _gradeToSign;
}

int Form::getGradeToExecute() const {
  return _gradeToExecute;
}

void Form::beSigned( const Bureaucrat &bureaucrat ) {
  if ( bureaucrat.getGrade() > _gradeToSign )
	throw GradeTooLowException();
  else if ( _signed )
    throw FormAlreadySignedException();
  _signed = true;
}

std::ostream &operator<<( std::ostream &out, const Form &form ) {
  out << "Form " << form.getName() << " is " << ( form.isSigned() ? "" : "not " )
	  << "signed. Grade to sign: " << form.getGradeToSign()
	  << ". Grade to execute: " << form.getGradeToExecute();
  return out;
}
