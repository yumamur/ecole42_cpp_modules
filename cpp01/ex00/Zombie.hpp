#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
class Zombie {
    public:
        Zombie( std::string );
        ~Zombie();
        void    announce( void );
    
    private:
        std::string name;
};

#endif