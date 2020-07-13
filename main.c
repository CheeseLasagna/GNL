/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:09:44 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/13 16:18:54 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		result;

	fd = open("files/huge_file", O_RDONLY);
	while ((result = get_next_line(fd, &line)))
	{
		if (result < 0)
			break ;
		printf("%s\n", line);
		//printf("%d\n", result);
		free(line);
	}
	/*fd = open("half_marge_bottom", O_RDONLY);
	while ((result = get_next_line(fd, &line)))
	{
		if (result < 0)
			break ;
		printf("%s\n", line);
		//printf("%d\n", result);
		free(line);
	}*/
	return (0);
}
