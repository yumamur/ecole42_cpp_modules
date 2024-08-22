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
    ~AForm();

    AForm             &operator=( const AForm &assign );

    const std::string &getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    void               beSigned( const class Bureaucrat &b );
    virtual void       execute( const class Bureaucrat &b );
};

std::ostream &operator<<( std::ostream &, const AForm & );

#endif
