/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:00:34 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/23 13:08:19 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rm_img(t_wall *img1, t_vars *vars, int x, int y)
{
	t_wall	img;

	img.path = "./image/floor_dirty.xpm";
	img.img = mlx_xpm_file_to_image(vars->mlx, img.path, &img.w, &img.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, x, y);
	if (img1->img == NULL)
		return (0);
	mlx_destroy_image(vars->mlx, img1->img);
	mlx_destroy_image(vars->mlx, img.img);
	return (1);
}

int	go_up(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img(img, vars, *x, *y);
	*y -= 80;
	vars->move++;
	ft_ennemi(vars, x, y);
	if (vars->map[*y / 80][*x / 80] == '1'
			|| (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible > 0))
	{
		*y += 80;
		vars->move--;
	}
	else
		ft_put_move(vars);
	if (vars->map[*y / 80][*x / 80] == 'C')
	{
		vars->collectible--;
		vars->map[*y / 80][*x / 80] = '0';
	}
	if (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible <= 0)
		ft_exit(vars);
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}

int	go_right(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img(img, vars, *x, *y);
	*x -= 80;
	vars->move++;
	ft_ennemi(vars, x, y);
	if (vars->map[*y / 80][*x / 80] == '1'
			|| (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible > 0))
	{
		*x += 80;
		vars->move--;
	}
	else
		ft_put_move(vars);
	if (vars->map[*y / 80][*x / 80] == 'C')
	{
		vars->collectible--;
		vars->map[*y / 80][*x / 80] = '0';
	}
	if (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible <= 0)
		ft_exit(vars);
	img->path = "./image/slime2.XPM";
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}

int	go_down(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img(img, vars, *x, *y);
	*y += 80;
	vars->move++;
	ft_ennemi(vars, x, y);
	if (vars->map[*y / 80][*x / 80] == '1'
			|| (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible > 0))
	{
		*y -= 80;
		vars->move--;
	}
	else
		ft_put_move(vars);
	if (vars->map[*y / 80][*x / 80] == 'C')
	{
		vars->collectible--;
		vars->map[*y / 80][*x / 80] = '0';
	}
	if (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible <= 0)
		ft_exit(vars);
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}

int	go_left(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img(img, vars, *x, *y);
	*x += 80;
	vars->move++;
	ft_ennemi(vars, x, y);
	if (vars->map[*y / 80][*x / 80] == '1'
			|| (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible > 0))
	{
		*x -= 80;
		vars->move--;
	}
	else
		ft_put_move(vars);
	if (vars->map[*y / 80][*x / 80] == 'C')
	{
		vars->collectible--;
		vars->map[*y / 80][*x / 80] = '0';
	}
	if (vars->map[*y / 80][*x / 80] == 'E' && vars->collectible <= 0)
		ft_exit(vars);
	img->path = "./image/slime1.XPM";
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}
