CC     = clang
CFLAGS = -Wall -O0 -g

all: main

main: build/hash_map_test.o build/linked_list.o build/hash_table.o build/listentry.o
	$(CC) $(CFLAGS) $^ -o $@

build/hash_map_test.o: src/hash_map_test.c
	$(CC) $(CFLAGS) -o $@ -c src/hash_map_test.c

build/hash_table.o: src/hash_table.h src/hash_table.c
	$(CC) $(CFLAGS) -o $@ -c src/hash_table.c

build/linked_list.o: src/linked_list.h src/linked_list.c
	$(CC) $(CFLAGS) -o $@ -c src/linked_list.c

build/listentry.o: src/listentry.c src/listentry.h
	$(CC) $(CFLAGS) -o $@ -c src/listentry.c

clean:
	cd build
	rm -rf *.o
