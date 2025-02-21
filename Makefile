# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbriant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:25:26 by dbriant           #+#    #+#              #
#    Updated: 2025/02/20 21:11:08 by dbriant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprint.a
CC		= cc
CFLAGS	= -Werror -Wextra -Wall
DELALL	= *.a *.o
SRC		= test.c $(wildcard libft/*.c)
OBJS    = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	ar rcs $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
fclean:
	cd libft/ && make fclean
clean:
	cd libft/ && make clean
	-rm $(DELALL)
.PHONY: clean fclean makesubdirs
