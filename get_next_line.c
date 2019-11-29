/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:05:00 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/29 15:31:57 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

int		test(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char *rest = NULL;
	char 		*str;
	char		*tmp;
	int			i;
	int			j;
	int			buff;

	i = 0;
	j = 0;
	if (fd < 0)
		return (-1);
	if (!(str = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	buff = read(fd, str, BUFFER_SIZE);
	str[buff] = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	tmp[BUFFER_SIZE] = 0;
	str = ft_strjoin(rest, str);
	while (str[i] != '\n')
	{
		if (str[i] == 0)
		{
			tmp = ft_strjoin(tmp, str);
			buff = read(fd, str, BUFFER_SIZE);
			if (buff < 0)
				return (-1);
			if (buff == 0)
			{
				*line = tmp;
				return (0);
			}
		}
		i++;
		// tmp[j] = str[i];
		// i++;
		// j++;
		// if (str[i] == 0 && buff != 0)
		// {
		// 	buff = read(fd, str, BUFFER_SIZE);
		// 	if (buff < 0)
		// 		return (-1);
		// 	if (buff == 0)
		// 	{
		// 		*line = tmp;
		// 		return (0);
		// 	}
		// 	str[buff] = 0;
		// 	i = 0;
		// }

	}
	tmp[j] = 0;
	(str[i] == '\n') ? i++ : 0;
	*line = tmp;
	rest = ft_substr(str, i, ft_strlen(str) - i);
	if (buff == 0 && str[i] == 0)
	{
		return (0);
	}
	return (1);
}