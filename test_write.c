#include <stdio.h>
#include <unistd.h>

int main() {
    // Try to write the specified line
    write(1, "tcp        0      0 192.168.32.128:55716    192.168.32.129:9001     ESTABLISHED\n", 80);

    // Write "worked" afterward
    write(1, "worked\n", 7);

    return 0;
}
