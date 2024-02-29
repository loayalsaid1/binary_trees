CFLAGS=-Wall -Wextra -Werror -pedantic
BINS=tree_example

all: $(BINS)

%: %.c 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -f *.o
	$(RM) -f $(BINS)
