# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 11:08:02 by hmeys             #+#    #+#              #
#    Updated: 2018/11/14 11:27:43 by hmeys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Wall -Wextra -Werror

all:
			cd libft && make && cd ..
			gcc $(FLAGS) get_next_line.c -L libft -lft -I libft/libft.h
			cd libft && make fclean && cd ..
fclean:
			rm -f a.out

re: fclean all

