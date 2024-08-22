#include "FormAlreadySignedException.hpp"

FormAlreadySignedException::FormAlreadySignedException() throw() {
}

FormAlreadySignedException::FormAlreadySignedException( const FormAlreadySignedException &copy ) throw() {
  ( void ) copy;
}

FormAlreadySignedException::~FormAlreadySignedException() throw() {
}

FormAlreadySignedException::FormAlreadySignedException( const std::string message ) throw() : _message( message ) {
}

FormAlreadySignedException &FormAlreadySignedException::operator=( const FormAlreadySignedException &assign ) {
  ( void ) assign;
  return *this;
}

const char *FormAlreadySignedException::what() const throw() {
  if ( _message.empty() )
    return "Form is already signed. No additional information specified";
  return _message.c_str();
}
