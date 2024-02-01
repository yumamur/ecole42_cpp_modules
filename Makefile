MODULES := $(wildcard */)

TARGET := $(MAKECMDGOALS)

.PHONY: all re clean $(MODULES)

all re clean: $(MODULES)

$(MODULES):
	@for i in $(wildcard $@*); \
	do \
		if [ -z "$$i/Makefile" ]; \
		then \
			echo "NAME = $$i" > $$i/Makefile; \
			echo "CC = clang++" >> $$i/Makefile; \
			echo "CFLAGS = -Wall -Werror -Wextra -Wpedantic" >> $$i/Makefile; \
			echo "SRC = `find $$i | grep .cpp`" >> $$i/Makefile; \
			echo "all: \$(NAME)" >> $$i/Makefile; \
			echo "\$(NAME): \$(SRC)" >> $$i/Makefile; \
			echo "\t\$(CC) \$(CFLAGS) \$(SRC) -o \$(NAME)" >> $$i/Makefile; \
			echo "clean:" >> $$i/Makefile; \
			echo "\trm -rf \$(NAME)" >> $$i/Makefile; \
			echo "re: clean all" >> $$i/Makefile; \
		fi \
		$(MAKE) $(TARGET) -sC $$i; \
	done