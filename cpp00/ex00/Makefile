NAME   = megaphone

CFLAGS = -Wall -Werror -Wextra -std=c++98

ifeq ($(shell uname), Linux)
    CC = clang++
else
    CC = c++
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): megaphone.cpp
	@$(CC) $(CFLAGS) megaphone.cpp -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: clean all
