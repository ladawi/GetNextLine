/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:25:27 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/27 18:13:42 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>

static char *useread(int fd, char **line)
{
	char	*tmp;
	char 	*string;

	int		i;
	int		j;
	int buff;
	static char *ok;
	
	i = 0;
	j = -1;

	if (!(ok = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	ok[BUFFER_SIZE] = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	if (!(string = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	if (!(buff = read(fd, string, BUFFER_SIZE)))
		return (0);
	string[buff] = '\0';
	while (string[i] != 0 && string[i] != '\n')
		i++;
	while (++j < i)
		tmp[j] = string[j];
	tmp[j] = 0;
	j = 0;
	i++;

	if (i + j < BUFFER_SIZE)
	{
		while (string[j + i] != 0)
		{
			ok[j] = string[i + j];
			j++;
		}
	}
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static int			j;
	char		*str;
	char		*string;
	int			i;
	
	i = 0;
	j++;
	
	*line = useread(fd, line);

	if (j > 3)
		return (0);
	return (1);
}