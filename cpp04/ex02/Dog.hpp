#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
    public:
        Dog( void );
        Dog( Dog const &source );
        virtual ~Dog( void );

        Dog         &operator=( Dog const &source );

        virtual void makeSound( void ) const;

    private:
        Brain *_brain;
};

#endif
