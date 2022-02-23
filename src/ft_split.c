/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:58:31 by bvernimm          #+#    #+#             */
/*   Updated: 2022/02/22 15:48:18 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_sep(char c, char set)
{
	if (c == '\0')
		return (1);
	if (c == set)
		return (1);
	return (0);
}

int	length(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (check_sep(str[i + 1], c) == 1
			&& check_sep(str[i], c) == 0)
			count++;
		i++;
	}
	return (count);
}

void	tab_add(char *tab, char *from, char c)
{
	int	i;

	i = 0;
	while (check_sep(from[i], c) == 0)
	{
		tab[i] = from[i];
		i++;
	}
	tab[i] = '\0';
}

void	*too_many_line(char **tab, char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (check_sep(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep(str[i + j], c) == 0)
				j++;
			tab[k] = (char *) malloc (sizeof(char) * (j + 1));
			if (!tab[k])
				return (NULL);
			tab_add(tab[k], str + i, c);
			k++;
			i = i + j;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;

	if (s == NULL)
		return (NULL);
	count = length((char *)s, c);
	tab = (char **) malloc (sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	if (!(too_many_line(tab, (char *)s, c)))
		return (NULL);
	tab[count] = 0;
	return (tab);
}
