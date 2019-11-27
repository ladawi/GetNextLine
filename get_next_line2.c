/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:05:00 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/27 16:32:04 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int		get_next_line2(int fd, char **line)
{
	static char *rest = NULL;
	char 		*str;
	char		*tmp;
	int			i;
	int			j;
	int			buff;
	static int 	test;

	i = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);

	if (!(tmp = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	tmp[BUFFER_SIZE] = 0;
	buff = read(fd, str, BUFFER_SIZE);
	str[buff] = 0;
	str = ft_strjoin(rest, str);
	while (str[i] != '\n' && str[i] != 0)
	{
		tmp[j] = str[i];
		i++;
		printf("[tmp[j] = %c]", tmp[j]);
		printf ("[buff == %d]\n", buff);
		j++;
		if (str[i] == 0)
		{
			if (!(buff = read(fd, str, BUFFER_SIZE)))
			{
				*line = tmp;
				return (0);
			}
			i = 0;
		}
	}
	tmp[j] = 0;
	(str[i] == '\n') ? i++ : 0;
	printf("[tmp = %s]\n", tmp);
	*line = tmp;
	tmp = rest;
	if (!(rest = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	rest = ft_substr(str, i, ft_strlen(str) - i);
	test++;
	if (buff == 0)
		return (0);
	return (1);
}