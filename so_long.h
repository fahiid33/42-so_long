/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:18:58 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/09 20:05:32 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_list
{
	int	player;
	int	coin;
	int	one;
	int	zero;
	int	exit;
}	t_list;
typedef struct 
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
}	vars;

char	**copy_map(int fd);
void	ft_exit(char *str);
void	check_sides(char *s);
void	check_map(char **map);
int		check_file(char *file);
void	check_map_items(char **map);
void	str_is_one(char *str);
int		*get_player_position(char **str, char c);
#endif