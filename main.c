/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:05:26 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/25 23:10:39 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *file1 = "giant_line_nl.txt";

	int fd1 = open(file1, O_RDONLY);

	if (fd1 == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}
	
	// char *file2 = "one_line_no_nl.txt";

	// int fd2 = open(file2, O_RDONLY);

	// if (fd2 == -1)
	// {
	// 	printf("CAN'T OPEN FILE!\n");
	// 	return (-1);
	// }
	char *line;
	// line = get_next_line(fd1);
	// printf("line 1: %s", line);
	// free(line);
	// printf("\n");

	// line = get_next_line(fd2);
	// printf("line 2: %s", line);
	// free(line);
	// printf("\n");

	// line = get_next_line(fd1);
	// printf("line 3: %s", line);
	// free(line);

	int i = 0;
	while (i < 20)
	{
		line = get_next_line(fd1);
		if (line == NULL)
		{
			// printf("line outer: %s", line);
			break ;
		}

		printf("%s", line);
		// printf("HERE\n");

		free(line);
		i++;
	}

	close(fd1);
	// close(fd2);

	return (0);
}
