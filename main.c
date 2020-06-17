#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char *line;
	int fd;
	int result;

	fd = open("textfile", O_RDONLY);
//	result = get_next_line(fd, &line);
/*	printf("%s\n", line);
	printf("%d\n", result);
	result = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("%d\n", result);
	result = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("%d\n", result);
	result = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("%d\n", result);*/
	while ((result = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		printf("%d\n", result);
		free(line);
	}
	printf("%d\n", result);
	return (0);
}
