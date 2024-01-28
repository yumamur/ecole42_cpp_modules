NAME	=	ex03

CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

SRC		=	main.cpp \
			HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp

.PHONY: all clean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: clean all