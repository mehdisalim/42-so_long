#include "so_long.h"

char	**move_up(t_data *mlx, t_door_coord *door, int i, int j)
{
	if (mlx->map[i - 1][j] == 'E')
	{
		door->xdoor = i - 1;
		door->ydoor = j;
	}
	if (mlx->map[i - 1][j] == 'C')
		mlx->ncoins += 1;
	mlx->map[i - 1][j] = 'P';
	mlx->map[i][j] = '0';
	if (door->xdoor && door->ydoor && mlx->map[door->xdoor][door->ydoor] == '0')
		mlx->map[door->xdoor][door->ydoor] = 'E';
	return (mlx->map);
}

char	**move_down(t_data	*mlx, t_door_coord *door, int i, int j)
{
	if (mlx->map[i + 1][j] == 'E')
	{
		door->xdoor = i + 1;
		door->ydoor = j;
	}
	if (mlx->map[i + 1][j] == 'C')
		mlx->ncoins += 1;
	mlx->map[i + 1][j] = 'P';
	mlx->map[i][j] = '0';
	if (door->xdoor && door->ydoor && mlx->map[door->xdoor][door->ydoor] == '0')
		mlx->map[door->xdoor][door->ydoor] = 'E';
	return (mlx->map);
}

char	**move_right(t_data	*mlx, t_door_coord *door, int i, int j)
{
	if (mlx->map[i][j + 1] == 'E')
	{
		door->xdoor = i;
		door->ydoor = j + 1;
	}
	if (mlx->map[i][j + 1] == 'C')
		mlx->ncoins += 1;
	mlx->map[i][j + 1] = 'P';
	mlx->map[i][j] = '0';
	if (door->xdoor && door->ydoor && mlx->map[door->xdoor][door->ydoor] == '0')
		mlx->map[door->xdoor][door->ydoor] = 'E';
	return (mlx->map);
}

char	**move_left(t_data *mlx, t_door_coord *door, int i, int j)
{
	if (mlx->map[i][j - 1] == 'E')
	{
		door->xdoor = i;
		door->ydoor = j - 1;
	}
	if (mlx->map[i][j - 1] == 'C')
		mlx->ncoins += 1;
	mlx->map[i][j - 1] = 'P';
	mlx->map[i][j] = '0';
	if (door->xdoor && door->ydoor && mlx->map[door->xdoor][door->ydoor] == '0')
		mlx->map[door->xdoor][door->ydoor] = 'E';
	return (mlx->map);
}