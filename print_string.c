/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:42:30 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/18 22:00:42 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_minus_zero(t_flags *flags, int zero, int space)
{
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
}

void	print_minus_space(t_flags *flags, int space)
{
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void	print_string(va_list ap, t_flags *flags)
{
	char	*str;
	int		len;
	int		space;
	int		zero;

	str = va_arg(ap, char *);
	zero = 0;
	space = 0;
	if (!str)
		str = "(null)";
	if (flags->precision > 0 && flags->precision < (int)ft_strlen(str))
		len = flags->precision;
	else if (flags->dot && !flags->precision)
		len = 0;
	else
		len = ft_strlen(str);
	if (flags->width > len && flags->zero)
		zero = flags->width - len;
	if (flags->width > len && !zero)
		space = flags->width - len;
	flags->ret += len + space + zero;
	print_minus_zero(flags, zero, space);
	while (len--)
		ft_putchar_fd(*str++, 1);
	print_minus_space(flags, space);
}
