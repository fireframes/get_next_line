/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:05:26 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/13 00:45:17 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int main(void)//int argc, char *argv[])
{
	// if (argc < 2)
	// {
	// 	printf("Enter sentences");
	// 	return (-1);
	// }
	// char *input = argv[1];
	// printf("%s\n", input);

	char *file = "weesperplein.txt";
	int fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}
	// else
	// 	printf("OPENED FILE FD: %d\n", fd);
	char *line1;
	// line1 = get_next_line(fd);
	// printf("%s", line1);
	// free(line1);
	int i = 0;
	while (i < 30)
	{
		line1 = get_next_line(fd);
		if (line1 == NULL)
		{	
			printf("Aborted function or EOF\n");	
			break ;
		}
		printf("%s", line1);
		free(line1);
		i++;
	}

	close(fd);
	return (0);
}
