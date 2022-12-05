#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_map
{
	char	*name;
	char	**map;
	int		xsize;
	int		ysize;
	int		ncoins;
	int		nplayer;
	int		ndoor;
	int		nempty;
}	t_map;

typedef struct	s_img
{
	void	*img;
	int		height;
	int		width;
	int		x;
	int		y;
	int		count;
	
}	t_img;


typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		height;
	int		width;
	char	*title;
	
}	t_mlx;

int	gere_key(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
	{
 		
	}
	printf("the keycode is : %d\n", keycode);

	return (0);
}

int	main()
{
	int u = 50;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 500, 500, "hello");
	mlx_key_hook(win, gere_key, (void *) 0);
	int i = 0;
	while (i < 500)
	{
		int j = 0;
		void *img = mlx_xpm_file_to_image(mlx, "./assets/bg10.xpm", &u, &u);
		while (j < 500)
		{
			mlx_put_image_to_window(mlx, win, img, i, j);
			j += 50;
		}
		i += 50;
	}
	
	mlx_loop(mlx);
//	option1();
}
