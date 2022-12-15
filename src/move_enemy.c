/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:56:15 by esalim            #+#    #+#             */
/*   Updated: 2022/12/15 20:20:45 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int move_enemy(t_data *mlx)
{
    static int  x;
    x++;
    t_list *lst;
	int a = 0;

    lst = mlx->lists.enemy;
	void	*img = mlx_xpm_file_to_image(mlx->ptr, "./assets/background/bg3.xpm", &a, &a);
    if (x == 20000 && mlx->map[lst->content.x + 1][lst->content.y] == '0')
    {
		mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50, (lst->content.y * 50) + 50);
        mlx->map[lst->content.x][lst->content.y] = '0';
        mlx->map[lst->content.x + 1][lst->content.y] = 'X';
        drawing_map(mlx);
    }
    if (x == 40000 && mlx->map[lst->content.x][lst->content.y + 1] == '0')
    {
		mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50, (lst->content.y * 50) + 50);
        mlx->map[lst->content.x][lst->content.y] = '0';
        mlx->map[lst->content.x][lst->content.y + 1] = 'X';
        drawing_map(mlx);
    }
    if (x == 60000 && mlx->map[lst->content.x - 1][lst->content.y] == '0')
    {
		mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50, (lst->content.y * 50) + 50);
        mlx->map[lst->content.x - 1][lst->content.y] = 'X';
        mlx->map[lst->content.x][lst->content.y] = '0';
        drawing_map(mlx);
    }
    if (x == 80000 && mlx->map[lst->content.x][lst->content.y - 1] == '0')
    {
		mlx_put_image_to_window(mlx->ptr, mlx->win, img, (lst->content.x) * 50, (lst->content.y + 2) * 50);
        mlx->map[lst->content.x][lst->content.y - 1] = 'X';
        mlx->map[lst->content.x][lst->content.y] = '0';
        drawing_map(mlx);
        x = 0;
    }
    return 0;
}