#include "so_long.h"

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
	  else if (c == '0')
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg10.xpm", &i, &i), y, x);
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
		y = -50;;
		while (map[i][j] && strchr("10ECP", map[i][j]))
			put_img(mlx, map[i][j++], x, (y += 50));
		x += 50;
		i++;
	}
}

char	**changeplayerinmap(char	**map, int direction)
{
	int	i = -1, j;
	static t_door_coord door;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && direction == 13 && map[i - 1][j] != '1')
				return (move_up(map, &door, i, j));
			if (map[i][j] == 'P' && direction == 0 && map[i][j - 1] != '1')
				return (move_left(map, &door, i, j));
			if (map[i][j] == 'P' && direction == 1 && map[i + 1][j] != '1')
				return (move_down(map, &door, i, j));
			if (map[i][j] == 'P' && direction == 2 && map[i][j + 1] != '1')
				return (move_right(map, &door, i, j));
		}
	}
	return (map);
}

int genkey(int key, t_data *mlx)
{
	if (key == 53)
		exit(1);
	if ((key >= 0 && key < 3) || key == 13)
	{
 		mlx->map = changeplayerinmap(mlx->map, key);
		drawing_map(*mlx, mlx->map);
	}
	return (0);
}

void	setup_background(t_data mlx, int height, int width)
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

int main()
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
	mlx.map = map;
	mlx.win = mlx_new_window(mlx.ptr, height, width, "so_long");
	setup_background(mlx, height, width);
	drawing_map(mlx, mlx.map);
	mlx_key_hook(mlx.win, genkey, &mlx);
	mlx_loop(mlx.ptr);
	return 0;
}

