/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:51:03 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/24 13:20:57 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(char *map, t_vars *vars, int x, int y)
{
	int	i;
	int	player;

	i = 0;
	player = 1;
	vars->collectible = 0;
	while (map[i])
	{
		ft_put_floor(vars, x, y);
		if (map[i] == '1')
			ft_put_wall(vars, x, y);
		if (map[i] == 'P')
			ft_put_slime(vars, x, y, &player);
		if (map[i] == 'C')
			ft_put_pot(vars, x, y);
		if (map[i] == 'E')
			ft_put_exit(vars, x, y);
		x += 80;
		if (map[i] == '\n')
		{
			x = 0;
			y += 80;
		}
		i++;
	}
}
