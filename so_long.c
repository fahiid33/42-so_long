/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:18:46 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/09 18:25:07 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

typedef struct {
	void* mlx_ptr;
	void* mlx_win;
	char **map;
}vars;

void	ft_exit(char *str)
{
	printf("%s\n",str);
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

void swap_player(char **str, int dirc, int x, int y)
{
	char temp;

	if (dirc == 4)
	{
		str[x][y] = '0';
		str[x][y-1] = 'P';
		
	}
	else if (dirc == 6)
	{
		str[x][y]  = '0';
		str[x][y+1]  = 'P';
	}
	else if (dirc == 8)
	{
		str[x][y]  = '0';
		str[x-1][y]  = 'P';
		printf("%c-\n",str[x-1][y]);
	}
	else if (dirc == 2)
	{
		str[x][y]  = '0';
		str[x+1][y]  = 'P';
	}
	
}
int key_hook(int keycode, vars *mlx_vars)
{
	int	*tab;
	int	k;
	int	z;
	int len;
	
	tab = get_player_position(mlx_vars->map, 'P');
	len = strlen(mlx_vars->map[1]);

	if (keycode == 124)
	{
		if (mlx_vars->map[tab[0]][tab[1] + 1] != 49)
		{
			if (mlx_vars->map[tab[0]][tab[1] + 1] == 69)
				ft_exit("");
			swap_player(mlx_vars->map, 6, tab[0], tab[1]);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./rbi3a.xpm" ,&k , &z), (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./la3ib.xpm" ,&k , &z), (tab[1] + 1) * 50, (tab[0] - 1) * 50);
		}
	}
	else if (keycode == 123)
	{
		if (mlx_vars->map[tab[0]][tab[1] - 1] != 49)
		{
			if (mlx_vars->map[tab[0]][tab[1] - 1] == 69)
				ft_exit("");
			swap_player(mlx_vars->map, 4, tab[0], tab[1]);
			printf("%d\n", keycode);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./rbi3a.xpm" ,&k , &z), (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./la3ib.xpm" ,&k , &z), (tab[1] - 1) * 50, (tab[0] - 1) * 50);
		}

	}
	else if (keycode == 125)
	{
		if (mlx_vars->map[tab[0] + 1][tab[1]] != 49 )
		{
			if (mlx_vars->map[tab[0] + 1][tab[1]] == 69)
				ft_exit("");
			swap_player(mlx_vars->map, 2, tab[0], tab[1]);
			printf("%d\n", keycode);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./rbi3a.xpm" ,&k , &z), (tab[1]) * 50, (tab[0] - 1) * 50);
			mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./la3ib.xpm" ,&k , &z), (tab[1]) * 50, (tab[0]) * 50);
		}
	}
	else if (keycode == 126)
	{
		printf("%d\n", keycode);
		if (mlx_vars->map[tab[0] - 1][tab[1]] != 49)
		{
			if (mlx_vars->map[tab[0] - 1][tab[1]] != 69 )
			{
				swap_player(mlx_vars->map, 8, tab[0], tab[1]);
				printf("%d\n", keycode);
				mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./rbi3a.xpm" ,&k , &z), (tab[1]) * 50, (tab[0] - 1) * 50);
				mlx_put_image_to_window(mlx_vars->mlx_ptr, mlx_vars->mlx_win, mlx_xpm_file_to_image(mlx_vars->mlx_ptr,"./la3ib.xpm" ,&k , &z), (tab[1]) * 50, (tab[0] - 2) * 50);
			}
			else if (get_player_position(mlx_vars->map, 'C') == NULL && mlx_vars->map[tab[0] - 1][tab[1]] == 69)
				ft_exit("");
			
		}
	}
	else if (keycode == 53)
		ft_exit("");
	return 0;
}
	
int	*get_player_position(char **str, char c)
{
	int *tab;

	tab = malloc(8);
	tab[0] = 1;
	tab[1] = 0;
	
	while(str[tab[0]])
	{
		tab[1] = 0;
		while(str[tab[0]][tab[1]])
		{
	
			if (str[tab[0]][tab[1]]== c)
				return tab;
			tab[1]++;
		}
		tab[0]++;
	}
	return NULL;
}
int main(int ac, char *av[])
{
	void *mlx;
	char **map1;
	int i = 1;
	int j;
	int k;
	k = 50;
	int z = 50;
	void	*mlx_img;
	vars mlx_vars;

	
	if (check_file(av[1]))
		mlx_vars.map = copy_map(open(av[1], O_RDONLY));
	else
		ft_exit("the file is not valid");
	check_map(mlx_vars.map);
	check_map_items(mlx_vars.map);
	mlx_vars.mlx_ptr = mlx_init();
	mlx_vars.mlx_win = mlx_new_window(mlx_vars.mlx_ptr, 34 * 50, 6 * 50, "so_long");
	mlx_clear_window(mlx_vars.mlx_ptr, mlx_vars.mlx_win);
	while (mlx_vars.map[i])
	{
		j = 0;
		while (mlx_vars.map[i][j])
		{
			if (mlx_vars.map[i][j] == '0')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./rbi3a.xpm" ,&k , &z);
			else if (mlx_vars.map[i][j] == '1')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./7et.xpm" ,&k , &z);
			else if (mlx_vars.map[i][j] == 'P')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./la3ib.xpm" ,&k , &z);
			else if (mlx_vars.map[i][j] == 'E')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./lkherja.xpm" ,&k , &z);
			else if (mlx_vars.map[i][j] == 'C')
				mlx_img = mlx_xpm_file_to_image(mlx_vars.mlx_ptr,"./img.xpm" ,&k , &z);	
			mlx_put_image_to_window(mlx_vars.mlx_ptr, mlx_vars.mlx_win, mlx_img, (j) * 50, (i - 1) * 50);
			j++;
		}
		i++;
		
	}
	mlx_key_hook(mlx_vars.mlx_win, key_hook, &mlx_vars);
	mlx_loop(mlx_vars.mlx_ptr);
	
	
	
}