#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
  protected:
    const std::string _name;
    int               _grade;

  public:
    Bureaucrat();
    Bureaucrat( const std::string name, int grade );
    Bureaucrat( const Bureaucrat &copy );
    ~Bureaucrat();

    Bureaucrat        &operator=( const Bureaucrat &assign );

    const std::string &getName() const;
    int                getGrade() const;

    void               incrementGrade();
    void               decrementGrade();

    void               signForm( class Form &form );

    class GradeTooHighException : public std::exception {
      private:
        const std::string _msg;

      public:
        GradeTooHighException() throw();
        GradeTooHighException( const std::string & ) throw();
        ~GradeTooHighException() throw();
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      private:
        const std::string _msg;

      public:
        GradeTooLowException() throw();
        GradeTooLowException( const std::string & ) throw();
        ~GradeTooLowException() throw();
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat );

#endif
