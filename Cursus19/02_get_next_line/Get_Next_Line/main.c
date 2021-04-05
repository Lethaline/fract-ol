/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 16:10:27 by lethaline         #+#    #+#             */
/*   Updated: 2021/04/05 04:47:02 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	(void)ac;
	ret = 0;
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		printf("%s\n", line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}
