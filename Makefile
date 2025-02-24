# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbriant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:25:26 by dbriant           #+#    #+#              #
#    Updated: 2025/02/24 15:24:11 by dbriant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Werror -Wextra -Wall
DELALL	= *.a *.o
STLIB	= libft/libft.a
SRCS    = test.c
OBJS    = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(MAKE) -C libft
	ar rc $(NAME) $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
fclean:
	cd libft/ && make fclean
	-rm $(NAME)
clean:
	cd libft/ && make clean
	-rm $(DELALL)
re: fclean all
.PHONY: clean fclean all re
