#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <string>

Bureaucrat::Bureaucrat() : _name( "default" ), _grade( 150 ) {
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name( name ) {
  if ( grade < 1 )
    throw GradeTooHighException();
  else if ( grade > 150 )
    throw GradeTooLowException();
  _grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ) :
    _name( copy._name ), _grade( copy._grade ) {
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
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if ( _grade == 150 )
    throw GradeTooLowException("asd");
  _grade++;
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat ) {
  out << "Bureaucrat " << bureaucrat.getName() << " has grade "
      << bureaucrat.getGrade();
  return out;
}
