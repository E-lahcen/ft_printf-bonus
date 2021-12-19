/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:42:53 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/18 20:02:06 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define STR_DECIMAL "0123456789"

typedef struct s_flags
{
	int			index;
	int			zero;
	int			minus;
	int			width;
	int			precision;
	int			dot;
	int			negative;
	int			ret;
}				t_flags;

int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
int				ft_printf_bonus(const char *format, ...);
void			store_flags(const char *format, va_list ap, t_flags *flags);
void			print_char(va_list ap, t_flags *flags);
void			print_string(va_list ap, t_flags *flags);
void			print_di(va_list ap, char c, t_flags *flags);
void			print_ux(va_list ap, char c, t_flags *flags);
void			print_pointer(va_list ap, t_flags *flags);
void			print_percent(t_flags *flags);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_base_fd(unsigned int n, char *base, int fd);
int				ft_intlen(int nb);
void			ft_putnbr(int nb, t_flags *flags);
void			ft_putstr(char *str, t_flags *flags);
void			ft_putunsigned(unsigned int nb, char base, t_flags *flags);

#endif