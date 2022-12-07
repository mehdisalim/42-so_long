#include "minilibx/mlx.h"
#include <stdio.h>

typedef struct s_win
{
	void	*win;
	int		height;
	int		width;
	char	*title;
}	t_win;

typedef	struct s_mlx
{
	void	*ptr;
	t_win	win;

}	t_mlx;


void	setup_background(void *ptr, void *win, int height, int width)
{	
	int x = -50;
	int y;
	int s = 50;
	while ((x += 50) < height)
	{
		y = -50;
		while ((y += 50) < width)
	  		mlx_put_image_to_window(ptr, win, mlx_xpm_file_to_image(ptr, "./assets/bg10.xpm", &s, &s), x, y);
	}
}

int main()
{
//	t_win	win;
//	t_mlx	mlx;
	void	*ptr, *win, *img;
	ptr = mlx_init();
	win = mlx_new_window(ptr, 800, 400, "Menu");
	setup_background(ptr, win, 800, 400);

	mlx_loop(ptr);
}

