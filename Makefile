# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 18:36:32 by esalim            #+#    #+#              #
#    Updated: 2022/11/23 17:12:44 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
SRC= main.c

OBJ= ${SRC:.c=.o}

CC=gcc
CFLAG=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	./$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

	