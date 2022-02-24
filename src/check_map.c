/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:31:34 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/24 13:24:27 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(int *x, int *y, int fd, int check)
{
	char	*letter;
	char	**map;
	char	*file;
	int		nbr_read;

	letter = malloc (sizeof(char) * 2);
	file = NULL;
	nbr_read = 1;
	while (nbr_read != 0)
	{
		nbr_read = read(fd, letter, 1);
		if (nbr_read < 0)
			exit (0);
		if (nbr_read == 0)
			break ;
		letter[1] = '\0';
		file = ft_strjoin(file, letter, 1);
		if (!file)
			exit (0);
	}
	free (letter);
	map = ft_split(file, '\n');
	check = verif_map(file, map, x, y);
	if (check == -1)
		return (1);
	start(*x, *y, map, check);
	return (0);
}

int	check_border_line(char *line, int len)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		else
			i++;
	}
	if (i != len)
		return (0);
	return (1);
}

int	check_middle_line(char *line, int len)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'C' && line[i] != 'E')
			return (0);
		else
			i++;
	}
	if (line[i - 1] != '1')
		return (0);
	if (i != len)
		return (0);
	return (1);
}

int	verif_map(char *file, char **map, int *x, int *y)
{
	int	i;
	int	len;
	int	check;

	len = ft_strlen(map[0]);
	i = 1;
	if (check_border_line(map[0], len) == 0)
		return (-1);
	while (map[i + 1])
	{
		if (check_middle_line(map[i], len) == 0)
			return (-1);
		else
			i++;
	}
	if (check_border_line(map[i], len) == 0)
		return (-1);
	check = verif_map3(0, file);
	if (check == 0)
		return (-1);
	*x = len * 80;
	*y = (i + 1) * 80;
	return (check);
}

int	verif_map3(int i, char *file)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	while (file[i])
	{
		if (file[i] != '1' && file[i] != '0' && file[i] != 'E'
			&& file[i] != 'C' && file[i] != 'P' && file[i] != '\n')
			return (0);
		if (file[i] == 'E')
			e++;
		if (file[i] == 'C')
			c++;
		if (file[i] == 'P')
			p++;
		i++;
	}
	if (e <= 0 || c <= 0 || (p != 1 && p != 2))
		return (0);
	if (p == 2)
		return (2);
	return (1);
}
