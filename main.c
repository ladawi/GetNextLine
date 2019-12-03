/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:39:25 by ladawi            #+#    #+#             */
/*   Updated: 2019/12/03 21:26:25 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		ret;
	int		ret2;
	char *line;
	char *line2;
	int 	fd;
	int 	fd2;
	
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	ret = 1;
	ret2 = 1;
	while (ret > 0 && ret2 > 0)
	{
		ret = get_next_line(fd, &line);
		printf("~~ret = %d , {%s}~~\n", ret, line);
		ret2 = get_next_line(fd2, &line2);
		printf("~~ret = %d , {%s}~~\n", ret, line2);
		free(line);
	}
	return 0;
}
