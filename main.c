/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:39:25 by ladawi            #+#    #+#             */
/*   Updated: 2019/11/24 15:11:46 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.c"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		ret;
	char *line;
	int 	fd;
	
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret = %d , <%s>\n", ret, line);
		free(line);
	}
	printf("ret = %d , <%s>\n", ret, line);
	free(line);
	return 0;
}