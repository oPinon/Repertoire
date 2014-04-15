CC     = clang
CFLAGS = -Wall -O0 -g

all: main

main: build/linked_list.o build/hash_table.o build/listentry.o build/parser.o build/hash_map_test.o
	$(CC) $(CFLAGS) $^ -o $@

build/parser.o: src/parser.c
	$(CC) $(CFLAGS) -o $@ -c src/parser.c

build/GUI.o: src/GUI.c
	$(CC) $(CFLAGS) -o $@ -c src/GUI.c

build/hash_map_test.o: src/hash_map_test.c
	$(CC) $(CFLAGS) -o $@ -c src/hash_map_test.c

build/hash_table.o: src/hash_table.h src/hash_table.c
	$(CC) $(CFLAGS) -o $@ -c src/hash_table.c

build/linked_list.o: src/linked_list.h src/linked_list.c
	$(CC) $(CFLAGS) -o $@ -c src/linked_list.c

build/listentry.o: src/listentry.c src/listentry.h
	$(CC) $(CFLAGS) -o $@ -c src/listentry.c

build/memory_leak_test.o: src/memory_leak_test.c
	$(CC) $(CFLAGS) -o $@ -c src/memory_leak_test.c

clean:
	rm -rf *.o
	rm -rf build/*.o
