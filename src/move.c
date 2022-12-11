/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:19:19 by esalim            #+#    #+#             */
/*   Updated: 2022/12/11 20:29:53 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**move_up(t_data *mlx, int i, int j)
{
	static int i;
	if (mlx->door.xdoor == i - 1 && mlx->door.ydoor == j && mlx->isopen == 1)
	{
		ft_printf("====== you win !! ======");
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->map);
		so_long("maps/map2.ber");
	}
	if (mlx->map[i - 1][j] == 'E')
	{
		mlx->door.xdoor = i - 1;
		mlx->door.ydoor = j;
	}
	if (mlx->map[i - 1][j] == 'C')
		mlx->ncoins += 1;
	if (mlx->map[i - 1][j] == 'X')
	{
		ft_printf("====== you lose !! ======");
		exit(0);
	}
	mlx->map[i - 1][j] = 'P';
	if (mlx->door.xdoor == i && mlx->door.ydoor == j)
		mlx->map[mlx->door.xdoor][mlx->door.ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}

char	**move_down(t_data *mlx, int i, int j)
{
	if (mlx->door.xdoor == i + 1 && mlx->door.ydoor == j && mlx->isopen == 1)
	{
		ft_printf("====== you win !! ======");
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->map);
		so_long("maps/map2.ber");
	}
	if (mlx->map[i + 1][j] == 'E')
	{
		mlx->door.xdoor = i + 1;
		mlx->door.ydoor = j;
	}
	if (mlx->map[i + 1][j] == 'C')
		mlx->ncoins += 1;
	if (mlx->map[i + 1][j] == 'X')
	{
		ft_printf("====== you lose !! ======");
		exit(0);
	}
	mlx->map[i + 1][j] = 'P';
	if (mlx->door.xdoor == i && mlx->door.ydoor == j)
		mlx->map[mlx->door.xdoor][mlx->door.ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}

char	**move_right(t_data *mlx, int i, int j)
{
	if (mlx->door.xdoor == i && mlx->door.ydoor == j + 1 && mlx->isopen == 1)
	{
		ft_printf("====== you win !! ======");
		mlx_clear_window(mlx->ptr, mlx->win);
		free(mlx->map);
		so_long("maps/map3.ber");
	}
	if (mlx->map[i][j + 1] == 'E')
	{
		mlx->door.xdoor = i;
		mlx->door.ydoor = j + 1;
	}
	if (mlx->map[i][j + 1] == 'C')
		mlx->ncoins += 1;
	if (mlx->map[i][j + 1] == 'X')
	{
		ft_printf("====== you lose !! ======");
		exit(0);
	}
	mlx->map[i][j + 1] = 'P';
	if (mlx->door.xdoor == i && mlx->door.ydoor == j)
		mlx->map[mlx->door.xdoor][mlx->door.ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}

char	**move_left(t_data *mlx, int i, int j)
{
	if (mlx->door.xdoor == i && mlx->door.ydoor == j - 1 && mlx->isopen == 1)
	{
		ft_printf("====== you win !! ======");
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->map);
		so_long("maps/map2.ber");
	}
	if (mlx->map[i][j - 1] == 'E')
	{
		mlx->door.xdoor = i;
		mlx->door.ydoor = j - 1;
	}
	if (mlx->map[i][j - 1] == 'C')
		mlx->ncoins += 1;
	if (mlx->map[i][j - 1] == 'X')
	{
		ft_printf("====== you lose !! ======");
		exit(0);
	}
	mlx->map[i][j - 1] = 'P';
	if (mlx->door.xdoor == i && mlx->door.ydoor == j)
		mlx->map[mlx->door.xdoor][mlx->door.ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}
