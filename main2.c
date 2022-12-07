/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:45:54 by esalim            #+#    #+#             */
/*   Updated: 2022/12/07 11:00:52 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *getrandomcoin(int index)
{
	if (index == 0)
		return ("./assets/coin1.xpm");
	else if (index == 1)
		return ("./assets/coin2.xpm");
	else if (index == 2)
		return ("./assets/coin3.xpm");
	return ("./assets/coin4.xpm");
}

void put_img(t_data *mlx, const char c, int x, int y)
{
	int i = 50;
	static t_door_coord door;
	if (c == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/tree.xpm", &i, &i), y, x);
	else if (c == 'E')
	{
		if (!door.xdoor || !door.ydoor)
		{
			door.xdoor = x;
			door.ydoor = y;
		}
		if (mlx->ncoins == mlx->totalcoins)
		{
			mlx->isopen = 1;
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/dooropen.xpm", &i, &i), y, x);
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/door.xpm", &i, &i), y, x);
	}
	else if (c == 'P' && door.xdoor == x && door.ydoor == y)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/door.xpm", &i, &i), y, x);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->playerimg, y, x);
	}
	else if (c == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->playerimg, y, x);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, getrandomcoin(mlx->totalcoins / 9), &i, &i), y, x);
	else if (c == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/bg10.xpm", &i, &i), y, x);
	else
		return;
}

void drawing_map(t_data *mlx)
{
	int i = 0;
	int j;
	int x = 0;
	int y;
	while (mlx->map[i])
	{
		j = 0;
		y = -50;
		;
		while (mlx->map[i][j] && strchr("10ECP", mlx->map[i][j]))
			put_img(mlx, mlx->map[i][j++], x, (y += 50));
		x += 50;
		i++;
	}
}

char **changeplayerinmap(t_data *mlx, int direction)
{
	int i = -1, j;
	static t_door_coord door;
	static int movecounter;
	int q = 50;

	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'P' && direction == 13 && mlx->map[i - 1][j] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/elf3.xpm", &q, &q);
				return (printf("%d ==> move to top\n", ++movecounter), move_up(mlx, &door, i, j));
			}
			if (mlx->map[i][j] == 'P' && direction == 0 && mlx->map[i][j - 1] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/elf0.xpm", &q, &q);
				return (printf("%d ==> move to left\n", ++movecounter), move_left(mlx, &door, i, j));
			}
			if (mlx->map[i][j] == 'P' && direction == 1 && mlx->map[i + 1][j] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/elf3.xpm", &q, &q);
				return (printf("%d ==> move to down\n", ++movecounter), move_down(mlx, &door, i, j));
			}
			if (mlx->map[i][j] == 'P' && direction == 2 && mlx->map[i][j + 1] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/elf3.xpm", &q, &q);
				return (printf("%d ==> move to right\n", ++movecounter), move_right(mlx, &door, i, j));
			}
		}
	}
	return (mlx->map);
}

int genkey(int key, t_data *mlx)
{
	if (key == 53)
		exit(0);
	if ((key >= 0 && key < 3) || key == 13)
	{
		mlx->map = changeplayerinmap(mlx, key);
		drawing_map(mlx);
	}
	return (0);
}

void setup_background(t_data mlx, int height, int width)
{
	int x = -50;
	int y;
	int s = 50;
	while ((x += 50) < height)
	{
		y = -50;
		while ((y += 50) < width)
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg10.xpm", &s, &s), x, y);
	}
}

int main(int ac, char **av)
{
	(void)ac;
	if (!strstr(av[1], ".ber"))
	{
		printf("Please make sure you put the currect file format (ex: map.ber or *.ber )\n");
		exit(1);
	}
	char **map = getfullcontent("maps.ber");

	if (!map)
		exit(0);
	t_data mlx;
	if (!check_size(map) || !check_wall(map) || !check_players(map) || !check_invalid_char(map) || !check_door(map) || !(mlx.totalcoins = check_coins(map)) || !check_condition(map))
		exit(0);
	int height = (strlen(map[0]) - 1) * 50;
	int width = doublestrlen(map) * 50;
	mlx.ptr = mlx_init();
	mlx.map = map;
	mlx.isopen = 0;
	mlx.win = mlx_new_window(mlx.ptr, height, width, "so_long");
	mlx.ncoins = 0;
	int q = 50;
	mlx.playerimg = mlx_xpm_file_to_image(mlx.ptr, "./assets/elf3.xpm", &q, &q);
	setup_background(mlx, height, width);
	drawing_map(&mlx);
	mlx_key_hook(mlx.win, genkey, &mlx);
	mlx_loop(mlx.ptr);
	return 0;
}
