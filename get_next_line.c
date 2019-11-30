/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:05:00 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/30 13:21:58 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

int		read_file(int fd, char **line)
{
	char	*str;
	int		buff;

	buff = 1;
	if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*str = '\0';
	while (ft_strchr(str, '\n') == -1 && buff > 0)
	{
		buff = read(fd, str, BUFFER_SIZE);
		ft_strjoin(*line, str);
	}
	free(str);
	return (buff > 0 ? 1 : buff);
}

int		get_next_line(int fd, char **line)
{
	static char *rest = NULL;
	int			buff;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	buff = read_file(fd, &line);
	if (buff == 0)
	{
		return (0);
	}
	return (1);
}