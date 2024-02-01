NAME	=	harlFilter

ifeq ($(shell uname), Linux)
    CC = clang++
else
    CC = c++
endif

CFLAGS	=	-Wall -Werror -Wextra -Wpedantic -std=c++98

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
