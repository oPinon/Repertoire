CC     = clang
CFLAGS = -Wall -O0 -g

all: main

main: build/linked_list.o build/hash_table.o build/entry.o build/parser.o build/gui.o build/main.o
	$(CC) $(CFLAGS) $^ -o $@

build/main.o: src/main.c
	$(CC) $(CFLAGS) -o $@ -c src/main.c
	
build/parser.o: src/parser.h src/parser.c
	$(CC) $(CFLAGS) -o $@ -c src/parser.c
	
build/gui.o: src/gui.h src/gui.c
	$(CC) $(CFLAGS) -o $@ -c src/gui.c

build/hash_table.o: src/hash_table.h src/hash_table.c
	$(CC) $(CFLAGS) -o $@ -c src/hash_table.c

build/linked_list.o: src/linked_list.h src/linked_list.c
	$(CC) $(CFLAGS) -o $@ -c src/linked_list.c

build/entry.o: src/entry.h src/entry.c
	$(CC) $(CFLAGS) -o $@ -c src/entry.c

build/memory_leak_test.o: src/memory_leak_test.c
	$(CC) $(CFLAGS) -o $@ -c src/memory_leak_test.c

clean:
	rm -rf *.o
	rm -rf build/*.o
