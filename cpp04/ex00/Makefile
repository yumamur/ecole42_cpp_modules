NAME = ex00

ifneq ($(shell uname), darwin)
	CC = clang++
else
	CC = c++
endif

CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: clean all
