/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:29:02 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/12 23:01:23 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	move_right(t_vars *mlx_vars, int *tab)
{
	void	*mlx_img;
	int		k;
	int		z;

	if (mlx_vars->map[tab[0]][tab[1] + 1] != 49)
	{
		if (mlx_vars->map[tab[0]][tab[1] + 1] != 69)
		{
			swap_player(mlx_vars->map, 6, tab[0], tab[1]);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./rbi3a.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./la3ib.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1] + 1) * 50, (tab[0] - 1) * 50);
			mlx_vars->x++;
			ft_printf("%d\n", mlx_vars->x);
		}
		else if (get_player_position(mlx_vars->map, 'C') == NULL
			&& mlx_vars->map[tab[0]][tab[1] + 1] == 69)
			ft_exit("");
	}
}

void	move_left(t_vars *mlx_vars, int *tab)
{
	void	*mlx_img;
	int		k;
	int		z;

	if (mlx_vars->map[tab[0]][tab[1] - 1] != 49)
	{
		if (mlx_vars->map[tab[0]][tab[1] - 1] != 69)
		{
			swap_player(mlx_vars->map, 4, tab[0], tab[1]);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./rbi3a.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./la3ib.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1] - 1) * 50, (tab[0] - 1) * 50);
			mlx_vars->x++;
			ft_printf("%d\n", mlx_vars->x);
		}
		else if (get_player_position(mlx_vars->map, 'C') == NULL
			&& mlx_vars->map[tab[0]][tab[1] - 1] == 69)
			ft_exit("");
	}
}

void	move_down(t_vars *mlx_vars, int *tab)
{
	void	*mlx_img;
	int		k;
	int		z;

	if (mlx_vars->map[tab[0] + 1][tab[1]] != 49)
	{
		if (mlx_vars->map[tab[0] + 1][tab[1]] != 69)
		{
			swap_player(mlx_vars->map, 2, tab[0], tab[1]);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./rbi3a.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./la3ib.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1]) * 50, (tab[0]) * 50);
			mlx_vars->x++;
			ft_printf("%d\n", mlx_vars->x);
		}
		else if (get_player_position(mlx_vars->map, 'C') == NULL
			&& mlx_vars->map[tab[0] + 1][tab[1]] == 69)
			ft_exit("");
	}
}

void	move_up(t_vars *mlx_vars, int *tab)
{
	void	*mlx_img;
	int		k;
	int		z;

	if (mlx_vars->map[tab[0] - 1][tab[1]] != 49)
	{
		if (mlx_vars->map[tab[0] - 1][tab[1]] != 69)
		{
			swap_player(mlx_vars->map, 8, tab[0], tab[1]);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./rbi3a.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx_img = mlx_xpm_file_to_image(mlx_vars->mlx_ptr, "./la3ib.xpm",
					&k, &z);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win,
				mlx_img, (tab[1]) * 50, (tab[0] - 2) * 50);
			mlx_vars->x++;
			ft_printf("%d\n", mlx_vars->x);
		}
		else if (get_player_position(mlx_vars->map, 'C') == NULL
			&& mlx_vars->map[tab[0] - 1][tab[1]] == 69)
			ft_exit("");
	}
}

int	key_hook(int keycode, t_vars *mlx_vars)
{
	int	*tab;
	int	k;
	int	z;

	tab = get_player_position(mlx_vars->map, 'P');
	if (keycode == 124 || keycode == 2)
		move_right(mlx_vars, tab);
	else if (keycode == 123 || keycode == 0)
		move_left(mlx_vars, tab);
	else if (keycode == 125 || keycode == 1)
		move_down(mlx_vars, tab);
	else if (keycode == 126 || keycode == 13)
		move_up(mlx_vars, tab);
	else if (keycode == 53)
		ft_exit("");
	return (0);
}
