/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:38:44 by fstitou           #+#    #+#             */
/*   Updated: 2022/05/12 17:44:36 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrd(long nb, int *len)
{
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-', len);
	}
	if (nb < 10)
		ft_putchar(nb + '0', len);
	else
	{
		ft_putnbrd((nb / 10), len);
		ft_putnbrd((nb % 10), len);
	}
}
