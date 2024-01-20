NAME	=	phonebook

CFLAGS	=	-Wall -Werror -Wextra -std=c++98
CC		=	c++

SRC		=	main.cpp \
			display_utils.cpp \
			EncoreApp.cpp \
			Contact.cpp \
			PhoneBook.cpp

.PHONY: all clean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all