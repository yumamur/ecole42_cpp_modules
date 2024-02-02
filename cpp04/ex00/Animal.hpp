#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
    public:
        Animal( void );
        Animal( std::string const &type );
        Animal( Animal const &source );
        virtual ~Animal( void );

        Animal            &operator=( Animal const &source );

        std::string const &getType( void ) const;
        virtual void       makeSound( void ) const;

    protected:
        std::string _type;
};

#endif       // ANIMAL_HPP
