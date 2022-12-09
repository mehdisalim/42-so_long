/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:45:54 by esalim            #+#    #+#             */
/*   Updated: 2022/12/08 16:47:12 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	getdoor_coord(t_data	*mlx)
{
	int		i = -1;
	int		j;
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

t_data	init(char *filename)
{
	t_data	mlx;
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
	mlx.playerimg = mlx_xpm_file_to_image(mlx.ptr, "./assets/elf3.xpm", &a, &a);
	return (mlx);
}

int main(int ac, char **av)
{
	(void)ac;
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_printf("Please make sure you put the currect file format (ex: map.ber or *.ber )\n");
 		exit(1);
	}
	t_data mlx;
	mlx = init("maps.ber");

	if (!check_size(mlx.map) || !check_wall(mlx.map) || !check_players(mlx.map) || !check_invalid_char(mlx.map) || !check_door(mlx.map) || !(mlx.totalcoins = check_coins(mlx.map)) || !check_condition(mlx.map))
		exit(0);

	setup_background(mlx, mlx.height, mlx.width);
	getdoor_coord(&mlx);
	drawing_map(&mlx);
	display_counter(&mlx, 0, " ");
	mlx_key_hook(mlx.win, genkey, &mlx);
	mlx_loop(mlx.ptr);
	return 0;
}
