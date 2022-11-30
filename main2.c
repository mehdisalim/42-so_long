#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minilibx/mlx.h"

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 1920

char	**getfullcontent(const char *filename);
int	doublestrlen(char	**s);
int	check_size(char	**s);
int	check_wall(char	**s);
int	check_players(char	**s);
int	check_door(char	**s);
int	check_coins(char	**s);
int	check_invalid_char(char	**s);
int	check_condition(char	**s);

typedef	struct	s_img {
	void	*img;
	int		height;
	int		width;
	char	*filename;
}	t_img;

typedef struct s_data {
	void	*ptr;
	void	*win;
	void	*img;
	int		width;
	int		height;
	char	*title;
}		t_data;

void	put_empty(t_data mlx, int x, int y)
{
		int i = 50;
		static int	istrue;
		if (istrue == 0)
		{
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg.xpm", &i, &i), y, x);
			istrue = 3;
		}
		else if (istrue == 1)
		{
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg1.xpm", &i, &i), y, x);
			istrue = 2;
		}
		else if (istrue == 2)
		{
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg2.xpm", &i, &i), y, x);
			istrue = 0;
		}
		else if (istrue == 3)
		{
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg3.xpm", &i, &i), y, x);
			istrue = 1;
		}
		else
			istrue = 0;
}

void	put_img(t_data mlx, const char	c, int	x, int y)
{
	int	i = 50;

	  if (c == '1')
	  	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/tree.xpm", &i, &i), y, x);
	  else if (c == 'E')
	  	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/door.xpm", &i, &i), y, x);
	  else if (c == '0')
		  put_empty(mlx, x, y);
	  else if (c == 'P')
	  	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/elf4.xpm", &i, &i), y, x);
	  else if (c == 'C')
	  	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/coins4.xpm", &i, &i), y, x);
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
	printf("width ==> %d   height ==> %d\n", width, height);
	

	char	filename[] = "./png.png";
	t_img	img;
	img.width = 100;
	img.height = 50;
	img.filename = "./assets/rock.xpm";
	t_data mlx;
	mlx.ptr = mlx_init();
	mlx.height = 20;
	mlx.width = 10;
	mlx.title = "hello world";
	mlx.win = mlx_new_window(mlx.ptr, height, width, mlx.title);
	int i = 0;
	int j;
	int istrue = 1;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{

			//mlx_pixel_put(mlx.ptr, mlx.win, i, j, 0x81ca30);
		//	if (istrue == 0)
		//	{
		//		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg.xpm", &mlx.height, &mlx.width), i, j);
		//		istrue = 3;
		//	}
		//	else if (istrue == 1)
		//	{
		//		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg1.xpm", &mlx.height, &mlx.width), i, j);
		//		istrue = 2;
		//	}
		//	else if (istrue == 2)
		//	{
		//		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg2.xpm", &mlx.height, &mlx.width), i, j);
		//		istrue = 0;
		//	}
		//	else if (istrue == 3)
		//	{
		//		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx_xpm_file_to_image(mlx.ptr, "./assets/bg3.xpm", &mlx.height, &mlx.width), i, j);
		//		istrue = 1;
		//	}
		//	else
		//		istrue = 0;
			j++;
		}
		i++;
	}
//	mlx_pixel_put(mlx.ptr, mlx.win, 10, 10, 0x0BE353);
	
	drawing_map(mlx, map);
	mlx_loop(mlx.ptr);
	return 0;
}

