/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/10 16:26:18 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
			size--;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	bytes_cnt;
	static size_t	i;
	size_t			line_len;
	char			*start;
	char			*line;

	i = 0;
	bytes_cnt = 0;
	line_len = 0;
	start = &buffer[i];
	while (read(fd, &buffer[i], sizeof(char)) > 0 && bytes_cnt < BUFFER_SIZE) 
	{
		bytes_cnt++;
		line_len++;
        if (buffer[i] == '\n') 
		{
			line = (char *) malloc((line_len + 2) * sizeof(char));
			ft_strlcpy(line, start, line_len + 2);
			printf("%zu\n", line_len);
			break ;
        }
		i++;
    }
    if (read(fd, &buffer[i], sizeof(char)) == -1 || bytes_cnt >= BUFFER_SIZE) 
	{
        printf("Error reading file\n");
		return (NULL);
    }
	return (line);
}
