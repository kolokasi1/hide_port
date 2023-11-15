#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // Open /proc/net/tcp using openat
    int fd = openat(AT_FDCWD, "/proc/net/tcp", O_RDONLY);
    if (fd == -1) {
        perror("Error opening /proc/net/tcp");
        return 1;
    }

    // Read and print the contents (you can customize this part)
    char buffer[4096];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("Error reading /proc/net/tcp");
        close(fd);
        return 1;
    }

    write(STDOUT_FILENO, buffer, bytesRead);

    // Close the file descriptor
    close(fd);

    return 0;
}
