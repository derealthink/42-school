#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     line_number = 1;

    fd = open("lorem.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening lorem.txt");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s\n", line_number++, line);
        free(line);
    }

    close(fd);
    return (0);
}