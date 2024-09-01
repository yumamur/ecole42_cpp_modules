#include "Serializer.hpp"

#include "Data.hpp"

#include <stdint.h>

Serializer Serializer::INSTANCE = Serializer();

uintptr_t  Serializer::serialize( Data *dptr ) {
  return reinterpret_cast<uintptr_t>( dptr );
}

Data *Serializer::deserialize( uintptr_t raw ) {
  return reinterpret_cast<Data *>( raw );
}

Serializer::Serializer() {
}

Serializer::Serializer( const Serializer & ) {
}

Serializer::~Serializer() {
}

Serializer &Serializer::operator=( const Serializer & ) {
  return *this;
}
