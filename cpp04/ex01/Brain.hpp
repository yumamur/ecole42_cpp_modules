#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
    private:
        std::string _ideas[100];

    public:
        Brain( void );
        Brain( Brain const &source );
        ~Brain( void );

        Brain      &operator=( Brain const &source );

        std::string getIdea( int index ) const;
        void        setIdea( int index, std::string idea );
};

#endif
