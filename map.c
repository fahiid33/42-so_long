/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:31:16 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/15 16:16:22 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**last_line(char *str, int i, char **map, int j)
{
	if (str[i] == '\0')
	{
		map[j] = malloc(sizeof(char) * (i + 1));
		map[j] = strncpy(map[j], str, i);
		map[j][i] = '\0';
		j++;
	}
	free(str);
	map[j] = NULL;
	return (map);
}

char	**copy_map(int fd, unsigned int *width)
{
	char	**map;
	char	*str;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * 400);
	str = get_next_line(fd);
	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			map[j] = malloc(sizeof(char) * (i + 1));
			map[j] = strncpy(map[j], str, i);
			map[j][i] = '\0';
			j++;
			i = 0;
			free(str);
			str = get_next_line(fd);
		}
		i++;
	}
	*width = i;
	return (last_line(str, i, map, j));
}

void	check_map(t_vars *mapp)
{
	char	**map;
	int		i;
	int		j;

	map = mapp->map;
	i = 1;
	j = 0;
	while (map[i])
	{
		if (i == 1 || map[i + 1] == NULL)
			str_is_one(map[i]);
		else
			check_sides(map[i]);
		if (i > 1 || map[i + 1] == NULL)
		{
			if (strlen(map[i]) != strlen(map[i - 1]))
				ft_exit("the map is not rectangular");
		}
		i++;
	}
	mapp->h = i - 1;
}

void	check_items(char **map, t_list count, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				count.one++;
			else if (map[i][j] == 'P')
				count.player++;
			else if (map[i][j] == 'E')
				count.exit++;
			else if (map[i][j] == '0')
				count.zero++;
			else if (map[i][j] == 'C')
				count.coin++;
			else if (map[i][j] != '\n')
				ft_exit("invalid item");
			j++;
		}
		i++;
	}
	if (count.player != 1 || count.exit != 1 || count.coin < 1)
		ft_exit("minimum");
}

void	check_map_items(char **map)
{
	t_list	count;
	int		i;
	int		j;

	i = 1;
	count.player = 0;
	count.one = 0;
	count.zero = 0;
	count.coin = 0;
	count.exit = 0;
	check_items(map, count, i, j);
}
