/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2024/12/02 17:08:13 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
        if (bytes_read == -1 || bytes_read == 0)
            return (free(temp), NULL);
        buffer = ft_strjoin(buffer, temp);
        if (ft_strchr(temp, '\n'))
            break ;
    }
	free(temp);
    return (buffer);
}

char *set_line(char *buffer) // tentar juntar essa funcao com a newline
{
	char	*line;
	int i;
	int	j;
	int k;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (i-- >= 0)
		line[j++] = buffer[k++];
	return (line);
}

char *set_new_line(char *buffer)
{
	int i;
	int j;
	int k;
	char *temp;

	i = 0;
	j = 0;
	while (buffer[j] != '\0')
		j++;
	if (ft_strchr(buffer, '\n'))
		while (buffer[i] != '\n')
			i++;
	temp = ft_calloc(j - i, sizeof(char));
	if (temp == NULL)
		return (NULL);
	k = 0;
	i++;
	while (i <= j)
		temp[k++] = buffer[i++];
	return (temp);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substring;
	size_t				s_size;
	size_t				i;

	s_size = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_size <= start)
		return (ft_strdup(""));
	else if (start + len > s_size)
		len = s_size - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}