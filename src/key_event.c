#include "../include/so_long.h"

char **changeplayerinmap(t_data *mlx, int direction)
{
	int i = -1, j;
	int q = 50;
	static	int movecounter;

	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'P' && (direction == 13 || direction == 126) && mlx->map[i - 1][j] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/P/elf0.xpm", &q, &q);
				display_counter(mlx, ++movecounter, "  move up");
				return (ft_printf("%d ==> move to top\n", movecounter), move_up(mlx, i, j));
			}
			if (mlx->map[i][j] == 'P' && (direction == 0 || direction == 123) && mlx->map[i][j - 1] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/P/elf1.xpm", &q, &q);
				display_counter(mlx, ++movecounter, "  move left");
				return (ft_printf("%d ==> move to left\n", movecounter), move_left(mlx, i, j));
			}
			if (mlx->map[i][j] == 'P' && (direction == 1 || direction == 125) && mlx->map[i + 1][j] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/P/elf0.xpm", &q, &q);
				display_counter(mlx, ++movecounter, "  move down");
				return (ft_printf("%d ==> move to down\n", movecounter), move_down(mlx, i, j));
			}
			if (mlx->map[i][j] == 'P' && (direction == 2 || direction == 124) && mlx->map[i][j + 1] != '1')
			{
				mlx->playerimg = mlx_xpm_file_to_image(mlx->ptr, "./assets/P/elf0.xpm", &q, &q);
				display_counter(mlx, ++movecounter, "  move right");
				return (ft_printf("%d ==> move to right\n", movecounter), move_right(mlx, i, j));
			}
		}
	}
	return (mlx->map);
}

int key_hook(int key, t_data *mlx)
{
	if (key == 53)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(0);
	}
	if ((key >= 0 && key < 3)  || (key >= 123 && key <= 126) || key == 13)
	{
		mlx->map = changeplayerinmap(mlx, key);
		//mlx_clear_window(mlx->ptr, mlx->win);
		drawing_map(mlx);
	}
	return (0);
}
