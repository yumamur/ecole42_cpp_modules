NAME	=	ex05

CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

SRC		=	main.cpp \
			Harl.cpp

.PHONY: all clean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME) *.replace

re: clean all
