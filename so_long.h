#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_list
{
	int	player;
	int	coin;
	int	one;
	int	zero;
	int	exit;
}	t_list;

char	**copy_map(int fd);
void	ft_exit(char *str);
void	check_sides(char *s);
void	check_map(char **map);
int		check_file(char *file);
#endif