/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:15:38 by fstitou           #+#    #+#             */
/*   Updated: 2021/12/02 23:54:16 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putnbrd(long nb, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(const char *str, int *len);
void	ft_putnbr(unsigned long nb, unsigned int i, int *len, char *str);
void	ft_putunsigned(unsigned int nb, unsigned int i, int *len, char *str);

#endif