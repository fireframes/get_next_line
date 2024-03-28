/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:38:10 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/28 18:38:12 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	read_buffer(int fd, char *buffer, ssize_t *read_ret)
{
	*read_ret = read(fd, buffer, BUFFER_SIZE);
	if (*read_ret <= 0)
		return (0);
	buffer[*read_ret] = '\0';
	return (1);
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
			if (!read_buffer(fd, buffer, &read_ret))
				break ;
		nl_ptr = ft_strchr(buffer, '\n');
		if (nl_ptr)
			return (line = append_buffer(buffer, line, "\n", nl_ptr));
		else
			line = append_buffer(buffer, line, "", NULL);
	}
	if (read_ret == -1)
		return (NULL);
	return (line);
}
