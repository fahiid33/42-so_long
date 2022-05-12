/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:44:36 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/12 17:44:18 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned long nb, unsigned int i, int *len, char *str)
{
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-', len);
	}
	if (nb < i)
		ft_putchar(str[nb], len);
	else
	{
		ft_putnbr((nb / i), i, len, str);
		ft_putnbr((nb % i), i, len, str);
	}
}
