NAME	=	megaphone

CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

.PHONY: all clean re

all: $(NAME)

$(NAME): megaphone.cpp
	@$(CC) $(CFLAGS) megaphone.cpp -o $(NAME)

clean:
	@rm $(NAME)

fclean:
	@rm $(NAME)
	@echo "bence abartmaya gerek yok"

re: clean all