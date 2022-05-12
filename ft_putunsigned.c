/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:57:07 by fstitou           #+#    #+#             */
/*   Updated: 2021/12/02 21:22:28 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int nb, unsigned int i, int *len, char *str)
{
	if (nb < i)
		ft_putchar(str[nb], len);
	else
	{
		ft_putnbr((nb / i), i, len, str);
		ft_putnbr((nb % i), i, len, str);
	}
}
