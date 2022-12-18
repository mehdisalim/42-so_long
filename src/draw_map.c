/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:24:55 by esalim            #+#    #+#             */
/*   Updated: 2022/12/18 14:54:44 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	checker_cond(t_data *mlx, char c, int x, int y)
{
	int	i;

	i = 50;
	if (c == 'E')
	{
		if (mlx->ncoins == mlx->totalcoins)
		{
			mlx->isopen = 1;
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.d_o, y, x);
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.d_c, y, x);
	}
	if (c == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.wall, y, x);
	if (c == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.player, y, x);
	if (c == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.coins, y, x);
	if (c == 'X')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img0, y, x);
}

void	display_counter(t_data	*mlx, int movecounter, char	*s)
{
	char	*mc;
	char	*tc;
	char	*string;

	mc = ft_itoa(movecounter);
	tc = ft_itoa(mlx->totalcoins);
	string = ft_strjoin(mc, s);
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, string);
	free(string);
	free(mc);
	mc = ft_itoa(mlx->ncoins);
	string = ft_strjoin(mc, "/");
	free(mc);
	mc = ft_strjoin(string, tc);
	free(string);
	string = ft_strjoin(mc, " coins");
	mlx_string_put(mlx->ptr, mlx->win, mlx->height - 110, 10, 0xffffff, string);
	free(mc);
	free(tc);
	free(string);
}

static void	put_img(t_data *mlx, const char c, int x, int y)
{
	static t_door_coord	door;
	int					i;

	i = 50;
	if (c == 'E' && (!door.xdoor || !door.ydoor))
	{
		door.xdoor = x;
		door.ydoor = y;
	}
	if (c == 'P' && door.xdoor == x && door.ydoor == y)
	{
		if (mlx->isopen)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.d_o, y, x);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.d_c, y, x);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.player, y, x);
	}
	checker_cond(mlx, c, x, y);
	return ;
}

void	drawing_map(t_data *mlx)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 50;
	while (mlx->map[i])
	{
		j = 0;
		y = -50;
		while (mlx->map[i][j] && ft_strchr("10ECPX", mlx->map[i][j]))
			put_img(mlx, mlx->map[i][j++], x, (y += 50));
		x += 50;
		i++;
	}
}
