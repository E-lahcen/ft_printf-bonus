# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 18:08:13 by lelhlami          #+#    #+#              #
#    Updated: 2021/12/19 11:51:38 by lelhlami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

FT_PRNT = 	ft_printf.c

SRC =		ft_strlen.c \
			print_char.c \
			print_string.c \
			print_int.c \
			print_pointer.c \
			print_percent.c \
			ft_putnbr_base_fd.c \
			ft_putchar_fd.c \
			ft_isdigit.c

BONUS =		ft_printf_bonus.c\
			store_flags.c\
			ft_putnbr.c \
			ft_putunsigned.c \
			ft_putstr.c \
			ft_intlen.c

OBJ =		$(SRC:.c=.o)

OBJ_BONUS =		$(BONUS:.c=.o)

CFLAGS =	-Wall -Werror -Wextra -g

CC = gcc

RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) $(FT_PRNT)
	ar rcs $(NAME) $(OBJ) ft_printf.o

clean:
	$(RM) $(OBJ) ft_printf.o $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

bonus:
	$(CC) $(FLAGS) -c $(SRC) $(BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

re: fclean all

.PONY: all, clean, fclean, re
