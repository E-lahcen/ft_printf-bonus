/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:41:57 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/19 11:12:52 by lelhlami         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (!c)
		return ((char *) s);
	return (0);
}

int	ft_width(va_list ap, const char *s, t_flags *flags)	//This function hundle space padding
{
	int		i;
	int		nb;
	char	*str;
	int		j;

	i = 0;
	nb = 0;
	while (ft_strchr("ids", s[++i]) == 0)	//calculating width before finding 'i || d || s'
		nb = s[i] - 48 + (nb * 10);
	if (s[i] == 's')
	{
		str = va_arg(ap, char *);
		nb -= ft_strlen(str);
		while (nb-- > 0)
			flags->ret += write(1, " ", 1);
		return (ft_putstr(str, flags), i + 1);
	}
	j = va_arg(ap, int);
	nb -= ft_intlen(j) + 1;
	while (nb-- > 0)
		flags->ret += write(1, " ", 1);
	if (j >= 0)		//if j >=0 we add a space(replace '-')
		flags->ret += write(1, s, 1);
	return (ft_putnbr(j, flags), i + 1);
}

void	ft_sharp(const char *format, va_list ap, t_flags *flags)	//This function put the number in hexa when # is detected
{
	unsigned int	unb;

	flags->index += 2;	//receiving exactly caracter after #
	unb = va_arg(ap, unsigned int);
	if (format[flags->index] == 'x' && unb != 0)
		flags->ret += write(1, "0x", 2);
	if (format[flags->index] == 'X' && unb != 0)
		flags->ret += write(1, "0X", 2);
	ft_putunsigned(unb, format[flags->index], flags); //we print with hexadecimal
}

static void	handle_conversions(const char *format, va_list ap, t_flags *flags)
{
	store_flags(format, ap, flags);
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
		{
			if (format[flags.index + 1] == '#'\
					&& (ft_strchr("xX", format[flags.index + 2])))
				ft_sharp(format, ap, &flags);
			else if (format[flags.index + 1] == ' '\
					|| format[flags.index + 1] == '+')
				flags.index += ft_width(ap, &format[flags.index + 1], &flags);
			else
				handle_conversions(format, ap, &flags);
		}
		else
		{
			ft_putchar_fd(format[flags.index], 1);
			flags.ret ++;
		}
		flags.index++;
	}
	va_end(ap);
	return (flags.ret);
}
