/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:05:26 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/22 19:16:02 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *file = "lines_around_10.txt";

	int fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}

	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	// int i = 0;
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		break ;
	// 	// size_t i = 0;
	// 	// while (i < ft_strlen(line))
	// 	// {
	// 	// 	if (line[i] == '\n')
	// 	// 		printf("char: %d\n", line[i]);
	// 	// 	i++;
	// 	// }
	// 	printf("%s", line);
	// 	free(line);
	// 	// i++;
	// }
	close(fd);
	return (0);
}
