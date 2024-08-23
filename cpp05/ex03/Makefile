NAME = ex03

ifeq ($(shell uname), Linux)
	CC = clang++
else
	CC = c++
endif

CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++98

SRC = AForm.cpp Bureaucrat.cpp FormAlreadySignedException.cpp GradeTooHighException.cpp GradeTooLowException.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: clean all
