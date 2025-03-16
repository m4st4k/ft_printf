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
SRCS    = ft_printf.c ft_p.c ft_xX.c ft_prnthx.c ft_di.c
OBJS    = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(MAKE) -C libft 
	ar rc $(NAME) libft/*.o $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
fclean:
	cd libft/ && make fclean
	-rm -f $(NAME)
clean:
	cd libft/ && make clean
	-rm -f $(DELALL)
re: fclean all
.PHONY: clean fclean all re
