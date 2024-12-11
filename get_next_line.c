/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:44 by ggoncalv          #+#    #+#             */
/*   Updated: 2024/12/11 12:47:43 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, newline);
	if (buffer == NULL)
		return (NULL);
	else if (*buffer == '\0')
		return (free(buffer), NULL);
	line = set_line(buffer, &newline);
	if (ft_strlen(line) == 0)
		return (free(buffer), free(line), free(newline), NULL);
	return (free(buffer), line);
}

char	*read_file(int fd, char *newline)
{
	char	*temp;
	char	*temp2;
	char	*buffer;
	int		bytes_read;

	buffer = set_buffer(newline);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (temp == NULL)
			return (NULL);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp), free(buffer), NULL);
		if (bytes_read == 0)
			return (free(temp), buffer);
		temp2 = buffer;
		buffer = ft_strjoin(buffer, temp);
		free(temp);
		free(temp2);
	}
	return (buffer);
}

char	*set_buffer(char *newline)
{
	char	*buffer;

	if (newline != NULL)
		buffer = newline;
	else
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char	*set_line(char *buffer, char **newline)
{
	char	*line;
	char	*start;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	start = line;
	while (i-- >= 0 && *buffer != '\0')
		*line++ = *buffer++;
	if (*buffer != '\0')
		*newline = ft_strdup(buffer);
	else
		*newline = ft_strdup("");
	if (*newline == NULL)
		return (free(start), NULL);
	return (start);
}
