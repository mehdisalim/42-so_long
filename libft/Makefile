# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalim <esalim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 18:43:45 by esalim            #+#    #+#              #
#    Updated: 2022/12/15 09:27:44 by esalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_strdup.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memmove.c \
	   	ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
	   	ft_split.c	\
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS	= $(CFILES:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror 
NAME	= ../libs/libft.a

all: 	$(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^

%.o:%.c
	@$(CC) -c $(CFLAGS) $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:fclean $(NAME)

