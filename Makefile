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

NAME	= libftprint.a
CC	= cc
CFLAGS	= -Werror -Wextra -Wall
DELALL	= *.a *.o
STLIB	= libft/libft.a
OBJS    = $(.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) main.c $(STLIB) -o main
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
fclean:
	cd libft/ && make fclean
clean:
	cd libft/ && make clean
	-rm $(DELALL)
.PHONY: clean fclean makesubdirs
