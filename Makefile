CC= gcc
CFLAGS=-Wall -Wextra -Werror -pedantic


all: queue

queue:
	gcc queue.c -o q
	./q
