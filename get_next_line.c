/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:44 by ggoncalv          #+#    #+#             */
/*   Updated: 2024/11/28 16:12:33 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *line;
    char    buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    line = (char *)malloc(sizeof(char) * (bytes_read + 1));
    ft_strlcpy(line, buffer, bytes_read + 1);
    return (line);
}

