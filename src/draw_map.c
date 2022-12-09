#include "../include/so_long.h"

static char *getrandomcoin(int index)
{
	if (index == 0 || index == 4 || index == 8)
		return ("./assets/C/coin1.xpm");
	if (index == 1 || index == 5)
		return ("./assets/C/coin2.xpm");
	if (index == 2 || index == 6 || index == 9)
		return ("./assets/C/coin3.xpm");
	return ("./assets/C/coin4.xpm");
}

void	display_counter(t_data	*mlx, int movecounter, char	*s)
{
	int	i = 0;
	char	*mc = ft_itoa(movecounter);
	char	*string = ft_strjoin(mc, s);
	char	*nc = ft_itoa(mlx->ncoins);
	char	*string2 = ft_strjoin(nc, "  coins");
	if (movecounter != 0)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/background/bg.xpm", &i, &i), 0, 0);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/background/bg.xpm", &i, &i), mlx->height - 100, 0);
	}
	mlx_string_put(mlx->ptr, mlx->win, 10, 10, 0x000000, string);
	mlx_string_put(mlx->ptr, mlx->win, mlx->height - 100, 10, 0x000000, string2);
	free(mc);
	free(nc);
	free(string);
	free(string2);
}

void put_img(t_data *mlx, const char c, int x, int y)
{
	int i = 50;
	static t_door_coord door;
	
	if (c == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/1/tree.xpm", &i, &i), y, x);
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
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/E/dooropen.xpm", &i, &i), y, x);
		}
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/E/door.xpm", &i, &i), y, x);
	}
	else if (c == 'P' && door.xdoor == x && door.ydoor == y)
	{
		if (mlx->isopen)
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/E/dooropen.xpm", &i, &i), y, x);
		else
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/E/door.xpm", &i, &i), y, x);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->playerimg, y, x);
	}
	else if (c == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->playerimg, y, x);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, getrandomcoin(mlx->totalcoins % 10), &i, &i), y, x);
	else if (c == 'X')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/X/enemy.xpm", &i, &i), y, x);
	else if (c == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx_xpm_file_to_image(mlx->ptr, "./assets/background/bg.xpm", &i, &i), y, x);
	else
		return ;
}

void drawing_map(t_data *mlx)
{
	int i = 0;
	int j;
	int x = 50;
	int y;
	while (mlx->map[i])
	{
		j = 0;
		y = -50;
		while (mlx->map[i][j] && ft_strchr("10ECPX", mlx->map[i][j]))
			put_img(mlx, mlx->map[i][j++], x, (y += 50));
		x += 50;
		i++;
	}
}
