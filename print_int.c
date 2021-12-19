/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:42:14 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/18 15:54:55 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_space_zero_minus(t_flags *flags, int zero, int space)
{
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->negative)
		ft_putchar_fd('-', 1);
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
}

static void	paddle_flags(t_flags *flags, unsigned int num, int len, char *base)
{
	int	zero;
	int	space;

	zero = 0;
	if (flags->negative)
		len++;
	if (flags->dot && !flags->precision && !num)
		len = 0;
	if (flags->precision > len)
		zero = flags->precision - len;
	else if (flags->width > len && flags->zero)
		zero = flags->width - len;
	if (zero > 0)
		len += zero;
	if (flags->width > len && !flags->zero)
		space = flags->width - len;
	else
		space = 0;
	flags->ret += len + space;
	check_space_zero_minus(flags, zero, space);
	if (len)
		ft_putnbr_base_fd(num, base, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

static int	ft_number_len(unsigned int number, int base_size)
{
	size_t	len;

	len = 1;
	while (number / base_size > 0)
	{
		len++;
		number /= base_size;
	}
	return (len);
}

void	print_di(va_list ap, char c, t_flags *flags)
{
	int				num;

	if (c == 'i' || c == 'd')
	{
		num = va_arg(ap, int);
		if (num < 0)
		{
			flags->negative = 1;
			num *= -1;
			if (flags -> precision > 0)
				flags -> precision += 1;
		}
		paddle_flags(flags, num, ft_number_len(num, 10), DEC);
	}
}

void	print_ux(va_list ap, char c, t_flags *flags)
{
	unsigned int	u_num;

	if (c == 'u' || c == 'x' || c == 'X')
	{
		u_num = va_arg(ap, unsigned int);
		if (c == 'u')
			paddle_flags(flags, u_num, ft_number_len(u_num, 10), DEC);
		else if (c == 'x')
			paddle_flags(flags, u_num, ft_number_len(u_num, 16), HEX_LOWER);
		else
			paddle_flags(flags, u_num, ft_number_len(u_num, 16), HEX_UPPER);
	}
}
