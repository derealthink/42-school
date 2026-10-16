# Get Next Line

A 42 School C project that exposes `char *get_next_line(int fd)` to read a file descriptor one line at a time.

## What this demonstrates

Low-level `read` calls, heap-allocated strings, newline detection and static state that retains unread text between calls.

## Use in a program

Include `get_next_line.h`, open a descriptor and repeatedly call `get_next_line(fd)`. Free each returned line. A returned line includes its newline when present; `NULL` ends the loop on end-of-input or failure.

Save the following as `example.c` in the repository root:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("lorem.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Compile with a C compiler on a POSIX system:

```sh
cc example.c get_next_line.c get_next_line_utils.c -o gnl_example
./gnl_example
```

## Implementation notes

- There is no Makefile in this repository.
- `get_next_line.c` defines a fixed `BUF_SIZE` of 10,000,000 bytes; it does not use the usual configurable `BUFFER_SIZE` macro.
- The implementation uses one static remainder. Interleaving reads from different descriptors is not supported.
- `get_next_test.c` and `next_line_mine.c` are additional files; the example above explicitly selects the main implementation.

This is a learning implementation, with no claim of production readiness or complete error-path coverage.

---

Part of my [42 School project collection](../../README.md).
