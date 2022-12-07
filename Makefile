# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 18:36:32 by esalim            #+#    #+#              #
#    Updated: 2022/12/07 11:01:41 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRC		=	main2.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c move.c check_maps.c
OBJ		=	${SRC:.c=.o}

CC		=	gcc
CFLAG	=	-Wall -Werror -Wextra

all		: 	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	./$(NAME) "maps.ber"

run		:
	./$(NAME) "maps.ber"

%.o		:	%.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME)
	
