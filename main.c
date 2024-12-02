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
        str = get_next_line(fd); 
        printf("%s", str);
    }
    free(str);
    close (fd);
}