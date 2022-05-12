/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:18:46 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/12 17:47:43 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	put_background(t_vars mlx_vars)
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

void	*put_items_helper(t_vars mlx_vars, void	*mlx_img, int i, int j)
{
	int	k;
	int	z;

	if (mlx_vars.map[i][j] == '0')
			mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,
				"./rbi3a.xpm", &k, &z);
	else if (mlx_vars.map[i][j] == '1')
		mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,
				"./7et.xpm", &k, &z);
	else if (mlx_vars.map[i][j] == 'P')
		mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,
				"./la3ib.xpm", &k, &z);
	else if (mlx_vars.map[i][j] == 'E')
		mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,
				"./lkherja.xpm", &k, &z);
	else if (mlx_vars.map[i][j] == 'C')
		mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,
				"./img.xpm", &k, &z);
	return (mlx_img);
}

void	put_items(t_vars mlx_vars, void *mlx_img, int z, int k)
{
	int		i;
	int		j;

	i = 1;
	while (mlx_vars.map[i])
	{
		j = 0;
		while (mlx_vars.map[i][j])
		{
			mlx_img = put_items_helper(mlx_vars, mlx_img, i, j);
			mlx_put_image_to_window(mlx_vars.mlx_ptr, mlx_vars.mlx_win,
				mlx_img, (j) * 50, (i - 1) * 50);
			j++;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	void		*mlx;
	void		*mlx_img;
	t_vars		mlx_vars;
	int			z;
	int			k;

	mlx_vars.h = 0;
	mlx_vars.w = 0;
	if (check_file(av[1]))
		mlx_vars.map = copy_map(open(av[1], O_RDONLY), &mlx_vars.w);
	else
		ft_exit("the file is not valid");
	check_map(&mlx_vars);
	check_map_items(mlx_vars.map);
	mlx_vars.mlx_ptr = mlx_init();
	mlx_vars.mlx_win = mlx_new_window(mlx_vars.mlx_ptr,
			mlx_vars.w * 50, mlx_vars.h * 50, "so_long");
	put_background(mlx_vars);
	put_items(mlx_vars, mlx_img, z, k);
	mlx_key_hook(mlx_vars.mlx_win, key_hook, &mlx_vars);
	mlx_loop(mlx_vars.mlx_ptr);
}
