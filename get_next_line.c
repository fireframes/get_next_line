/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/12 23:45:28 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE];
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
	while (i < BUFFER_SIZE)
	{
		if (i >= BUFFER_SIZE) // Added check to prevent buffer overflow
		{
			i = 0;
			return (NULL);
		}
		read_ret = read(fd, &buffer[i], sizeof(char));
		if (read_ret < 0)
			return (NULL);
		if (read_ret == 0)
			break ;	
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			i++;
			line_len++;
			start = &buffer[i - line_len];
			if (line_len == 1 && start[0] == '\n') // Empty line
			{
				line = (char *) malloc(2 * sizeof(char));
				if (line == NULL)
				{
					free(line);
					return (NULL);
				}
				line[0] = '\n';
				line[1] = '\0';
				break ;
			}
			line = (char *) malloc((line_len + 1) * sizeof(char));
			if (line == NULL)
			{
				free(line);
				return (NULL);
			}
			ft_strlcpy(line, start, line_len + 1);
			break ;
		}
		line_len++;
		i++;
	}
	return (line);
}
