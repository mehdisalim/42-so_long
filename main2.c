#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minilibx/mlx.h"
#include "so_long.h"

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 1920

void	put_img(t_data mlx, const char	c, int	x, int y)
{
	int	i = 50;

	  if (c == '1')
	  	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/tree.xpm", &i, &i), y, x);
	  else if (c == 'E')
	  	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/door.xpm", &i, &i), y, x);
	  else if (c == 'P')
		  mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/elf3.xpm", &i, &i), y, x);
	  else if (c == 'C')
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/coins12.xpm", &i, &i), y, x);
	  else
	  	return ;
}

void	drawing_map(t_data	mlx, char **map)
{
	int	i = 0;
	int	j;
	int x = 0;
	int y;
	while (map[i])
	{
		j = 0;
		y = 0;
		while (map[i][j])
		{
			if (strchr("10ECP", map[i][j]))
				put_img(mlx, map[i][j], x, y);
			y += 50;
			j++;
		}
		x += 50;
		i++;
	}
}

int genkey(int key, t_data mlx)
{
	int i = 50;
	if (key == 53)
		exit(1);
	if (key == 13)
	{
		  mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/elf3.xpm", &i, &i), 50, 50);
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	char	**map = getfullcontent("maps");

	if (!map)
		exit(0);
	if (!check_size(map) || !check_wall(map) || !check_players(map) || !check_invalid_char(map)
			|| !check_door(map) || !check_coins(map) || !check_condition(map))
		exit(0);
	int	height = (strlen(map[0]) - 1) * 50;
	int width = doublestrlen(map) * 50;
	t_data mlx;
	mlx.ptr = mlx_init();
	mlx.title = "so long";
	mlx.win = mlx_new_window(mlx.ptr, height, width, mlx.title);
	int x = -50;
	int y;
	int s = 50;
	while ((x += 50) < height)
	{
		y = -50;
		while ((y += 50) < width)
	  		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg10.xpm", &s, &s), x, y);
	}
	drawing_map(mlx, map);
	mlx_key_hook(mlx.win, genkey, 0);
	mlx_loop(mlx.ptr);
	return 0;
}

