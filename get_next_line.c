/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:32:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/18 22:16:41 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1]; // +1 for NUL terminator
	ssize_t		read_ret;
	
	while (read_ret)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
			break ; // check for 0 here?
			/*
			- Make sure to handle the case 
			where read_ret might be a positive value 
			greater than zero but less than BUFFER_SIZE. 
			This indicates a partial read, which might require 
			further processing depending on your use case.
			*/
		
		
	}
	return (NULL);
	
	/*
	1) allocate buffer[BUFFER_SIZE]
	2) read BUFFER_SIZE chars from fd to buffer 
		- read(fd, buffer, BUFFER_SIZE)
		or 
		- read(fd, &buffer[i], sizeof(char))
		
	3) ft_strjoin read buffer to char *line (static?)
	4) check if '\n' is in buffer (before or after joining?)
	5) do until EOF
	6) on read = 0 -- return NULL;
	*/
}

/*
1) Try returning the string read when reach the BUFFER_SIZE
2) Try dynamic buffer allocation instead
*/
