/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:22:31 by tlavelle          #+#    #+#             */
/*   Updated: 2020/06/15 14:47:11 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*proverka(char **ostatok, char **line)
{
	char *pointer;
	char *leaks;

	pointer = NULL;
	if (*ostatok)
	{
		leaks = *line;
		if ((pointer = ft_strchr(*ostatok, '\n')))
		{
			*pointer++ = '\0';
			*line = ft_strjoin(*line, *ostatok);
			*ostatok = pointer;
		}
		else
		{
			*line = ft_strjoin(*line, *ostatok);
			free(*ostatok);
		}
		free(leaks);
	}
	return (pointer);
}	
			 

int	get_next_line(int fd, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		result;
	char	*endofline;
	static char *ostatok;
	char	*leaks;
	
	*line = ft_strdup("");
	endofline = proverka(&ostatok, line);
	while (!endofline && (result = read(fd, buffer, BUFFER_SIZE)))
	{
		if (result == -1)
			return (result);
		buffer[result] = '\0';
		if ((endofline = ft_strchr(buffer, '\n')))
		{
			*endofline++ = '\0';
			ostatok = ft_strdup(endofline);
		}
		leaks = *line;
		*line = ft_strjoin(*line, buffer);
		free(leaks);
	}
	return (endofline || result > 0);
}

