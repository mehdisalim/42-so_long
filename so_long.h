/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:00:09 by esalim            #+#    #+#             */
/*   Updated: 2022/12/05 10:59:38 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef	struct	s_img {
	void	*img;
	int		height;
	int		width;
	char	*filename;
}	t_img;


typedef struct s_player {
	int	x;
	int	y;
}	t_player;

typedef struct s_data {
	void	*ptr;
	void	*win;
	void	*img;
	char	**map;
	int		width;
	int		height;
	char	*title;
	t_player player;
}		t_data;


char	**getfullcontent(const char *filename);
int	doublestrlen(char	**s);
int	check_size(char	**s);
int	check_wall(char	**s);
int	check_players(char	**s);
int	check_door(char	**s);
int	check_coins(char	**s);
int	check_invalid_char(char	**s);
int	check_condition(char	**s);

#endif
