/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:09:21 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/24 13:10:40 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("Movements : %d\n", vars->move);
	printf("exit\n");
	exit (0);
	return (0);
}

int	do_stuff_player2(int keycode, t_vars *vars)
{
	static t_wall	img2;

	if (!img2.path)
		img2.path = "./image/knight1.xpm";
	if (keycode == 126)
		go_up2(&img2, vars, &vars->player2x, &vars->player2y);
	else if (keycode == 123)
		go_right2(&img2, vars, &vars->player2x, &vars->player2y);
	else if (keycode == 125)
		go_down2(&img2, vars, &vars->player2x, &vars->player2y);
	else if (keycode == 124)
		go_left2(&img2, vars, &vars->player2x, &vars->player2y);
	else
		do_stuff_player1(keycode, vars);
	return (0);
}

int	do_stuff_player1(int keycode, t_vars *vars)
{
	static t_wall	img1;

	if (!img1.path)
		img1.path = "./image/slime1.xpm";
	if (keycode == 53)
		ft_exit(vars);
	if (keycode == 13 || keycode == 126)
		go_up(&img1, vars, &vars->playerx, &vars->playery);
	if (keycode == 0 || keycode == 123)
		go_right(&img1, vars, &vars->playerx, &vars->playery);
	if (keycode == 1 || keycode == 125)
		go_down(&img1, vars, &vars->playerx, &vars->playery);
	if (keycode == 2 || keycode == 124)
		go_left(&img1, vars, &vars->playerx, &vars->playery);
	return (0);
}

char	*ft_reee(char **map)
{
	char	*line;
	int		i;

	i = 0;
	while (map[i])
	{
		line = ft_strjoin(line, map[i], 1);
		line = ft_strjoin(line, "\n", 1);
		i++;
	}
	return (line);
}

void	start(int x, int y, char **map, int player_nbr)
{
	t_vars	data;

	data.move = 0;
	data.map = map;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, x, y, "So_long");
	make_map(ft_reee(map), &data, 0, 0);
	if (player_nbr == 2)
		data.collectible--;
	if (player_nbr == 1)
		mlx_key_hook(data.win, do_stuff_player1, &data);
	if (player_nbr == 2)
		mlx_key_hook(data.win, do_stuff_player2, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_exit, &data);
	mlx_loop(data.mlx);
}
