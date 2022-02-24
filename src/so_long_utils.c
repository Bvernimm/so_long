/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:07:47 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/24 13:52:53 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd)
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
	return (file);
}

int	ft_counter_split(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_ennemi(t_vars *vars, int *x, int *y)
{
	if (*x == vars->player2x && *y == vars->player2y)
	{
		printf ("Knight wins !\n");
		ft_exit(vars);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *file, char *tmp, int indic)
{
	char	*str;
	int		i;
	int		j;

	if (!file)
	{
		file = malloc(sizeof(char) * 1);
		file[0] = '\0';
	}
	if (!file || !tmp)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(file) + ft_strlen(tmp)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (file[++i])
		str[i] = file[i];
	while (tmp[j])
		str[i++] = tmp[j++];
	str[i] = '\0';
	if (indic == 1)
		free(file);
	return (str);
}
