/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:18:46 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/11 21:26:53 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
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

void	put_background(vars mlx_vars)
{
	void	*mlx_img;
	int		i;
	int		j;
	int		k;
	int		z;

	i = 1;
	k = 50;
	z = 50;
	while (mlx_vars.map[i])
	{
		j = 0;
		while (mlx_vars.map[i][j])
		{
			mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,
					"./rbi3a.xpm", &k, &z);
			mlx_put_image_to_window(mlx_vars.mlx_ptr, mlx_vars.mlx_win,
				mlx_img, (j) * 50, (i - 1) * 50);
			j++;
		}
		i++;
	}
}

void	put_items(vars mlx_vars, void *mlx_img, int z, int k)
{
	int		i;
	int		j;

	i = 1;
	while (mlx_vars.map[i])
	{
		j = 0;
		while (mlx_vars.map[i][j])
		{
			if (mlx_vars.map[i][j] == '0')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./rbi3a.xpm",
						&k , &z);
			else if (mlx_vars.map[i][j] == '1')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./7et.xpm",
						&k , &z);
			else if (mlx_vars.map[i][j] == 'P')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr, "./la3ib.xpm",
					&k , &z);
			else if (mlx_vars.map[i][j] == 'E')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./lkhrja.xpm",
					&k , &z);
			else if (mlx_vars.map[i][j] == 'C')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./img.xpm",
					&k , &z);	
			mlx_put_image_to_window(mlx_vars.mlx_ptr, mlx_vars.mlx_win,
				mlx_img, (j) * 50, (i - 1) * 50);
			j++;
		}
		i++;		
	}
}

int main(int ac, char *av[])
{
	void 		*mlx;
	void	*mlx_img;
	vars	mlx_vars;
	int			z;
	int			k;

	z = 50;
	k = 50; 
	if (check_file(av[1]))
		mlx_vars.map = copy_map(open(av[1], O_RDONLY));
	else
		ft_exit("the file is not valid");
	check_map(mlx_vars.map);
	check_map_items(mlx_vars.map);
	mlx_vars.mlx_ptr = mlx_init();
	mlx_vars.mlx_win = mlx_new_window(mlx_vars.mlx_ptr, 34 * 50, 8 * 50,
			"so_long");
	put_background(mlx_vars);
	put_items(mlx_vars, mlx_img, z, k);
	mlx_key_hook(mlx_vars.mlx_win, key_hook, &mlx_vars);
	mlx_loop(mlx_vars.mlx_ptr);
}