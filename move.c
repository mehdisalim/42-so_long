#include "so_long.h"

char **move_up(t_data *mlx, t_door_coord *door, int i, int j)
{
	if (door->xdoor == i - 1 && door->ydoor == j && mlx->isopen == 1)
		exit(0);
	if (mlx->map[i - 1][j] == 'E')
	{
		door->xdoor = i - 1;
		door->ydoor = j;
	}
	if (mlx->map[i - 1][j] == 'C')
		mlx->ncoins += 1;
	mlx->map[i - 1][j] = 'P';
	if (door->xdoor == i && door->ydoor == j)
		mlx->map[door->xdoor][door->ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}

char **move_down(t_data *mlx, t_door_coord *door, int i, int j)
{
	if (door->xdoor == i + 1 && door->ydoor == j && mlx->isopen == 1)
		exit(0);
	if (mlx->map[i + 1][j] == 'E')
	{
		door->xdoor = i + 1;
		door->ydoor = j;
	}
	if (mlx->map[i + 1][j] == 'C')
		mlx->ncoins += 1;
	mlx->map[i + 1][j] = 'P';
	if (door->xdoor == i && door->ydoor == j)
		mlx->map[door->xdoor][door->ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}

char **move_right(t_data *mlx, t_door_coord *door, int i, int j)
{
	if (door->xdoor == i && door->ydoor == j + 1 && mlx->isopen == 1)
		exit(0);
	if (mlx->map[i][j + 1] == 'E')
	{
		door->xdoor = i;
		door->ydoor = j + 1;
	}
	if (mlx->map[i][j + 1] == 'C')
		mlx->ncoins += 1;
	mlx->map[i][j + 1] = 'P';
	if (door->xdoor == i && door->ydoor == j)
		mlx->map[door->xdoor][door->ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}

char **move_left(t_data *mlx, t_door_coord *door, int i, int j)
{
	if (door->xdoor == i && door->ydoor == j - 1 && mlx->isopen == 1)
		exit(0);
	if (mlx->map[i][j - 1] == 'E')
	{
		door->xdoor = i;
		door->ydoor = j - 1;
	}
	if (mlx->map[i][j - 1] == 'C')
		mlx->ncoins += 1;
	mlx->map[i][j - 1] = 'P';
	if (door->xdoor == i && door->ydoor == j)
		mlx->map[door->xdoor][door->ydoor] = 'E';
	else
		mlx->map[i][j] = '0';
	return (mlx->map);
}
