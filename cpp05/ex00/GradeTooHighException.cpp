#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException() throw() {
}

GradeTooHighException::GradeTooHighException( const GradeTooHighException &copy ) throw() {
  *this = copy;
}

GradeTooHighException::~GradeTooHighException() throw() {
}

GradeTooHighException::GradeTooHighException( const std::string message ) throw() : _message( message ) {
}

GradeTooHighException &GradeTooHighException::operator=( const GradeTooHighException &assign ) {
  ( void ) assign;
  return *this;
}

const char *GradeTooHighException::what() const throw() {
  if ( _message.empty() )
    return "Grade too high. No additional information specified";
  return _message.c_str();
}
