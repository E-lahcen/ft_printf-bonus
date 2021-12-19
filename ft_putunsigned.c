/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:08:04 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/19 11:08:04 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunsigned(unsigned int nb, char base, t_flags *flags)
{
	int	base_int;

	if (base == 'u')
		base_int = 10;
	else
		base_int = 16;
	if (nb >= base_int)
		ft_putunsigned(nb / base_int, base, flags);
	if (base == 'x')
		flags->ret += write(1, &HEX_LOWER[nb % base_int], 1);
	else if (base == 'X')
		flags->ret += write(1, &HEX_UPPER[nb % base_int], 1);
	else
		flags->ret += write(1, &STR_DECIMAL[nb % base_int], 1);
}
