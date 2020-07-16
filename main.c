/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:09:44 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/16 13:22:17 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		i;
//	int		j = 1;

	fd = open("files/alphabet", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		if (i < 0)
			break ;
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	/*fd = open("half_marge_bottom", O_RDONLY);
	while ((result = get_next_line(fd, &line)))
	{
		if (result < 0)
			break ;
		printf("%s\n", line);
		//printf("%d\n", result);
		free(line);
	}*/
/*	int fd2;

	if (!(fd = open("files/half_marge_top", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	if (!(fd2 = open("files/half_marge_bottom", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	free(line);
	while ((i = get_next_line(fd2, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);*/
	return (0);
}
