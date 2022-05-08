/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:32:21 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/08 15:34:25 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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