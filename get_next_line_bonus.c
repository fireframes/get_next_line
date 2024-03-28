/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:39:56 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/28 18:39:58 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*append_buffer(char *buffer, char *line, char *sep, char *nl_ptr)
{
	char	*temp_line;
	char	*old_line;

	if (nl_ptr)
		*nl_ptr = '\0';
	temp_line = ft_strjoin(buffer, sep);
	if (!temp_line)
		return (NULL);
	old_line = line;
	line = ft_strjoin(line, temp_line);
	if (!line)
		return (NULL);
	free(old_line);
	free(temp_line);
	if (nl_ptr)
		ft_memmove(buffer, nl_ptr + 1, ft_strlen(nl_ptr + 1) + 1);
	else
		buffer[0] = '\0';
	return (line);
}

int	process_fd_buffer(int fd, char **buffer, ssize_t *read_ret, int inwhile)
{
	if (inwhile == 0)
	{
		if (fd < 0 || fd > FOPEN_MAX)
			return (0);
		if (buffer[fd] == NULL)
		{
			buffer[fd] = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (buffer[fd] == NULL)
				return (0);
			buffer[fd][0] = '\0';
		}
	}
	else if (inwhile == 1)
	{
		*read_ret = read(fd, buffer[fd], BUFFER_SIZE);
		if (*read_ret <= 0)
			return (0);
		buffer[fd][*read_ret] = '\0';
	}
	else if (inwhile == 2 && buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;
	char		*nl_ptr;
	ssize_t		read_ret;

	line = NULL;
	if (!process_fd_buffer(fd, buffer, &read_ret, 0))
		return (NULL);
	while (1)
	{
		if (!buffer[fd][0])
			if (!process_fd_buffer(fd, buffer, &read_ret, 1))
				break ;
		nl_ptr = ft_strchr(buffer[fd], '\n');
		if (nl_ptr)
			return (line = append_buffer(buffer[fd], line, "\n", nl_ptr));
		else
			line = append_buffer(buffer[fd], line, "", NULL);
	}
	process_fd_buffer(fd, buffer, &read_ret, 2);
	if (read_ret == -1)
		return (NULL);
	return (line);
}
