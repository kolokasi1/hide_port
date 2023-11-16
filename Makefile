CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: hide_openat.so hide_write.so test1 test2

hide_openat.so: openat_hide.c
	$(CC) -shared -fPIC -o $@ $< -ldl $(CFLAGS)

hide_write.so: write_hide.c
	$(CC) -shared -fPIC -o $@ $< -ldl $(CFLAGS)

test1: test_openat.c
	$(CC) -o $@ $< $(CFLAGS)

test2: test_write.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f hide_openat.so hide_write.so test1 test2
