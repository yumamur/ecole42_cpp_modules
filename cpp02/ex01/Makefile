NAME	=	ex01

CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

SRC		=	main.cpp \
			Fixed.cpp

.PHONY: all clean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: clean all