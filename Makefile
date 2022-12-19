# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 18:36:32 by esalim            #+#    #+#              #
#    Updated: 2022/12/19 22:08:57 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRC		=	main.c \
			./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c \
			./src/move.c \
			./src/check_map.c \
			./src/check_map2.c \
			./src/draw_map.c \
			./src/key_event.c \
			./src/read_map.c \
			./src/so_long.c \
			./src/loop_hook.c \
			./src/init_list.c \
			./src/move_enemy.c \
			./src/protection.c

OBJ		=	${SRC:.c=.o}
LIBFT	=	libft
FT_PRINTF =	ft_printf
CC		=	gcc
CFLAG	=	-Wall -Werror -Wextra

all		: 	$(NAME)

$(NAME)	:	$(OBJ)
	make -C $(LIBFT)
	make -C $(FT_PRINTF)
	$(CC) $(OBJ) libs/libft.a libs/libftprintf.a  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mand	: $(NAME)
	./$< "maps/map.ber" mand

bonus	: $(NAME)
	./$< "maps/map_bonus.ber" bonus

%.o		:	%.c
	$(CC) $(CFLAG) -Imlx -c $< -o $@

clean	:
	make clean -C $(LIBFT)
	make clean -C $(FT_PRINTF)
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME) libs/libftprintf.a libs/libft.a

re		:	fclean all
