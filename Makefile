SUBDIRS := $(wildcard */*)

all:
	@for dir in $(SUBDIRS); \
	do \
		echo Building $$dir; \
		$(MAKE) -sC $$dir; \
	done

re:
	@for dir in $(SUBDIRS); \
	do \
		echo Rebuilding $$dir; \
		$(MAKE) re -sC $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); \
	do \
		echo Cleaning $$dir; \
		$(MAKE) clean -sC $$dir; \
	done