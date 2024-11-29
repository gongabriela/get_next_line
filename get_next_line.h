/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:19:15 by ggoncalv          #+#    #+#             */
/*   Updated: 2024/11/29 20:53:34 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char    *get_next_line(int fd);
char    *read_file(int fd, char *buffer);
char    *set_line(char  *buffer);
char    *set_new_line(char  *buffer);
char    *ft_strjoin(char    *buffer, char   *temp);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(char *s, int c);

#endif
