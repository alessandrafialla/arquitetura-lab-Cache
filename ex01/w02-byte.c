#include "iobench.h"

int main() {
    // Opens a file called `data`. The O_SYNC flag was removed, so it will use caching.
    int fd = open("data", O_WRONLY | O_CREAT | O_TRUNC , 0666);
    
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // writes the characer '6' to the file
    size_t size = 5120000;
    const char* buf = "6";
    double start = tstamp();

    size_t n = 0;
    while (n < size) {
        ssize_t r = write(fd, buf, 1);
        if (r != 1) {
            perror("write");
            exit(1);
        }

        // with some frequency (defined in iobench.h), prints out
        // how long it takes to complete the write.
        n += r;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    /* Without O_SYNC, closing the file forces the operating system to write
    all remaining data in the cache to the disk. */
    close(fd);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
