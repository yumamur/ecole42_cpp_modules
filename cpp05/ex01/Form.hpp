#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form {
  private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExecute;

  public:
    Form();
    Form( const std::string name, int gradeToSign, int gradeToExecute );
    Form( const Form &copy );
    ~Form();

    Form              &operator=( const Form &form );

    const std::string &getName() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    void               beSigned( const class Bureaucrat &bureaucrat );
};

std::ostream &operator<<( std::ostream &out, const Form &form );

#endif
