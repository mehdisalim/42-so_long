/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:19:19 by esalim            #+#    #+#             */
/*   Updated: 2022/12/18 14:06:00 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	freemap(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	**move_up(t_data *mlx, int i, int j)
{
	if (mlx->door.xdoor == i - 1 && mlx->door.ydoor == j && mlx->isopen == 1)
	{
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you win !! ======");
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
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you lose !! ======");
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
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you win !! ======");
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
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you lose !! ======");
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
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you win !! ======");
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
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you lose !! ======");
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
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you win !! ======");
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
		freemap(mlx->map);
		mlx_destroy_window(mlx->ptr, mlx->win);
		MPRINT("====== you lose !! ======");
	}
	mlx->map[i][j - 1] = 'P';
	if (mlx->door.xdoor == i && mlx->door.ydoor == j)
		mlx->map[mlx->door.xdoor][mlx->door.ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}
