#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
class Zombie {
    public:
        Zombie( void );
        Zombie( std::string );
        ~Zombie( void );
        void setName( std::string );
        void announce( void );

    private:
        std::string name;
};

#endif