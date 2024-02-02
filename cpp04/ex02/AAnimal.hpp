#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
    public:
        AAnimal( void );
        AAnimal( std::string const &type );
        AAnimal( AAnimal const &source );
        virtual ~AAnimal( void );

        AAnimal           &operator=( AAnimal const &source );

        std::string const &getType( void ) const;
        virtual void       makeSound( void ) const = 0;

    protected:
        std::string _type;
};

#endif       // AANIMAL_HPP
