/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:28:39 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/23 10:56:51 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nbr_len(int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_rev_tab(char *tab, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc (sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (tab[i])
	{
		tmp[len - i - 1] = tab[i];
		i++;
	}
	tmp[len + 1] = '\0';
	free (tab);
	return (tmp);
}

char	*ft_putnbr(int nb)
{
	char	*nbr;
	int		i;
	int		len;

	i = 0;
	nbr = NULL;
	len = ft_nbr_len(nb);
	nbr = malloc (sizeof(char) * len + 1);
	if (!nbr)
		return (NULL);
	while (nb > 0)
	{
		nbr[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	nbr[len + 1] = '\0';
	nbr = ft_rev_tab(nbr, len);
	return (nbr);
}

int	ft_put_move(t_vars *vars)
{
	char	*move;
	char	*nbr;

	nbr = ft_putnbr(vars->move);
	move = ft_strjoin("Movements : ", nbr, 0);
	ft_put_floor(vars, 0, 0);
	ft_put_floor(vars, 80, 0);
	ft_put_wall(vars, 0, 0);
	ft_put_wall(vars, 80, 0);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0x00FFFF00, move);
	return (0);
}
