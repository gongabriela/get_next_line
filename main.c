#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char    *get_next_line(int fd); 

int main(void)
{
    int fd;


    fd = open("image.txt", O_RDONLY);

    printf("%s", get_next_line(fd));
    close(fd);
    return (0);
}