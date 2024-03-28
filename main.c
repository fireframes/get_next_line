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

	// char *file2 = "weesperplein.txt";
	// int fd2 = open(file2, O_RDONLY);

	// if (fd2 == -1)
	// {
	// 	printf("CAN'T OPEN FILE!\n");
	// 	return (-1);
	// }

	// char *file3 = "lines_around_10.txt";
	// int fd3 = open(file3, O_RDONLY);

	// if (fd3 == -1)
	// {
	// 	printf("CAN'T OPEN FILE!\n");
	// 	return (-1);
	// }

	// char *file4 = "empty.txt";
	// int fd4 = open(file4, O_RDONLY);

	// if (fd4 == -1)
	// {
	// 	printf("CAN'T OPEN FILE!\n");
	// 	return (-1);
	// }

	char *line1 = NULL;
	line1 = get_next_line(1000);
	printf("next line fd1: %s", line1);
	free(line1);
	line1 = NULL;
	printf("\n");

	char *line2 = get_next_line(-1);
	printf("next line fd2: %s", line2);
	free(line2);
	line2 = NULL;
	printf("\n");

	char *line3 = get_next_line(fd1);
	printf("next line fd3: %s", line3);
	free(line3);
	line3 = NULL;
	printf("\n");

	char *line4 = get_next_line(fd1);
	printf("next line fd4: %s", line4);
	free(line4);
	line4 = NULL;
	printf("\n");

	line1 = NULL;
	line1 = get_next_line(fd1);
	printf("next line fd1: %s", line1);
	free(line1);
	line1 = NULL;
	printf("\n");

	line2 = get_next_line(fd1);
	printf("next line fd2: %s", line2);
	free(line2);
	line2 = NULL;
	printf("\n");

	line3 = get_next_line(fd1);
	printf("next line fd3: %s", line3);
	free(line3);
	line3 = NULL;
	printf("\n");

	line4 = get_next_line(fd1);
	printf("next line fd4: %s", line4);
	free(line4);
	line4 = NULL;
	printf("\n");


	close(fd1);
	// close(fd2);
	// close(fd3);
	// close(fd4);

	return (0);
}

/*
	TO CLEAN STILL REACHABLE STATIC MEMORY

FOR MAIN: 

	get_next_line(-3); // CLEAN STATIC BUFFERS ON EXIT

FOR GNL:


void cleanup(char **buffer)
{
    for (int i = 0; i < FOPEN_MAX; i++)
    {
        if (buffer[i] != NULL)
        {
            free(buffer[i]);
            buffer[i] = NULL;
        }
    }
}
...
...
	if (fd == -3){
		cleanup(buffer);
		return (NULL);
	}
*/
