/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:24:55 by esalim            #+#    #+#             */
/*   Updated: 2022/12/16 16:59:58 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	checker_cond(t_data *mlx, char c, int x, int y)
{
	int	i;

	i = 50;
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
	int		i;
	char	*mc;
	char	*tc;
	char	*string;
	char	*nc;
	char	*coin;

	i = 0;
	mc = ft_itoa(movecounter);
	tc = ft_itoa(mlx->totalcoins);
	string = ft_strjoin(mc, s);
	nc = ft_itoa(mlx->ncoins);
	coin = ft_strjoin(nc, "/");
	free(nc);
	nc = ft_strjoin(coin, tc);
	free(coin);
	coin = ft_strjoin(nc, " coins");
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0xffffff, string);
	mlx_string_put(mlx->ptr, mlx->win, mlx->height - 110, 10, 0xffffff, coin);
	free(mc);
	free(tc);
	free(nc);
	free(string);
	free(coin);
}

void	put_img(t_data *mlx, const char c, int x, int y)
{
	static t_door_coord	door;
	int					i;

	i = 50;
	if (!mlx->nextlevel)
	{
		door.xdoor = 0;
		door.ydoor = 0;
	}
	if (c == 'E')
	{
		if (!door.xdoor || !door.ydoor)
		{
			door.xdoor = x;
			door.ydoor = y;
			mlx->nextlevel = 1;
		}
		if (mlx->ncoins == mlx->totalcoins)
		{
			mlx->isopen = 1;
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.dooropen, y, x);
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.doorclose, y, x);
	}
	if (c == 'P' && door.xdoor == x && door.ydoor == y)
	{
		if (mlx->isopen)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.dooropen, y, x);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.doorclose, y, x);
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
