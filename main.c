/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:05:26 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/21 23:24:53 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *file = "weesperplein.txt";
	int fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		printf("CAN'T OPEN FILE!\n");
		return (-1);
	}

	char *line1;

	int i = 0;
	while (i < 20)
	{
		line1 = get_next_line(fd);
		if (line1 == NULL)
		{
			printf("NULL or EOF\n");
			break ;
		}
		printf("%s", line1);
		free(line1);
		i++;
	}

	close(fd);
	return (0);
}
