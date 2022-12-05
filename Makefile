# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 18:36:32 by esalim            #+#    #+#              #
#    Updated: 2022/12/05 18:47:09 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRC		=	main2.c get_next_line.c get_next_line_utils.c move.c check_maps.c
OBJ		=	${SRC:.c=.o}

CC		=	gcc
CFLAG	=	-Wall -Werror -Wextra

all		: 	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	./$(NAME)
run		:
	./$(NAME)

%.o		:	%.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean	:
	rm -rf $(OBJ)
fclean	:	clean
	rm -rf $(NAME)
	
