#ifndef FORM_ALREADY_SIGNED_EXCEPTION_HPP
#define FORM_ALREADY_SIGNED_EXCEPTION_HPP

#include <exception>
#include <string>

class FormAlreadySignedException : public std::exception {
  private:
    const std::string _message;

  public:
    FormAlreadySignedException() throw();
    FormAlreadySignedException( const FormAlreadySignedException & ) throw();
    ~FormAlreadySignedException() throw();
    FormAlreadySignedException( const std::string ) throw();

    FormAlreadySignedException &operator=( const FormAlreadySignedException & );
    virtual const char         *what() const throw();
};

#endif
