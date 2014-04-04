CC     = clang
CFLAGS = -Wall -O0 -g

all: main

main: build/main.o build/hash_table.o build/linked_list.o
	$(CC) $(CFLAGS) $^ -o $@

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

build/hash_table.o: src/hash_table.h src/hash_table.c
	$(CC) $(CFLAGS) -c src/hash_table.c

build/linked_list.o: src/linked_list.h src/linked_list.c
	$(CC) $(CFLAGS) -c src/linked_list.c

clean:
	cd build
	rm -rf *.o
