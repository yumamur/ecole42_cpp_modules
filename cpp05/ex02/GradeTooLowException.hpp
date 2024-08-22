#ifndef GRADE_TOO_LOW_EXCEPTION_HPP
#define GRADE_TOO_LOW_EXCEPTION_HPP

#include <exception>
#include <string>

class GradeTooLowException : public std::exception {
  private:
    const std::string _message;

  public:
    GradeTooLowException() throw();
    GradeTooLowException( const GradeTooLowException &copy ) throw();
    ~GradeTooLowException() throw();
	GradeTooLowException( const std::string ) throw();

    GradeTooLowException &operator=( const GradeTooLowException &assign );
    virtual const char   *what() const throw();
};

#endif
