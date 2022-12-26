/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:39:04 by esalim            #+#    #+#             */
/*   Updated: 2022/12/26 15:52:39 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	setup_background(t_data mlx)
{
	int	k;

	k = 0;
	if (mlx.part == 1)
		k = 50;
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 0, k);
	if (mlx.height > 5120 || mlx.width > 2880)
		destroy_game(&mlx, "Error: size is too large.");
	if (mlx.height >= 1250)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 1650, 0);
	if (mlx.height >= 2400)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 3200, 0);
	if (mlx.width >= 1650)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 0, 1250);
	if (mlx.width >= 3200)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 0, 2400);
	if (mlx.height > 1200 && mlx.width > 1600)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 1600, 1200);
	if (mlx.height > 2400 && mlx.width > 3200)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 3200, 2400);
}

void	so_long(char *map, char	*part)
{
	t_data	mlx;
	int		len;

	len = ft_strlen(map);
	if (!ft_strnstr(map + len - 4, ".ber", 4))
	{
		ft_printf("Please make sure you put the currect file format (*.ber)");
		exit(1);
	}
	mlx = init(map, part);
	if (!check_size(mlx.map) ||!check_wall(mlx.map) || !check_players(mlx.map)
		|| !check_invalid_char(mlx.map, mlx) || !check_door(mlx.map, &mlx)
		|| !check_is_rectangle(mlx.map) || !mlx.totalcoins
		|| !check_path(getfullcontent(map)))
		destroy_game(&mlx, "invalid map");
	setup_background(mlx);
	drawing_map(&mlx);
	if (mlx.part == 1)
	{
		mlx_loop_hook(mlx.ptr, move_enemy, &mlx);
		display_counter(&mlx, 0, " ");
	}
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, close_win, &mlx);
	mlx_loop(mlx.ptr);
}
