CC     = clang
CFLAGS = -Wall -Werror
BINARIES = main linked_list parser 

all: $(BINARIES)

$(BINARIES):
	$(CC) $(CFLAGS) âˆ-o $@ $@.c

clean:
	rm -rf *.o

distclean: clean
	rm -rf $(BINARIES)
