#include <algorithm>
#include <cctype>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

    for (int i = 1; i < argc; ++i) {
		std::string str(argv[i]);
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
    }
	std::cout << std::endl;
}