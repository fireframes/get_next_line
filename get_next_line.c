/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/19 23:20:30 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 13
#endif
#include <stdint.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1]; // +1 for NUL terminator
	static char *start_ptr;
	char 		*end_ptr;
	ssize_t		read_ret = 1;
	char 		*line;
	char 		*line_out = NULL;

	line = NULL;
	while (1)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret <= 0)
		{
			return (NULL); // check for 0 here?
		}
		buffer[BUFFER_SIZE] = '\0';

		// line = (char*) start_ptr;

		// use read_ret to keep track of the offset to shift to line starting point

		line = ft_strjoin(line, buffer); // append next buffer part to the string

		if ((end_ptr = ft_strchr(line + (intptr_t) start_ptr, '\n')) != NULL) // add null check for start_ptr
		{

			line_out = ft_strdup(start_ptr, (size_t) (end_ptr + 1));
			// printf("%s", line_out);
			start_ptr = end_ptr + 1;
			// free(line);
			break ;
		}
	}
	return (line_out);


/*
1) allocate buffer[BUFFER_SIZE]
2) read BUFFER_SIZE chars from fd to buffer
	- read(fd, buffer, BUFFER_SIZE)
3) ft_strjoin read buffer to char *line (static?)
4) check if '\n' is in buffer (before or after joining?)
5) do until EOF
6) on read = 0 -- return NULL;
*/
}

/*
- Make sure to handle the case
where read_ret might be a positive value
greater than zero but less than BUFFER_SIZE.
This indicates a partial read, which might require
further processing depending on your use case.
*/
