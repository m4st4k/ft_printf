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

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Werror -Wextra -Wall
DELALL	= *.a *.o
STLIB	= libft/libft.a
SRCS    = ft_printf.c helperfunc/c_ft_chartostr.c helperfunc/ft_countnum.c helperfunc/s_ft_strtostr.c \
			helperfunc/p_ft_ptrtostr.c helperfunc/ft_tohex.c helperfunc/d_ft_inttostr.c helperfunc/u_ft_uninttostr.c helperfunc/xX_hextostr.c helperfunc/ft_perctostr.c
BONUSSRCS	= ft_printf_bonus.c
OBJS    = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(MAKE) -C libft 
	ar rc $(NAME) libft/*.o $(OBJS)
#bonus : $(OBJS) $(BONUSOBJS)
	#$(MAKE) -C libft 
	#ar rc $(NAME) libft/*.o $(OBJS) $(BONUSOBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
fclean:
	cd libft/ && make fclean
	-rm -f $(DELALL) helperfunc/*.o
	-rm -f $(NAME)
clean:
	cd libft/ && make clean
	-rm -f $(DELALL) helperfunc/*.o
	-rm -f $(DELALL)
re: fclean all
.PHONY: clean fclean all re
