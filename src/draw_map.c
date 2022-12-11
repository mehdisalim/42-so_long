/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:24:55 by esalim            #+#    #+#             */
/*   Updated: 2022/12/09 22:02:10 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*getrandomcoin(int index)
{
	if (index == 0 || index == 4 || index == 8)
		return ("./assets/C/coin1.xpm");
	if (index == 1 || index == 5)
		return ("./assets/C/coin2.xpm");
	if (index == 2 || index == 6 || index == 9)
		return ("./assets/C/coin3.xpm");
	return ("./assets/C/coin4.xpm");
}

void	display_counter(t_data	*mlx, int movecounter, char	*s)
{
	int		i;
	char	*mc;
	char	*string;
	char	*nc;
	char	*coin;

	i = 0;
	mc = ft_itoa(movecounter);
	string = ft_strjoin(mc, s);
	nc = ft_itoa(mlx->ncoins);
	coin = ft_strjoin(nc, "  coins");
	if (movecounter != 0)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(
				mlx->ptr, "./assets/background/bg.xpm", &i, &i), 0, 0);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(
				mlx->ptr, "./assets/background/bg.xpm", &i, &i),
			mlx->height - 100, 0);
	}
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0x000000, string);
	mlx_string_put(mlx->ptr, mlx->win, mlx->height - 100, 10, 0x000000, coin);
	free(mc);
	free(nc);
	free(string);
	free(coin);
}

void	checker_cond(t_data *mlx, char c, int x, int y)
{
	int	i;

	i = 50;
	if (c == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx_xpm_file_to_image(mlx->ptr, "./assets/1/tree.xpm", &i, &i),
			y, x);
	if (c == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->playerimg, y, x);
	if (c == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx_xpm_file_to_image(mlx->ptr,
				getrandomcoin(mlx->totalcoins % 10), &i, &i), y, x);
	if (c == 'X')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx_xpm_file_to_image(mlx->ptr, "./assets/X/enemy.xpm",
				&i, &i), y, x);
	if (c == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx_xpm_file_to_image(mlx->ptr, "./assets/background/bg.xpm",
				&i, &i), y, x);
}

void	put_img(t_data *mlx, const char c, int x, int y)
{
	static t_door_coord	door;
	int					i;

	i = 50;
	if (c == 'E')
	{
		if (!door.xdoor || !door.ydoor)
		{
			door.xdoor = x;
			door.ydoor = y;
		}
		if (mlx->ncoins == mlx->totalcoins)
		{
			mlx->isopen = 1;
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx_xpm_file_to_image(mlx->ptr, "./assets/E/dooropen.xpm",
					&i, &i), y, x);
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx_xpm_file_to_image(mlx->ptr, "./assets/E/door.xpm", &i, &i),
				y, x);
	}
	if (c == 'P' && door.xdoor == x && door.ydoor == y)
	{
		if (mlx->isopen)
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx_xpm_file_to_image(mlx->ptr, "./assets/E/dooropen.xpm",
					&i, &i), y, x);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx_xpm_file_to_image(mlx->ptr, "./assets/E/door.xpm",
					&i, &i), y, x);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->playerimg, y, x);
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
