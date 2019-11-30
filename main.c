/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:39:25 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/30 11:01:34 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		ret;
	char *line;
	int 	fd;
	
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("~~ret = %d , {%s}~~\n", ret, line);
		free(line);
	}
	printf("~~ret = %d , {%s}~~\n", ret, line);
	free(line);
	return 0;
}
