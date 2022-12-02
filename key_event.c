#include "mlx.h"
#include "stdio.h"

int	close_window(int keycode, t_data mlx)
{
	if (keycode != 53)
		return (0);
	mlx_destroy_window(mlx.ptr, mlx.win);
	exit(1);
}
