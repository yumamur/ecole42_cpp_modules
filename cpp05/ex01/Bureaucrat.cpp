#include "Bureaucrat.hpp"

#include "Form.hpp"

#include <exception>

Bureaucrat::Bureaucrat() : _name( "default" ), _grade( 150 ) {
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name( name ) {
  if ( grade < 1 )
    throw GradeTooHighException();
  else if ( grade > 150 )
    throw GradeTooLowException();
  _grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ) : _name( copy._name ), _grade( copy._grade ) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &assign ) {
  if ( this == &assign )
    return *this;
  _grade = assign._grade;
  return *this;
}

const std::string &Bureaucrat::getName() const {
  return _name;
}

int Bureaucrat::getGrade() const {
  return _grade;
}

void Bureaucrat::incrementGrade() {
  if ( _grade == 1 )
    throw Bureaucrat::GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if ( _grade == 150 )
    throw Bureaucrat::GradeTooLowException();
  _grade++;
}

void Bureaucrat::signForm( Form &form ) {
  try {
    form.beSigned( *this );
    std::cout << _name << " signs " << form.getName() << std::endl;
  } catch ( std::exception &e ) {
    std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what()
              << std::endl;
  }
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat ) {
  out << "Bureaucrat " << bureaucrat.getName() << " has grade " << bureaucrat.getGrade();
  return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() : _msg( "" ) {
}

Bureaucrat::GradeTooHighException::GradeTooHighException( const std::string &msg ) throw() :
    _msg( msg ) {
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() : _msg( "" ) {
}

Bureaucrat::GradeTooLowException::GradeTooLowException( const std::string &msg ) throw() :
    _msg( msg ) {
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  if ( this->_msg.empty() )
    return "Grade is too high for a bureaucrat";
  return this->_msg.c_str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  if ( this->_msg.empty() )
    return "Grade is too low for a bureaucrat";
  return this->_msg.c_str();
}
