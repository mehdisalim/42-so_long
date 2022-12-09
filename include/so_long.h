/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:00:09 by esalim            #+#    #+#             */
/*   Updated: 2022/12/09 13:25:23 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include "../minilibx/mlx.h"
#include "get_next_line.h"
#include "libft.h"
#include "ft_printf.h"

typedef struct s_door_coord
{
	int xdoor;
	int	ydoor;
}	t_door_coord;

typedef struct s_data {
	void	*ptr;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		ncoins;
	int		totalcoins;
	int		isopen;
	void	*playerimg;
	int		movecounter;
	t_door_coord	door;
}		t_data;

void	so_long(char *map);
char	**getfullcontent(const char *filename);
int		doublestrlen(char	**s);
int		check_size(char	**s);
int		check_wall(char	**s);
int		check_players(char	**s);
int		check_door(char	**s);
int		check_coins(char	**s);
int		check_invalid_char(char	**s);
int		check_condition(char	**s);

int		genkey(int key, t_data *mlx);
void	display_counter(t_data	*mlx, int movecounter, char	*s);
void	drawing_map(t_data *mlx);

char	**move_down(t_data	*mlx, int i, int j);
char	**move_up(t_data	*mlx, int i, int j);
char	**move_left(t_data	*mlx, int i, int j);
char	**move_right(t_data	*mlx, int i, int j);

#endif
