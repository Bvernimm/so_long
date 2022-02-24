/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:32:21 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/24 10:03:58 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <libc.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		playerx;
	int		playery;
	int		player2x;
	int		player2y;
	int		collectible;
	int		move;
}				t_vars;

typedef struct s_wall {
	void	*img;
	char	*path;
	int		w;
	int		h;
}				t_wall;

void	start(int x, int y, char *map, int player_nbr);
int		do_stuff_player1(int keycode, t_vars *vars);
int		ft_exit(t_vars *vars);
int		rm_img(t_wall *img1, t_vars *vars, int x, int y);
int		go_up(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_right(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_down(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_left(t_wall *img1, t_vars *vars, int *x, int *y);
int		rm_img2(t_wall *img1, t_vars *vars, int x, int y);
int		go_up2(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_right2(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_down2(t_wall *img1, t_vars *vars, int *x, int *y);
int		go_left2(t_wall *img1, t_vars *vars, int *x, int *y);
void	ft_ennemi(t_vars *vars, int *x, int *y);
int		ft_put_move(t_vars *vars);
char	*ft_putnbr(int nb);
char	*ft_rev_tab(char *tab, int len);
int		ft_nbr_len(int nb);
void	make_map(char *map, t_vars *vars, int x, int y);
void	ft_put_wall(t_vars *vars, int x, int y);
void	ft_put_floor(t_vars *vars, int x, int y);
void	ft_put_pot(t_vars *vars, int x, int y);
void	ft_put_exit(t_vars *vars, int x, int y);
void	ft_put_slime(t_vars *vars, int x, int y, int *player);
char	*ft_strjoin(char *file, char *tmp, int indic);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		check_map(int *x, int *y, int fd, int check);
int		verif_map(char *file, int *x, int *y);
int		verif_map2(char *file, int i, int len);
int		verif_map3(int i, char *file);
#endif
