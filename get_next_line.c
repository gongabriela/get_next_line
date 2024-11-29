/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:44 by ggoncalv          #+#    #+#             */
/*   Updated: 2024/11/29 21:13:38 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char *buffer; //essa variavel nao pode ser a estatica pq eu inicializo ela aq em cima
                        //tem q guardar o resto la embaixo no setnewline e so ir copiando o valor
    char    *line;

    buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));

    buffer = read_file(fd, buffer);
    line = set_line(buffer);
    buffer = set_new_line(buffer);
    return (line);
}

