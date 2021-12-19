/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:26:58 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/18 23:26:58 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *str, t_flags *flags)
{
	if (!str)
		flags->ret += write(1, "(null)", 6);
	else
		while (*str)
			flags->ret += write(1, str++, 1);
}
