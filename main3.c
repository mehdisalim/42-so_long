#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	gere_key(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	printf("the keycode is : %d\n", keycode);
	return (0);
}

int	main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 500, 500, "hello");
	mlx_key_hook(win, gere_key, (void *) 0);
	mlx_loop(mlx);
//	option1();
}
