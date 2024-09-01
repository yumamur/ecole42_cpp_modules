#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

int main() {
  Data    d;
  uintptr_t  raw;

  raw = Serializer::INSTANCE.serialize( &d );
  std::cout << "Serialized: " << raw << std::endl;
  std::cout << "Deserialized: " << Serializer::INSTANCE.deserialize( raw ) << std::endl;
  return 0;
}
