NAME	=	ex01

ifeq ($(shell uname), Linux)
    CC = clang++
else
    CC = c++
endif

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

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