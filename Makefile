# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbriant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:25:26 by dbriant           #+#    #+#              #
#    Updated: 2025/02/26 21:51:51 by dbriant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
DELALL  = *.a *.o
LIBFT   = libft/libft.a
LIBFT_DIR = libft
SRCS    = ft_printf.c helperfunc/c_ft_chartostr.c helperfunc/ft_countnum.c \
          helperfunc/s_ft_strtostr.c helperfunc/p_ft_ptrtostr.c \
          helperfunc/ft_tohex.c helperfunc/d_ft_inttostr.c \
          helperfunc/u_ft_uninttostr.c helperfunc/xX_hextostr.c \
          helperfunc/ft_perctostr.c helperfunc/ft_formatspecifiersize.c \
	helperfunc_bonus/ft_prependzero_bonus.c \
	helperfunc_bonus/ft_prependspace_bonus.c \
	helperfunc_bonus/ft_hashtag_bonus.c \
	helperfunc_bonus/ft_space_bonus.c \
	helperfunc_bonus/ft_alligment.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $(NAME) $(LIBFT_DIR)/*.o $(OBJS)

bonus: $(OBJS) $(LIBFT)
	ar rc $(NAME) $(LIBFT_DIR)/*.o $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

