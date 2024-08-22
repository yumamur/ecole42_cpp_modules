#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException() throw() {
}

GradeTooLowException::GradeTooLowException( const GradeTooLowException &copy ) throw() {
  *this = copy;
}

GradeTooLowException::~GradeTooLowException() throw() {
}

GradeTooLowException &GradeTooLowException::operator=( const GradeTooLowException &assign ) {
  ( void ) assign;
  return *this;
}

GradeTooLowException::GradeTooLowException( const std::string message ) throw() : _message( message ) {
}

const char *GradeTooLowException::what() const throw() {
  if ( _message.empty() )
    return "Grade too low. No additional information specified";
  return _message.c_str();
}
