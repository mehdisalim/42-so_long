/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:56:15 by esalim            #+#    #+#             */
/*   Updated: 2022/12/22 12:31:41 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	enemy_to_left(t_data *mlx, int *x)
{
	t_list	*lst;

	lst = mlx->enemy;
	while (lst)
	{	
		if (mlx->map[lst->content.x - 1][lst->content.y] == 'P')
			destroy_game(mlx, "=======> You lose <======");
		if (mlx->map[lst->content.x - 1][lst->content.y] == '0'
			|| mlx->map[lst->content.x - 1][lst->content.y] == 'P')
		{
			mlx->map[lst->content.x][lst->content.y] = '0';
			mlx->map[lst->content.x - 1][lst->content.y] = 'X';
			setup_background(*mlx);
			drawing_map(mlx);
			lst->content.x -= 1;
		}
		lst = lst->next;
	}
	*x = 0;
}

void	enemy_to_up(t_data *mlx, int *x)
{
	t_list	*lst;

	lst = mlx->enemy;
	while (lst)
	{
		if (mlx->map[lst->content.x][lst->content.y - 1] == 'P')
			destroy_game(mlx, "=======> You lose <======");
		if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
		{
			mlx->map[lst->content.x][lst->content.y] = '0';
			mlx->map[lst->content.x][lst->content.y - 1] = 'X';
			setup_background(*mlx);
			drawing_map(mlx);
			lst->content.y -= 1;
		}
		lst = lst->next;
	}
	*x = rand() % 10000 + 1;
}

void	enemy_to_down(t_data *mlx, int *x)
{
	t_list	*lst;

	lst = mlx->enemy;
	while (lst)
	{
		if (mlx->map[lst->content.x][lst->content.y + 1] == 'P')
			destroy_game(mlx, "=======> You lose <======");
		if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
		{
			mlx->map[lst->content.x][lst->content.y] = '0';
			mlx->map[lst->content.x][lst->content.y + 1] = 'X';
			setup_background(*mlx);
			drawing_map(mlx);
			lst->content.y += 1;
		}
		lst = lst->next;
	}
	*x = rand() % 10000 + 1;
}

void	enemy_to_right(t_data *mlx, int *x)
{
	t_list	*lst;

	lst = mlx->enemy;
	while (lst)
	{
		if (mlx->map[lst->content.x + 1][lst->content.y] == 'P')
			destroy_game(mlx, "=======> You lose <======");
		if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
		{
			mlx->map[lst->content.x][lst->content.y] = '0';
			mlx->map[lst->content.x + 1][lst->content.y] = 'X';
			setup_background(*mlx);
			drawing_map(mlx);
			lst->content.x += 1;
		}
		lst = lst->next;
	}
	*x = rand() % 20000 + 1;
}

int	move_enemy(t_data *mlx)
{
	static int	x;

	x++;
	loop_hook(mlx);
	if (x == 4000)
		enemy_to_up(mlx, &x);
	else if (x == 8000)
		enemy_to_right(mlx, &x);
	else if (x == 12000)
		enemy_to_down(mlx, &x);
	else if (x > 16000)
		enemy_to_left(mlx, &x);
	return (0);
}
