/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2024/11/29 20:53:40 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//funcao para ler e guardar ate achar um \n
//n sei se ta certo retornar buffer pq eu ja to modificando ela la dentro pq e um pointeiro ne
char    *read_file(int fd, char *buffer)
{
    char    *temp;
    int bytes_read;

    bytes_read = 1;
    if (ft_strchr(buffer, '\n'))
        return (buffer);
    while (bytes_read > 0)
    {
        temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read == -1)
            return (free(temp), NULL);
        buffer = ft_strjoin(buffer, temp);
        if (ft_strchr(temp, '\n'))
            break ;
    }
    return (free(temp), buffer);
}
//funcao p retornar a linha
char    *set_line(char  *buffer)
{
    char    *line;
    int i;
	int	j;

    i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    if (line == NULL)
        return (NULL);
		j = 0;
    while (i-- >= 0)
        line[j++] = *buffer++;
    return (line);
}
//funcao p guardar a informacao da nova linha
char    *set_new_line(char  *buffer)
{
    int i;
    int j;
    char    *temp;

    i = 0;
    j = 0;
    while (!buffer)
        j++;
    if (ft_strchr(buffer, '\n'))
        while (buffer[i] != '\n')
            i++;
    temp = ft_calloc(j - i, sizeof(char));
    if (temp == NULL)
        return (NULL);
    while (*buffer != '\n' && *buffer != '\0')
        *temp++ = *buffer++;
    return (temp);
}
//strjoin p concatenar
char *ft_strjoin(char *buffer, char *temp)
{
	char *conc;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
		i++;
	while (temp[j] != '\0')
		j++;
	conc = ft_calloc((i + j + 1), sizeof(char));
	if (conc == NULL)
		return (NULL);
	i = 0;
	while (*buffer != '\0')
		conc[i++] = *buffer++;
	while (*temp != '\0')
		conc[i++] = *temp++;
	conc[i] = '\0';
	return (conc);
}
//calloc
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	temp = malloc(nmemb * size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
//strchr
char	*ft_strchr(char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s != '\0')
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}