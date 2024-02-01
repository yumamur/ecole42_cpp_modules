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
			printf "NAME = $$i\n\n" > $$i/Makefile; \
			printf "ifeq (%c(shell uname), Linux)" '$$'; \
			printf "\tCC = clang++\n" >> $$i/Makefile; \
			printf "else\n" >> $$i/Makefile; \
			printf "\tCC = c++\n" >> $$i/Makefile; \
			printf "endif\n\n" >> $$i/Makefile; \
			printf "CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++98\n\n" >> $$i/Makefile; \
			printf "SRC = `find $$i | grep .cpp`\n\n" >> $$i/Makefile; \
			printf "all: %c(NAME)\n\n" '$$' >> $$i/Makefile; \
			printf "%c(NAME): %c(SRC)\n" '$$' '$$' >> $$i/Makefile; \
			printf "\t%c(CC) %c(CFLAGS) %c(SRC) -o %c(NAME)\n\n" '$$' '$$' '$$' '$$' >> $$i/Makefile; \
			printf "clean:\n" >> $$i/Makefile; \
			printf "\trm -rf %c(NAME)\n\n" '$$' >> $$i/Makefile; \
			printf "fclean:\n" >> $$i/Makefile; \
			printf "\trm -rf %c(NAME)" '$$' >> $$i/Makefile; \
			printf "re: clean all\n" >> $$i/Makefile; \
		fi \
	done