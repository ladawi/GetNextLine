/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:05:00 by ladawi            #+#    #+#             */
/*   Updated: 2019/12/02 02:43:17 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

int		read_file(int fd, char **rest)
{
	char	*str;
	int		buff;

	buff = 1;
	if (ft_strchr(*rest, '\n') != -1)
		return (1);
	if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*str = '\0';
	while (ft_strchr(str, '\n') == -1 && buff > 0)
	{
		buff = read(fd, str, BUFFER_SIZE);
		if (buff >= 0)
		{
			str[buff] = '\0';
			if (!(*rest))
				*rest = ft_substr(str, 0, buff);
			else
			{
				*rest = ft_strjoin(*rest, str);
			}
		}
	}
	free(str);
	return (buff > 0 ? 1 : buff);
}

int		stock_rest(int fd, char **line, char **rest)
{
	char	*to_free;
	int		error;
	int		len;
	
	if (!(line))
		return (-1);
	if ((error = read_file(fd, rest) < 0))
		return (-1);
	len = ft_strchr(*rest, '\n');
	len == -1 ? len = ft_strlen(*rest) : len;
	if ((*line = ft_substr(*rest, 0, len)))
		return (-1);
	to_free = *rest;
	*rest = ft_substr(*rest, len + 1, ft_strlen((*rest) + len + 1));
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
	return (error);
}

int		get_next_line(int fd, char **line)
{
	static char *rest = NULL;
	int			error;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	error = stock_rest(fd, line, &rest);
	if (rest && (error == 0 || error == -1))
	{
		free(rest);
		rest = NULL;
	}
	return (error);
}