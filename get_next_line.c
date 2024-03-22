/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/22 19:20:50 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*nl_ptr;
	char		*temp_line;
	ssize_t		read_ret;
	char 		*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (read_ret == -1)
			break ;
		buffer[read_ret] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			temp_line = ft_strjoin(line, buffer);
			free(line); // Free the previous line
			line = temp_line;
		}
		if ((nl_ptr = ft_strchr(buffer, '\n')) != NULL)
		{
			ft_memmove(buffer, nl_ptr + 1, ft_strlen(nl_ptr + 1) + 1);
			return (line);
		}
	}
	if (read_ret == 0 && line != NULL)
		return (line);
	return (NULL);
}


/*
- Make sure to handle the case
where read_ret might be a positive value
greater than zero but less than BUFFER_SIZE.
This indicates a partial read, which might require
further processing depending on your use case.
*/
