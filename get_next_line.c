/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:44 by ggoncalv          #+#    #+#             */
/*   Updated: 2024/12/07 19:06:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    static char *newline;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (newline != NULL)
        buffer = newline;
    else
        buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (buffer == NULL)
        return (NULL);
    buffer = read_file(fd, buffer);
    if (buffer == NULL)
        return (free(newline), NULL);
    line = set_line(buffer);
    newline = set_new_line(buffer);
    free(buffer);
    return (line);
}

//quando for a ultima chamada, e preciso dar free na newline. retornar (null) apenas quando nao ha nada para ler no arquivo (ta aparecendo quando le a ultima linha) 