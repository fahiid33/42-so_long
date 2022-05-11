/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:32:21 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/11 23:59:16 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	str_is_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
			ft_exit("the map is not closed from top or bottom");
		i++;
	}
}

void	check_sides(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = strlen(s) - 1;
	while (s[i])
	{
		if (i == 0 || i == len)
		{
			if (s[i] != '1')
				ft_exit("the map is not closed from sides");
		}
		i++;
	}
}

int	check_file(char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	str = strrchr(file, '.');
	if (str == NULL || strcmp(".ber", str) != 0)
		return (0);
	return (1);
}

void	swap_player(char **str, int dirc, int x, int y)
{
	if (dirc == 4)
	{
		str[x][y] = '0';
		str[x][y - 1] = 'P';
	}
	else if (dirc == 6)
	{
		str[x][y] = '0';
		str[x][y + 1] = 'P';
	}
	else if (dirc == 8)
	{
		str[x][y] = '0';
		str[x - 1][y] = 'P';
	}
	else if (dirc == 2)
	{
		str[x][y] = '0';
		str[x + 1][y] = 'P';
	}
}

int	*get_player_position(char **str, char c)
{
	int	*tab;

	tab = malloc(8);
	tab[0] = 1;
	tab[1] = 0;
	while (str[tab[0]])
	{
		tab[1] = 0;
		while (str[tab[0]][tab[1]])
		{
			if (str[tab[0]][tab[1]] == c)
				return (tab);
			tab[1]++;
		}
		tab[0]++;
	}
	return (NULL);
}
