#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>

class AForm {
  private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExecute;

  public:
    AForm();
    AForm( const std::string name, int gradeToSign, int gradeToExecute );
    AForm( const AForm &copy );
    virtual ~AForm();

    AForm             &operator=( const AForm &assign );

    const std::string &getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    void               beSigned( const class Bureaucrat &b );
    virtual void       execute( const class Bureaucrat       &) {};

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

    class FormAlreadySignedException : public std::exception {
      private:
        const std::string _msg;

      public:
        FormAlreadySignedException() throw();
        FormAlreadySignedException( const std::string & ) throw();
		~FormAlreadySignedException() throw();
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<( std::ostream &, const AForm & );

#endif
