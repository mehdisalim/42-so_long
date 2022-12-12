/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:39:04 by esalim            #+#    #+#             */
/*   Updated: 2022/12/12 16:40:45 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	getdoor_coord(t_data	*mlx)
{
	int		i;
	int		j;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'E')
			{
				mlx->door.xdoor = i;
				mlx->door.ydoor = j;
			}
		}
	}
}

static t_data	init(char *filename)
{
	t_data	mlx;

	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
	{
		ft_printf("Please make sure you put the currect file format (*.ber)");
		exit(1);
	}
	mlx.map = getfullcontent(filename);
	if (!mlx.map)
		exit(0);
	mlx.height = ((ft_strlen(mlx.map[0]) - 1) * 50);
	mlx.width = (doublestrlen(mlx.map) * 50) + 50;
	mlx.ptr = mlx_init();
	mlx.isopen = 0;
	mlx.movecounter = 0;
	mlx.win = mlx_new_window(mlx.ptr, mlx.height, mlx.width, "so_long");
	mlx.ncoins = 0;
	int a = 50;

	mlx.imgs.bg = mlx_xpm_file_to_image(mlx.ptr, "./assets/background/bg.xpm", &a, &a);
	mlx.imgs.player = mlx_xpm_file_to_image(mlx.ptr, "./assets/P/elf0.xpm", &a, &a);
	mlx.imgs.coins = mlx_xpm_file_to_image(mlx.ptr, "./assets/C/coin1.xpm", &a, &a);
	mlx.imgs.wall = mlx_xpm_file_to_image(mlx.ptr, "./assets/1/tree.xpm", &a, &a);
	mlx.imgs.dooropen = mlx_xpm_file_to_image(mlx.ptr, "./assets/E/dooropen.xpm", &a, &a);
	mlx.imgs.doorclose = mlx_xpm_file_to_image(mlx.ptr, "./assets/E/door.xpm", &a, &a);
	mlx.imgs.enemy = mlx_xpm_file_to_image(mlx.ptr, "./assets/X/enemy.xpm", &a, &a);
	getdoor_coord(&mlx);
	return (mlx);
}

void	so_long(char *map)
{
	t_data	mlx;

	mlx = init(map);
	mlx.totalcoins = check_coins(mlx.map);
	if (!check_size(mlx.map)
		||!check_wall(mlx.map)
		|| !check_players(mlx.map)
		|| !check_invalid_char(mlx.map)
		|| !check_door(mlx.map)
		|| !mlx.totalcoins
		|| !check_condition(mlx.map))
		exit(0);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 0,0);
	drawing_map(&mlx);
	display_counter(&mlx, 0, " ");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.ptr);
}
