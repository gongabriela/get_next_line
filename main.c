#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char    *str;

    fd = open("empty.txt", O_RDONLY);
    printf("\nEmpty file:\n");
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close (fd);

    fd = open("onechar.txt", O_RDONLY);
    printf("\nFile with one character:\n");
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close (fd);

    fd = open("small_line.txt", O_RDONLY);
    printf("\nFile with one small line:\n");
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close (fd);

    fd = open("big_line.txt", O_RDONLY);
    printf("\nFile with one big line:\n");
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close (fd);

    fd = open("small_lines.txt", O_RDONLY);
    printf("\nFile with small lines:\n");
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close (fd);

    fd = open("big_lines.txt", O_RDONLY);
    printf("\nFile with big lines:\n");
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close (fd);

    fd = open("images.txt", O_RDONLY);
    printf("\nFile with dot images:\n");
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

//testar com:
    //arquivo vazio
    //1 letra
    //1 linha pequena
    //1 linha grande
    //varias linhas pequenas
    //varias linhas grandes
    //imagens no fim
//e compilar com buffer size:
    //1
    //10
    //100
    //1000
    //10000
