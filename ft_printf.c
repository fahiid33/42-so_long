/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:58:20 by fahd              #+#    #+#             */
/*   Updated: 2022/05/12 17:55:57 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_arg(const char *s, va_list *arg, int *len, int i)
{
	if (s[i] == 'c')
		ft_putchar(va_arg(*arg, int), len);
	else if (s[i] == 's')
		ft_putstr(va_arg(*arg, char *), len);
	else if (s[i] == 'd' || s[i] == 'i')
		ft_putnbrd(va_arg(*arg, int), len);
	else if (s[i] == 'u')
		ft_putunsigned(va_arg(*arg, unsigned int), 10, len, "0123456789");
	else if (s[i] == 'x')
		ft_putnbr(va_arg(*arg, unsigned int), 16, len, "0123456789abcdef");
	else if (s[i] == 'X')
		ft_putnbr(va_arg(*arg, unsigned int), 16, len, "0123456789ABCDEF");
	else if (s[i] == 'p')
	{
		ft_putstr("0x", len);
		ft_putnbr(va_arg(*arg, unsigned long), 16, len, "0123456789abcdef");
	}
	else
		ft_putchar(s[i], len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			convert_arg(s, &arg, &len, i);
		}
		else
			ft_putchar(s[i], &len);
			i++;
	}
	return (len);
}
