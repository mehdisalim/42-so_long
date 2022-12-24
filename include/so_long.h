/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:00:09 by esalim            #+#    #+#             */
/*   Updated: 2022/12/24 12:34:46 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "structs.h"

void	so_long(char *map, char	*part);
void	setup_background(t_data mlx);
char	**getfullcontent(const char *filename);
int		doublestrlen(char	**s);
int		check_size(char	**s);
int		check_wall(char	**s);
int		check_players(char	**s);
int		check_door(char	**s, t_data *mlx);
int		check_coins(char	**s);
int		check_invalid_char(char	**s, t_data mlx);
int		check_is_rectangle(char **content);
int		check_path(char **map);
void	destroy_game(t_data *mlx, char *message);
void	freemap(char	**map);

int		key_hook(int key, t_data *mlx);
int		close_win(t_data *mlx);
void	display_counter(t_data	*mlx, int movecounter, char	*s);
void	drawing_map(t_data *mlx);

int		loop_hook(t_data *mlx);
t_list	*init_lists(char **map);
int		move_enemy(t_data *mlx);
void	*get_image(t_data *mlx, char *filename);

char	**move_down(t_data	*mlx, int i, int j);
char	**move_up(t_data	*mlx, int i, int j);
char	**move_left(t_data	*mlx, int i, int j);
char	**move_right(t_data	*mlx, int i, int j);

#endif
