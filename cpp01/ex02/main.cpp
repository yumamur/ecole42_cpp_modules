#include <iostream>
#include <string>
int main(void) {
  std::string a_string_variable = "HI THIS IS BRAIN";

  std::string *stringPTR = &a_string_variable;
  std::string &stringREF = a_string_variable;

  std::cout << "string  mem = " << &a_string_variable << std::endl;
  std::cout << "str ptr mem = " << &stringPTR << std::endl;
  std::cout << "str ref mem = " << &stringREF << std::endl;

  std::cout << "\nstring  val = " << a_string_variable << std::endl;
  std::cout << "str ptr val = " << stringPTR << std::endl;
  std::cout << "str ref val = " << stringREF << std::endl;
}