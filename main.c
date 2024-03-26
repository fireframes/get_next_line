/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:05:26 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/26 23:00:06 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *file1 = "read_error.txt";
	int fd1 = open(file1, O_RDONLY);

	if (fd1 == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}

	char *file2 = "read_error.txt";
	int fd2 = open(file2, O_RDONLY);

	if (fd2 == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}

	char *file3 = "read_error.txt";
	int fd3 = open(file3, O_RDONLY);

	if (fd3 == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}

	char *file4 = "read_error.txt";
	int fd4 = open(file4, O_RDONLY);

	if (fd4 == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}

	char *line1 = NULL;
	line1 = get_next_line(fd1);
	printf("next line fd1: %s", line1);
	free(line1);
	line1 = NULL;
	printf("\n");

	char *line2 = get_next_line(fd2);
	printf("next line fd2: %s", line2);
	free(line2);
	line2 = NULL;
	printf("\n");

	char *line3 = get_next_line(fd3);
	printf("next line fd3: %s", line3);
	free(line3);
	line3 = NULL;
	printf("\n");

	char *line4 = get_next_line(fd4);
	printf("next line fd4: %s", line4);
	free(line4);
	line4 = NULL;
	printf("\n");
	// char *line1 = NULL;
	// char *line2 = NULL;

	// int i = 0;
	// while (i < 60)
	// {
	// 	line1 = get_next_line(fd1);
	// 	if (line1 == NULL)
	// 		break ;
	// 	printf("line1:\n%s", line1);
	// 	free(line1);

	// 	line2 = get_next_line(fd2);
	// 	if (line2 == NULL)
	// 		break ;
	// 	printf("line2:\n%s", line2);
	// 	free(line2);

	// 	i++;
	// }

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
