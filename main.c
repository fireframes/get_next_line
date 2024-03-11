/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:05:26 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/10 16:24:41 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <string.h>

int main(void)
{
    char *file = "weesperplein.txt";
    
    int fd = open(file, O_RDONLY);

    if (fd == -1)
    {
        printf("CAN'T OPEN FILE!\n");
        return (-1);
    }
    else
        printf("OPENED FILE'S FD: %d\n", fd);
    
    char *line1 = get_next_line(fd);
    char *line2 = get_next_line(fd);
    char *line3 = get_next_line(fd);
    printf("%s", line1);
    size_t len = strlen(line1);
    printf("last char: %d\n", line1[len]);
    printf("%s", line2);
    printf("%s", line3);
}