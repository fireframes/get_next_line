/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/11 20:32:45 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	i;
	size_t			line_len;
	int				read_ret;
	char			*start;
	char			*line;

	if (fd < 0 || BUFFER_SIZE > 65536)
		return (NULL);
	line_len = 0;
	read_ret = 1;
	while (read_ret > 0 && i <= BUFFER_SIZE)
	{
		read_ret = read(fd, &buffer[i], sizeof(char));
		if (read_ret == 0 || read_ret == -1)
			return (NULL);
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			line_len++;
			i++;
			start = &buffer[i - line_len];
			line = (char *) malloc((line_len + 1) * sizeof(char));
			if (line == NULL)
				return (NULL);
			ft_strlcpy(line, start, line_len + 1);
			break ;
		}
		line_len++;
		i++;
	}
	if (i > BUFFER_SIZE)
		return (NULL);
	return (line);
}

// If the EOF is reached what is the last character printed?
