#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd); 

int main(void)
{
    int fd;
    char    *str;

    fd = open("image.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close (fd);
    return (0);
}