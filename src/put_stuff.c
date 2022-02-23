/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:13:04 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/23 13:14:09 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wall(t_vars *vars, int x, int y)
{
	t_wall	img1;

	img1.path = "./image/barrel.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_floor(t_vars *vars, int x, int y)
{
	t_wall	img1;

	img1.path = "./image/floor_1.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_pot(t_vars *vars, int x, int y)
{
	t_wall	img1;

	vars->collectible++;
	img1.path = "./image/potion_red.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_slime(t_vars *vars, int x, int y, int *player)
{
	t_wall	img1;

	if (*player == 1)
	{
		img1.path = "./image/slime1.xpm";
		vars->playerx = x;
		vars->playery = y;
		*player = 2;
	}
	else if (*player == 2)
	{
		img1.path = "./image/knight1.xpm";
		vars->player2x = x;
		vars->player2y = y;
	}
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}

void	ft_put_exit(t_vars *vars, int x, int y)
{
	t_wall	img1;

	img1.path = "./image/exit.xpm";
	img1.img = mlx_xpm_file_to_image(vars->mlx, img1.path, &img1.w, &img1.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img1.img, x, y);
	mlx_destroy_image(vars->mlx, img1.img);
}
