NAME	=	account

CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

SRC		=	tests.cpp \
			Account.cpp

.PHONY: all clean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all