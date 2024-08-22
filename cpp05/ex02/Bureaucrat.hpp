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

    void               signForm( class AForm &form );
	void			   executeForm( class AForm &form);
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat );

#endif
