/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:22:31 by tlavelle          #+#    #+#             */
/*   Updated: 2020/07/13 15:57:05 by tlavelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_rem(char **rem, char **line)
{
	char	*ptr;
	int		len;

	if (*rem)
	{
		if ((ptr = ft_strchr(*rem, '\n')))
		{
			*ptr++ = '\0';
			*line = ft_strdup(*rem);
			len = ft_strlen(ptr);
			*rem = ft_memcpy(*rem, ptr, len + 1);
		}
		else
		{
			if (**rem == '\0')
			{
				free(*rem);
				*rem = NULL;
				return ;
			}
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
		}
	}
}

void	add_line(char **rem, int br, char **line, char *buff)
{
	char *leaks;
	
	buff[br] = '\0';
	if ((*rem = ft_strchr(buff, '\n')))
	{
		**rem = '\0';
		*rem = *rem + 1;
		*rem = ft_strdup(*rem);
	}
	if (*line == NULL)
		*line = ft_strdup(buff);
	else
	{
		leaks = *line;
		*line = ft_strjoin(*line, buff);
		free(leaks);
	}
}
int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			byrd;
	static char	*rem;

	*line = NULL;
	add_rem(&rem, line);
	while (!rem && (byrd = read(fd, buff, BUFFER_SIZE)))
	{
		if (byrd == -1)
			return (byrd);
		add_line(&rem, byrd, line, buff);	
	}
	return (rem != NULL || byrd > 0 || *line != NULL);
}
