# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 18:36:32 by esalim            #+#    #+#              #
#    Updated: 2022/12/09 13:01:33 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRC		=	main.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c move.c check_maps.c draw_map.c key_event.c
OBJ		=	${SRC:.c=.o}
LIBFT	=	libft
FT_PRINTF =	ft_printf
CC		=	gcc
CFLAG	=	-Wall -Werror -Wextra

all		: 	$(NAME)

$(NAME)	:	$(OBJ)
	make -C $(LIBFT)
	make -C $(FT_PRINTF)
	$(CC) $(OBJ) libft.a libftprintf.a  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	./$(NAME) "maps.ber"

run		:
	./$(NAME) "maps.ber"

%.o		:	%.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean	:
	make clean -C $(LIBFT)
	make clean -C $(FT_PRINTF)
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME) libftprintf.a libft.a

re		:	fclean all
