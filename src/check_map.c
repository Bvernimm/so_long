/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:31:34 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/24 10:07:20 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(int *x, int *y, int fd, int check)
{
	char	*letter;
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
	check = verif_map(file, x, y);
	if (check == 0)
		return (1);
	start(*x, *y, file, check);
	return (0);
}

int	verif_map(char *file, int *x, int *y)
{
	int	i;
	int	len;
	int	check;

	i = 0;
	len = 0;
	while (file[len] != '\n')
	{
		if (file[i] != '1')
			return (0);
		len++;
	}
	i = verif_map2(file, len, len);
	if (i == -1)
		return (0);
	check = verif_map3(0, file);
	if (check == 0)
		return (0);
	*x = len * 80;
	*y = (i / len) * 80;
	return (check);
}

int	verif_map2(char *file, int i, int len)
{
	int	ret;

	ret = 0;
	while (file[i + 1])
	{
		if (file[i] != '\n' || file[i - 1] != '1' || file[i + 1] != '1')
			return (-1);
		i += len + 1;
	}
	ret = i;
	if (file[i] && file[i] != '\n')
		return (-1);
	i--;
	while (file[i] != '\n')
	{
		if (file[i] != '1')
			return (-1);
		i--;
	}
	return (ret);
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
