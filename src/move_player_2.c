/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:15:32 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/23 13:15:36 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rm_img2(t_wall *img1, t_vars *vars, int x, int y)
{
	t_wall	img;

	img.path = "./image/floor_1.xpm";
	img.img = mlx_xpm_file_to_image(vars->mlx, img.path, &img.w, &img.h);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, x, y);
	if (img1->img == NULL)
		return (0);
	mlx_destroy_image(vars->mlx, img1->img);
	mlx_destroy_image(vars->mlx, img.img);
	return (1);
}

int	go_up2(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img2(img, vars, *x, *y);
	*y -= 80;
	if (*x == vars->playerx && *y == vars->playery)
	{
		printf ("Knight wins !\n");
		ft_exit(vars);
	}
	if (vars->map[*y / 80][*x / 80] == '1'
			|| vars->map[*y / 80][*x / 80] == 'E'
			|| vars->map[*y / 80][*x / 80] == 'C')
		*y += 80;
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}

int	go_right2(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img2(img, vars, *x, *y);
	*x -= 80;
	if (*x == vars->playerx && *y == vars->playery)
	{
		printf ("Knight wins !\n");
		ft_exit(vars);
	}
	if (vars->map[*y / 80][*x / 80] == '1'
			|| vars->map[*y / 80][*x / 80] == 'E'
			|| vars->map[*y / 80][*x / 80] == 'C')
		*x += 80;
	img->path = "./image/knight2.XPM";
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}

int	go_down2(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img2(img, vars, *x, *y);
	*y += 80;
	if (*x == vars->playerx && *y == vars->playery)
	{
		printf ("Knight wins !\n");
		ft_exit(vars);
	}
	if (vars->map[*y / 80][*x / 80] == '1'
			|| vars->map[*y / 80][*x / 80] == 'E'
			|| vars->map[*y / 80][*x / 80] == 'C')
		*y -= 80;
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}

int	go_left2(t_wall *img, t_vars *vars, int *x, int *y)
{
	rm_img2(img, vars, *x, *y);
	*x += 80;
	if (*x == vars->playerx && *y == vars->playery)
	{
		printf ("Knight wins !\n");
		ft_exit(vars);
	}
	if (vars->map[*y / 80][*x / 80] == '1'
			|| vars->map[*y / 80][*x / 80] == 'E'
			|| vars->map[*y / 80][*x / 80] == 'C')
		*x -= 80;
	img->path = "./image/knight1.XPM";
	img->img = mlx_xpm_file_to_image(vars->mlx, img->path, &img->w, &img->h);
	if (img->img == NULL)
		return (1);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, *x, *y);
	return (0);
}
