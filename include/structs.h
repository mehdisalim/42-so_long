/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:30:27 by esalim            #+#    #+#             */
/*   Updated: 2022/12/22 10:14:56 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef struct s_door_coord
{
	int	xdoor;
	int	ydoor;
}	t_door_coord;

typedef struct s_enemy
{
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
	void	*img10;
	void	*img11;
}	t_enemy;

typedef struct s_imgs
{
	void	*bg;
	void	*d_c;
	void	*d_o;
	void	*player;
	void	*coins;
	t_enemy	enemy;
	void	*wall;
	void	*smallbg;
}	t_imgs;

typedef struct s_data
{
	void			*ptr;
	void			*win;
	void			*playerimg;
	char			**map;
	int				part;
	int				height;
	int				width;
	int				ncoins;
	int				totalcoins;
	int				isopen;
	int				movecounter;
	t_imgs			imgs;
	t_door_coord	door;
	t_list			*enemy;
}		t_data;

#endif
