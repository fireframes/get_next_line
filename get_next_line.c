/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:34:10 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/27 22:35:43 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nl_ptr;
	ssize_t		read_ret;

	line = NULL;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		if (!buffer[0])
		{
			read_ret = read(fd, buffer, BUFFER_SIZE);
			if (read_ret <= 0)
				break ;
			buffer[read_ret] = '\0';
		}
		nl_ptr = ft_strchr(buffer, '\n');
		if (nl_ptr)
		{
			*nl_ptr = '\0';
			line = append_buffer(buffer, line, "\n");
			if (!line)
				return (NULL);
			ft_memmove(buffer, nl_ptr + 1, ft_strlen(nl_ptr + 1) + 1);
			return (line);
		}
		else
		{
			line = append_buffer(buffer, line, "");
			if (!line)
				return (NULL);
			buffer[0] = '\0';
		}
	}
	if (read_ret == -1)
		return (NULL);
	return (line);
}
