/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:59:42 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/23 11:14:34 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*file_path;
	int		x;
	int		y;
	int		fd;

	x = 0;
	y = 0;
	if (argc != 2)
	{
		printf ("error");
		exit (0);
	}
	file_path = ft_strjoin("./map/", argv[1], 0);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open the map\n");
		exit (0);
	}
	if (check_map(&x, &y, fd, 0) == 1)
	{
		printf ("Error, map invalid\n");
		exit (0);
	}
	close (fd);
}
