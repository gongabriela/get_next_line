/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/01/08 12:24:14 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *buffer, char *temp)
{
	char	*conc;
	int		i;
	int		j;

	conc = ft_calloc((ft_strlen(buffer) + ft_strlen(temp) + 1), sizeof(char));
	if (conc == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[j] != '\0')
		conc[i++] = buffer[j++];
	j = 0;
	while (temp[j] != '\0')
		conc[i++] = temp[j++];
	free(buffer);
	free(temp);
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
	dest = ft_calloc(i + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
