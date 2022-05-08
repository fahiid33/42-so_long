
#include "so_long.h"
#include "get_next_line.h"

void	ft_exit(char *str)
{
	printf("%s\n",str);
	exit(0);
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
	if (str[i] == '\0')
	{
		map[j] = malloc(sizeof(char) * (i + 1));
		map[j] = strncpy(map[j], str, i);
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
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
void	str_is_one(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] != '1' && str[i] != '\n')
			ft_exit("the map is not closed from top or bottom");
		i++;
	}
}
void	check_map(char **map)
{
	int	i;
	int	j;
	int	len;

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

void	check_map_items(char **map)
{
	int i;
	int j;
	t_list count;
	count.player = 0;
	count.one = 0;
	count.zero = 0;
	count.coin = 0;
	count.exit = 0;
	i = 1;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '1')
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
		i++;
	}
	if(count.player != 1 || count.exit != 1 || count.coin < 1)
		ft_exit("minimum");
}

int main(int ac, char *av[])
{
	char	**map;
	if (check_file(av[1]))
		map = copy_map(open(av[1], O_RDONLY));
	else
		ft_exit("the file is not valid");
	check_map(map);
	check_map_items(map);
}