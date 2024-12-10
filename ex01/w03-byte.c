#include "iobench.h"

int main() {
    /* Opens a file in C and returns a pointer */
    /* 'W' is the opening mode: if it already exists, opens it empty; otherwise, creates it */
    /* Write-only mode */
    FILE* file = fopen("data", "w"); /*FILE *fopen(const char *path, const char *mode)*/

    if (file == NULL) { //
        perror("fopen");
        exit(1);
    }

    
    size_t size = 5120000;
    const char* buf = "6";
    double start = tstamp();

    size_t n = 0;
    while (n < size) {
        /* Uses an internal buffer to accumulate data before writing it to the file. 
        This reduces system calls, improving performance. */
        size_t r = fwrite(buf, 1, 1, file); //
        if (r != 1) {
            perror("fwrite");
            exit(1);
        }

        n += r;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    fclose(file); /* Function: Closes the file associated with the file pointer,
    flushes buffers (if necessary), and frees resources. */
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
