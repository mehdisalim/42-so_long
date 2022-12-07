/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:00:09 by esalim            #+#    #+#             */
/*   Updated: 2022/12/06 11:10:08 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minilibx/mlx.h"
#include "./gnl/get_next_line.h"

typedef struct s_door_coord
{
	int xdoor;
	int	ydoor;
}	t_door_coord;

typedef struct s_data {
	void	*ptr;
	void	*win;
	char	**map;
	int		ncoins;
	int		totalcoins;
	int		isopen;
	void	*playerimg;
}		t_data;

char	**getfullcontent(const char *filename);
int		doublestrlen(char	**s);
int		check_size(char	**s);
int		check_wall(char	**s);
int		check_players(char	**s);
int		check_door(char	**s);
int		check_coins(char	**s);
int		check_invalid_char(char	**s);
int		check_condition(char	**s);

char	**move_down(t_data	*mlx, t_door_coord *door, int i, int j);
char	**move_up(t_data	*mlx, t_door_coord *door, int i, int j);
char	**move_left(t_data	*mlx, t_door_coord *door, int i, int j);
char	**move_right(t_data	*mlx, t_door_coord *door, int i, int j);

#endif
