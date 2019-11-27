/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:39:25 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/27 16:06:47 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line2.c"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		ret;
	char *line;
	int 	fd;
	
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line2(fd, &line)))
	{
		printf("~~ret = %d , {%s}~~\n", ret, line);
		free(line);
	}
	printf("~~ret = %d , {%s}~~\n", ret, line);
	free(line);
	return 0;
}
