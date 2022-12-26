/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_solong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:39:35 by esalim            #+#    #+#             */
/*   Updated: 2022/12/26 15:52:29 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	char	*getrandomcoin(int index)
{
	if (index == 0)
		return ("./assets/C/coin1.xpm");
	if (index == 1)
		return ("./assets/C/coin2.xpm");
	if (index == 2)
		return ("./assets/C/coin3.xpm");
	return ("./assets/C/coin4.xpm");
}

static	void	getenemyimages(t_data *mlx)
{
	int	a;

	a = 50;
	mlx->imgs.enemy.img0 = get_image(mlx, "./assets/X/e0.xpm");
	mlx->imgs.enemy.img1 = get_image(mlx, "./assets/X/e1.xpm");
	mlx->imgs.enemy.img2 = get_image(mlx, "./assets/X/e2.xpm");
	mlx->imgs.enemy.img3 = get_image(mlx, "./assets/X/e3.xpm");
	mlx->imgs.enemy.img4 = get_image(mlx, "./assets/X/e4.xpm");
	mlx->imgs.enemy.img5 = get_image(mlx, "./assets/X/e5.xpm");
	mlx->imgs.enemy.img6 = get_image(mlx, "./assets/X/e6.xpm");
	mlx->imgs.enemy.img7 = get_image(mlx, "./assets/X/e7.xpm");
	mlx->imgs.enemy.img8 = get_image(mlx, "./assets/X/e8.xpm");
	mlx->imgs.enemy.img9 = get_image(mlx, "./assets/X/e9.xpm");
	mlx->imgs.enemy.img10 = get_image(mlx, "./assets/X/e10.xpm");
	mlx->imgs.enemy.img11 = get_image(mlx, "./assets/X/e11.xpm");
}

static	void	set_images(t_data *mlx)
{
	mlx->imgs.bg = get_image(mlx, "./assets/background/bg.xpm");
	mlx->imgs.player = get_image(mlx, "./assets/P/elf0.xpm");
	mlx->imgs.coins = get_image(mlx, getrandomcoin(mlx->totalcoins % 4));
	mlx->imgs.wall = get_image(mlx, "./assets/1/tree.xpm");
	mlx->imgs.d_o = get_image(mlx, "./assets/E/dooropen.xpm");
	mlx->imgs.d_c = get_image(mlx, "./assets/E/door.xpm");
	mlx->imgs.smallbg = get_image(mlx, "./assets/background/smallbg.xpm");
}

t_data	init(char *filename, char	*part)
{
	t_data	mlx;
	int		a;

	a = 50;
	mlx.map = getfullcontent(filename);
	mlx.ptr = mlx_init();
	mlx.width = (doublestrlen(mlx.map) * 50) + 50;
	mlx.height = ((ft_strlen(mlx.map[0]) - 1) * 50);
	mlx.part = 0;
	if (!ft_strncmp(part, "bonus", 5))
	{
		mlx.part = 1;
		mlx.enemy = init_lists(mlx.map);
		getenemyimages(&mlx);
	}
	mlx.win = mlx_new_window(mlx.ptr, mlx.height, mlx.width, "so_long");
	if (!mlx.map || !mlx.ptr || !mlx.win)
		exit(1);
	mlx.isopen = 0;
	mlx.movecounter = 0;
	mlx.ncoins = 0;
	mlx.totalcoins = check_coins(mlx.map);
	set_images(&mlx);
	return (mlx);
}
