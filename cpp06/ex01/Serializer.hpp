#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

class Serializer {
  private:
    Serializer();
    Serializer( const Serializer & );
    ~Serializer();

  public:
    Serializer       &operator=( const Serializer &assign );

    static Serializer INSTANCE;

    uintptr_t         serialize( class Data *p );
    Data             *deserialize( uintptr_t );
};

#endif       // !SERIALIZER_HPP
