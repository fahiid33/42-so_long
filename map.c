/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:31:16 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/08 16:54:29 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	last_line(char *str, int i, char **map, int j)
{
	if (str[i] == '\0')
	{
		map[j] = malloc(sizeof(char) * (i + 1));
		map[j] = strncpy(map[j], str, i);
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
}

char	**copy_map(int fd)
{
	char	**map;
	char	*str;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * 400);
	str = get_next_line(fd);
	i = 0;
	j = 1;
	while(str[i])
	{
		if (str[i] == '\n')
		{
			map[j] = malloc(sizeof(char) * (i + 1));
			map[j] = strncpy(map[j], str, i);
			map[j][i] = '\0';
			j++;
			i = 0;
			str = get_next_line(fd);
		}
		i++;
	}
	last_line(str, i, map, j);
	return (map);
} 

void	check_map(char **map)
{
	int	i;
	int	j;

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
}
void	function(char **map, int i, int j)
{
	t_list count;

	count.player = 0;
	count.one = 0;
	count.zero = 0;
	count.coin = 0;
	count.exit = 0;

	while (map[i][j])
	{
		if (map[i][j] == '1')
			count.one++;
		else if(map[i][j] == 'P')
			count.player++;
		else if(map[i][j] == 'E')
			count.exit++;
		else if(map[i][j] == '0')
			count.zero++;
		else if(map[i][j] == 'C')
			count.coin++;
		else if(map[i][j] != '\n')
			ft_exit("invalid item");
		j++;
	}
	// if(count.player != 1 || count.exit != 1 || count.coin < 1)
	// 	ft_exit("minimum");
}
void	check_map_items(char **map)
{
	int i;
	int j;

	i = 1;
	while(map[i])
	{
		j = 0;
		function(map, i, j);
		i++;
	}
}
