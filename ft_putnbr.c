/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:07:55 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/19 11:07:55 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int nb, t_flags *flags)
{
	if (nb == -2147483648)
	{
		flags->ret += write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		flags->ret += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, flags);
	flags->ret += write(1, &STR_DECIMAL[nb % 10], 1);
}
