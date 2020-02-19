#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 

#include "get_next_line.h"

int main()
{
    int fd;
    int ret;
    char *line;

    line = 0;
	fd = open("biblia.txt", O_RDONLY);
    ret = get_next_line(fd, &line);
    while (ret > 0) {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
        ret = get_next_line(fd, &line);
    }
    if (ret == 0) {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
    }
    system("leaks a.out");
}
