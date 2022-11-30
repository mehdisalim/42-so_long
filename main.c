#include <mlx.h>

typedef struct	s_photo {
	void	*img;
	int		h;
	int		w;
}				t_photo;
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	t_photo pho;
	t_photo d;
}				t_data;

int	main(void)
{

	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.pho.img = mlx_xpm_file_to_image(img.mlx, "test.xpm", &img.pho.w, &img.pho.h);
	img.d.img = mlx_xpm_file_to_image(img.mlx, "test.xpm", &img.pho.w, &img.pho.h);
	mlx_put_image_to_window(img.mlx, img.win, img.pho.img, 0, 0);
	mlx_put_image_to_window(img.mlx, img.win, img.d.img, 500, 500);
	mlx_loop(img.mlx);
}