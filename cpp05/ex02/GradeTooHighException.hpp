#ifndef GRADE_TOO_HIGH_EXCEPTION_HPP
#define GRADE_TOO_HIGH_EXCEPTION_HPP

#include <exception>
#include <string>

class GradeTooHighException : public std::exception {
  private:
    const std::string _message;

  public:
    GradeTooHighException() throw();
    GradeTooHighException( const GradeTooHighException & ) throw();
    ~GradeTooHighException() throw();
    GradeTooHighException( const std::string ) throw();

    GradeTooHighException &operator=( const GradeTooHighException & );
    virtual const char    *what() const throw();
};

#endif
