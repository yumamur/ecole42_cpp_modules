#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once

#include <string>

class ICharacter;

class AMateria {
  protected:
    std::string _type;

  public:
    AMateria();
    AMateria( AMateria const &other );
    AMateria &operator=( AMateria const &other );
    AMateria( std::string const &type );
    virtual ~AMateria();
    virtual AMateria  *clone() const = 0;

    std::string const &getType() const;

    virtual void       use( ICharacter &target );
};

#endif       // AMATERIA_HPP
