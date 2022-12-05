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


int main()
{
	t_win	win;
	t_mlx	mlx;

	win.height = 600;
	win.width = 800;
	win.title = "so_long";
	mlx.ptr = mlx_init();
	win.win = mlx_new_window(mlx.ptr, win.height, win.width, win.title);
	mlx.win = win;
	mlx_loop(mlx.ptr);

}

