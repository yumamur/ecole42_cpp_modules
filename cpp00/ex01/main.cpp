#include <iostream>
#include <string>
#include "EncoreApp.hpp"

int main(void) {

    EncoreApp app;
    std::string input;

    while (true) {
        std::cout << ENCORE_APP_PROMPT;
        std::getline(std::cin, input);
        if (std::cin.eof())
            return (0);
        if (app.execute(input))
            return (0);
    }
}
