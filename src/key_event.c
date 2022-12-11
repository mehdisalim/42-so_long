/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:15:55 by esalim            #+#    #+#             */
/*   Updated: 2022/12/09 19:59:03 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	checker(t_data *mlx, int *movecounter, char *imgname, char *direction)
{
	int	q;

	q = 50;
	mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, imgname, &q, &q);
	display_counter(mlx, ++(*movecounter), direction);
	ft_printf("%d ==> %s\n", *movecounter, direction);
}

static char	**getmap(t_data *mlx, int *mc, int dir, int i)
{
	int	j;

	j = -1;
	while (mlx->map[i][++j])
	{
		if (mlx->map[i][j] == 'P' && (dir == 13 || dir == 126)
			&& mlx->map[i - 1][j] != '1')
			return (checker(mlx, mc, "./assets/P/elf0.xpm", "  move up"),
				move_up(mlx, i, j));
		if (mlx->map[i][j] == 'P' && (dir == 0 || dir == 123)
			&& mlx->map[i][j - 1] != '1')
			return (checker(mlx, mc, "./assets/P/elf1.xpm", "  move left"),
				move_left(mlx, i, j));
		if (mlx->map[i][j] == 'P' && (dir == 1 || dir == 125)
			&& mlx->map[i + 1][j] != '1')
			return (checker(mlx, mc, "./assets/P/elf0.xpm", "  move down"),
				move_down(mlx, i, j));
		if (mlx->map[i][j] == 'P' && (dir == 2 || dir == 124)
			&& mlx->map[i][j + 1] != '1')
			return (checker(mlx, mc, "./assets/P/elf0.xpm", "  move right"),
				move_right(mlx, i, j));
	}
	return (0);
}

char	**changeplayerinmap(t_data *mlx, int dir)
{
	int			i;
	static int	mc;
	char		**map;

	i = -1;
	while (mlx->map[++i])
	{
		map = getmap(mlx, &mc, dir, i);
		if (map)
			return (map);
	}
	return (mlx->map);
}

int	key_hook(int key, t_data *mlx)
{
	if (key == 53)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(0);
	}
	if ((key >= 0 && key < 3) || (key >= 123 && key <= 126) || key == 13)
	{
		mlx->map = changeplayerinmap(mlx, key);
		drawing_map(mlx);
	}
	return (0);
}
