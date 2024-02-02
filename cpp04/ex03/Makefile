NAME = ex03

ifeq ($(shell uname), Linux)
	CC = clang++
else
	CC = c++
endif

CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++98

SRC = MateriaSource.cpp Cure.cpp main.cpp AMateria.cpp Character.cpp Ice.cpp 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: clean all
