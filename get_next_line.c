/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/13 20:23:15 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	i;
	size_t			line_len;
	int				read_ret;
	char			*start = NULL;
	char			*line;

	line = NULL;

	if (fd < 0)// || BUFFER_SIZE > 65536) //Can it be more?
		return (NULL);

	line_len = 0;
	read_ret = 1;

	while (line_len < BUFFER_SIZE)
	{
		read_ret = read(fd, &buffer[i], sizeof(char));

		if (read_ret <= 0)
		{
			i = 0;
			ft_memset(buffer, '\0', sizeof(buffer));
			if (line)
				free(line);
			return (NULL);
		}
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			if (buffer[i] == '\n')
			{
				i++;
				line_len++;
			}
			start = &buffer[i - line_len];
			line = (char *) malloc((line_len + 1) * sizeof(char));
			if (line == NULL)
			{
				free(line);
				return (NULL);
			}
			ft_strlcpy(line, start, line_len + 1);
			ft_memset(buffer, '\0', sizeof(buffer));
			break ;
		}
		line_len++;
		i++;
		if (i >= BUFFER_SIZE || line_len > BUFFER_SIZE) // Added check to prevent buffer overflow
		{
			i = 0;
			ft_memset(buffer, '\0', sizeof(buffer));
			if (line)
				free(line);
			return (NULL);
		}
	}
	if (line_len == BUFFER_SIZE)
	{
		start = &buffer[i - line_len];
		line = (char *) malloc((line_len + 1) * sizeof(char));
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy(line, start, line_len + 1);
	}
	return (line);
}

/*
1) Try returning the string read when reach the BUFFER_SIZE
2) Try dynamic buffer allocation instead
*/
