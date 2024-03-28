/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:34:10 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/27 22:18:06 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*append_buffer(char *buffer, char *line, char *sep)
{
	char	*temp_line;
	char	*old_line;

	temp_line = ft_strjoin(buffer, sep);
	if (!temp_line)
		return (NULL);
	old_line = line;
	line = ft_strjoin(line, temp_line);
	if (!line)
		return (NULL);
	free(old_line);
	free(temp_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;
	char		*nl_ptr;
	ssize_t		read_ret;


	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (buffer[fd] == NULL)
	{
		buffer[fd] = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer[fd] == NULL)
			return (NULL);
		buffer[fd][0] = '\0';
	}
	while (1)
	{
		if (!buffer[fd][0])
		{
			read_ret = read(fd, buffer[fd], BUFFER_SIZE);
			if (read_ret <= 0)
				break ;
			buffer[fd][read_ret] = '\0';
		}
		nl_ptr = ft_strchr(buffer[fd], '\n');
		if (nl_ptr)
		{
			*nl_ptr = '\0';
			line = append_buffer(buffer[fd], line, "\n");
			if (!line)
				return (NULL);
			ft_memmove(buffer[fd], nl_ptr + 1, ft_strlen(nl_ptr + 1) + 1);
			return (line);
		}
		else
		{
			line = append_buffer(buffer[fd], line, "\0");
			if (!line)
				return (NULL);
			buffer[fd][0] = '\0';
		}
	}
	if (buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	if (read_ret == -1)
		return (NULL);
	return (line);
}
