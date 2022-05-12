/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:18:58 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/12 17:48:27 by fstitou          ###   ########.fr       */
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
# include "ft_printf.h"

typedef struct s_list
{
	int	player;
	int	coin;
	int	one;
	int	zero;
	int	exit;
}	t_list;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			**map;
	int				x;
	unsigned int	w;
	unsigned int	h;
}	t_vars;

char	**copy_map(int fd, unsigned int *width);
void	ft_exit(char *str);
void	check_sides(char *s);
void	check_map(t_vars *map);
int		check_file(char *file);
void	check_map_items(char **map);
void	str_is_one(char *str);
int		*get_player_position(char **str, char c);
int		key_hook(int keycode, t_vars *mlx_vars);
void	swap_player(char **map, int dirc, int x, int y);
#endif