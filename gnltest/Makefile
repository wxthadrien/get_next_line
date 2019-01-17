# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 11:08:02 by hmeys             #+#    #+#              #
#    Updated: 2019/01/12 14:23:13 by hmeys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Wall -Wextra -Werror

all:
			cd .. && cd libft && make && cd .. && cd gnltest
			cd .. && gcc $(FLAGS) get_next_line.c -L libft -lft -I libft/libft.h
libft:
			cd libft && make && cd ..
gnl:
			gcc $(FLAGS) get_next_line.c -L libft -lft -I libft/libft.h
clean:
			cd libft && make clean && cd ..
fclean: clean
			rm -f a.out
lftclean:
			cd ../libft/ && make fclean
re: fclean all
