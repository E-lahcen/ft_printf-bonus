/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:42:19 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/18 00:42:19 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_percent(t_flags *flags)
{
	int	space;
	int	zero;

	if (flags->width > 1 && flags->zero)
		zero = flags->width - 1;
	else
		zero = 0;
	if (flags->width > 1 && !zero)
		space = flags->width - 1;
	else
		space = 0;
	flags->ret += 1 + zero + space;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
