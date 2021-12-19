/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:41:45 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/19 11:29:29 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->negative = 0;
	flags->dot = 0;
}

static void	handle_conversions(const char *format, va_list ap, t_flags *flags)
{
	flags->index++;
	if (format[flags->index] == 'c')
		print_char(ap, flags);
	else if (format[flags->index] == 's')
		print_string(ap, flags);
	else if (format[flags->index] == 'p')
		print_pointer(ap, flags);
	else if (format[flags->index] == 'd' || format[flags->index] == 'i')
		print_di(ap, format[flags->index], flags);
	else if (format[flags->index] == 'u' || format[flags->index] == 'x'\
		||format[flags->index] == 'X')
		print_ux(ap, format[flags->index], flags);
	else if (format[flags->index] == '%')
		print_percent(flags);
	else
	{
		write(1, "%", 1);
		flags->index--;
		flags->ret++;
	}
	init_flags(flags);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;

	flags.index = 0;
	flags.ret = 0;
	init_flags(&flags);
	va_start(ap, format);
	while (format[flags.index])
	{
		if (format[flags.index] == '%')
			handle_conversions(format, ap, &flags);
		else
		{
			ft_putchar_fd(format[flags.index], 1);
			flags.ret++;
		}
		flags.index++;
	}
	va_end(ap);
	return (flags.ret);
}
