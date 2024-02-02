#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat( void );
        Cat( Cat const &source );
        virtual ~Cat( void );

        Cat         &operator=( Cat const &source );

        virtual void makeSound( void ) const;
};

#endif
