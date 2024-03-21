/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/21 23:26:22 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1]; // +1 for NUL terminator
	static size_t  offset;
	char 		*end_ptr;
	ssize_t		read_ret;
	static char line[1000000];
	char 		*line_out;

	line_out = NULL;
	read_ret = 1;
	if (fd < 0)
		return (NULL);
	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (read_ret == -1)// || read_ret == 0)
			break ;

		buffer[read_ret] = '\0';
		ft_strcat(line, buffer); // append next buffer part to the string

		if (read_ret < BUFFER_SIZE)
		{
			line_out = ft_strendup(&line[offset], &line[ft_strlen(line)]);
			return (line_out);
		}

		if ((end_ptr = ft_strchr(&line[offset], '\n')))// || ft_strchr(buffer, '\0'))
		{
			if (*end_ptr)
				end_ptr++;
			line_out = ft_strendup(&line[offset], end_ptr);
			offset = end_ptr - line;
			return (line_out);
		}

	}
	return (NULL);
}


/*
- Make sure to handle the case
where read_ret might be a positive value
greater than zero but less than BUFFER_SIZE.
This indicates a partial read, which might require
further processing depending on your use case.
*/
