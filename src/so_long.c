/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:39:04 by esalim            #+#    #+#             */
/*   Updated: 2022/12/15 19:13:56 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// static void	getdoor_coord(t_data	*mlx)
// {
// 	int		i;
// 	int		j;

// 	i = -1;
// 	while (mlx->map[++i])
// 	{
// 		j = -1;
// 		while (mlx->map[i][++j])
// 		{
// 			if (mlx->map[i][j] == 'E')
// 			{
// 				mlx->door.xdoor = i;
// 				mlx->door.ydoor = j;
// 			}
// 		}
// 	}
// }

void	display_linkedlist(t_data mlx)
{
	t_linkedlist lst = init_lists(mlx.map);
	while (lst.enemy)
	{
		ft_printf("Enemy (%c) :  x ===> %d  y ===> %d \n", lst.enemy->content.c, lst.enemy->content.x, lst.enemy->content.y);
		lst.enemy = lst.enemy->next;
	}
	while (lst.player)
	{
		ft_printf("Player (%c) :  x ===> %d  y ===> %d \n", lst.player->content.c, lst.player->content.x, lst.player->content.y);
		lst.player = lst.player->next;
	}
	while (lst.coins)
	{
		ft_printf("Coins (%c) :  x ===> %d  y ===> %d \n", lst.coins->content.c, lst.coins->content.x, lst.coins->content.y);
		lst.coins = lst.coins->next;
	}
	while (lst.door)
	{
		ft_printf("Door (%c) :  x ===> %d  y ===> %d \n", lst.door->content.c, lst.door->content.x, lst.door->content.y);
		lst.door = lst.door->next;
	}
}

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

void	setup_background(t_data mlx)
{
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 0,0);
	if (mlx.height > 5120 || mlx.width > 2880)
	{
		ft_printf("Error: size is too large.\n");
		exit(1);
	}
	int h = 1200;
	int w = 1650;
	ft_printf("%d ===> %d \n", mlx.height, mlx.width);
	if (mlx.height >= h)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, w, 0);
	if (mlx.width >=  w)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, 0, h);
	if (mlx.height > h && mlx.width >  w)
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.imgs.bg, w, h);
	
	// display_linkedlist(mlx);
	
}

void	getenemyimages(t_data *mlx)
{
	int a = 50;
	mlx->imgs.enemy.img0 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e0.xpm", &a, &a);
	mlx->imgs.enemy.img1 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e1.xpm", &a, &a);
	mlx->imgs.enemy.img2 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e2.xpm", &a, &a);
	mlx->imgs.enemy.img3 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e3.xpm", &a, &a);
	mlx->imgs.enemy.img4 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e4.xpm", &a, &a);
	mlx->imgs.enemy.img5 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e5.xpm", &a, &a);
	mlx->imgs.enemy.img6 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e6.xpm", &a, &a);
	mlx->imgs.enemy.img7 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e7.xpm", &a, &a);
	mlx->imgs.enemy.img8 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e8.xpm", &a, &a);
	mlx->imgs.enemy.img9 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e9.xpm", &a, &a);
	mlx->imgs.enemy.img10 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e10.xpm", &a, &a);
	mlx->imgs.enemy.img11 = mlx_xpm_file_to_image(mlx->ptr, "./assets/X/e11.xpm", &a, &a);
}

static t_data	init(char *filename)
{
	t_data	mlx;
	int a = 0;

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
	mlx.totalcoins = check_coins(mlx.map);
	mlx.imgs.bg = mlx_xpm_file_to_image(mlx.ptr, "./assets/background/bg.xpm", &a, &a);
	mlx.imgs.player = mlx_xpm_file_to_image(mlx.ptr, "./assets/P/elf0.xpm", &a, &a);
	mlx.imgs.coins = mlx_xpm_file_to_image(mlx.ptr, getrandomcoin(mlx.totalcoins % 10), &a, &a);
	mlx.imgs.wall = mlx_xpm_file_to_image(mlx.ptr, "./assets/1/tree.xpm", &a, &a);
	mlx.imgs.dooropen = mlx_xpm_file_to_image(mlx.ptr, "./assets/E/dooropen.xpm", &a, &a);
	mlx.imgs.doorclose = mlx_xpm_file_to_image(mlx.ptr, "./assets/E/door.xpm", &a, &a);
	getenemyimages(&mlx);
	// getdoor_coord(&mlx);
	return (mlx);
}

void	so_long(char *map)
{
	t_data	mlx;

	mlx = init(map);
	if (!check_size(mlx.map)
		||!check_wall(mlx.map)
		|| !check_players(mlx.map)
		|| !check_invalid_char(mlx.map)
		|| !check_door(mlx.map)
		|| !mlx.totalcoins
		|| !check_condition(mlx.map))
		exit(0);
	// exit(0);
	mlx.lists = init_lists(mlx.map);
	setup_background(mlx);
	drawing_map(&mlx);
	display_counter(&mlx, 0, " ");
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop_hook(mlx.ptr, move_enemy, &mlx);
	mlx_loop(mlx.ptr);
}
