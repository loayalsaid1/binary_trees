CC= gcc
CFLAGS=-Wall -Wextra -Werror -pedantic


%: %.c 
	$(CC) $(CFLAGS) $^ -o $@
	@echo
