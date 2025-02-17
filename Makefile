# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbriant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:25:26 by dbriant           #+#    #+#              #
#    Updated: 2025/02/17 09:31:01 by dbriant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
CC = cc
CFLAGS = -Werror -Wextra -Wall

DELALL = libft/*.o libft/*.a $(NAME)
makesubdirs:
		$(MAKE) -C libft;
fclean:
	rm libft/*.o libft/*.a
clean:
	rm $(DELALL)
.PHONY: clean fclean makesubdirs
