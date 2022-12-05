#include "so_long.h"

char	**move_up(char	**map, t_door_coord *door, int i, int j)
{
	if (map[i - 1][j] == 'E')
	{
		door->xdoor = i - 1;
		door->ydoor = j;
	}
	map[i - 1][j] = 'P';
	map[i][j] = '0';
	if (door->xdoor && door->ydoor && map[door->xdoor][door->ydoor] == '0')
		map[door->xdoor][door->ydoor] = 'E';
	printf("move to up\n");
	return (map);
}

char	**move_down(char	**map, t_door_coord *door, int i, int j)
{
	if (map[i + 1][j] == 'E')
	{
		door->xdoor = i + 1;
		door->ydoor = j;
	}
	map[i + 1][j] = 'P';
	map[i][j] = '0';
	if (door->xdoor && door->ydoor && map[door->xdoor][door->ydoor] == '0')
		map[door->xdoor][door->ydoor] = 'E';
	printf("move to down\n");
	return (map);
}

char	**move_right(char	**map, t_door_coord *door, int i, int j)
{
	if (map[i][j + 1] == 'E')
	{
		door->xdoor = i;
		door->ydoor = j + 1;
	}
	map[i][j + 1] = 'P';
	map[i][j] = '0';
	if (door->xdoor && door->ydoor && map[door->xdoor][door->ydoor] == '0')
		map[door->xdoor][door->ydoor] = 'E';
	printf("move to right\n");
	return (map);
}

char	**move_left(char	**map, t_door_coord *door, int i, int j)
{
	if (map[i][j - 1] == 'E')
	{
		door->xdoor = i;
		door->ydoor = j - 1;
	}
	map[i][j - 1] = 'P';
	map[i][j] = '0';
	if (door->xdoor && door->ydoor && map[door->xdoor][door->ydoor] == '0')
		map[door->xdoor][door->ydoor] = 'E';
	printf("move to left\n");
	return (map);
}
