#CONFIG

CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++98
SRC = `find $$i | grep .cpp | cut -d/ -f3 | tr '\n' ' '`

#END CONFIG

MODULES := $(wildcard */*)

TARGET := $(MAKECMDGOALS)

.PHONY: all re clean $(MODULES)

all re clean:
	@for i in $(MODULES); \
	do \
		if [ -f "$$i/Makefile" ]; \
		then \
			echo "\033[32;1mmake $(TARGET)\033[m in $$i"; \
			$(MAKE) $(TARGET) -sC $$i; \
		fi \
	done

create:
	@for i in $(MODULES); \
	do \
		if [ ! -f "$$i/Makefile" ]; \
		then \
			echo "\033[38;2;150;150;250;1mCreating Makefile for $$i\033[m"; \
			printf "NAME = `echo $$i | cut -d/ -f-1`\n\n" > $$i/Makefile; \
			printf "ifeq (%c(shell uname), Linux)\n" >> $$i/Makefile '$$'; \
			printf "\tCC = clang++\n" >> $$i/Makefile; \
			printf "else\n" >> $$i/Makefile; \
			printf "\tCC = c++\n" >> $$i/Makefile; \
			printf "endif\n\n" >> $$i/Makefile; \
			printf "CFLAGS = %s\n\n" "$(CFLAGS)" >> $$i/Makefile; \
			printf "SRC = %s\n\n" "$(SRC)" >> $$i/Makefile; \
			printf ".PHONY: all clean fclean re\n\n" >> $$i/Makefile; \
			printf "all: %c(NAME)\n\n" '$$' >> $$i/Makefile; \
			printf "%c(NAME): %c(SRC)\n" '$$' '$$' >> $$i/Makefile; \
			printf "\t%c(CC) %c(CFLAGS) %c(SRC) -o %c(NAME)\n\n" '$$' '$$' '$$' '$$' >> $$i/Makefile; \
			printf "clean:\n" >> $$i/Makefile; \
			printf "\trm -rf %c(NAME)\n\n" '$$' >> $$i/Makefile; \
			printf "fclean:\n" >> $$i/Makefile; \
			printf "\trm -rf %c(NAME)\n\n" '$$' >> $$i/Makefile; \
			printf "re: clean all\n" >> $$i/Makefile; \
		fi \
	done