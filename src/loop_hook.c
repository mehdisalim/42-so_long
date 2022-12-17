/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:30 by esalim            #+#    #+#             */
/*   Updated: 2022/12/17 18:36:11 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	loop_hook(t_data *mlx)
{
	static int i;
	i++;
	int a = 0;
	void	*img = mlx_xpm_file_to_image(mlx->ptr, "./assets/background/bg3.xpm", &a, &a);
	t_list *lst;
	if (i == 1000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			ft_printf("Enemy (%c) :  x ===> %d  y ===> %d \n", lst->content.c, lst->content.y * 50, lst->content.y);
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img0, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 2000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img1, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 3000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img2, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 4000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img3, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 5000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img4, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 6000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img5, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 7000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img6, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 8000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img7, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 9000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img8, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 10000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img9, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 11000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img10, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
	}
	if (i == 12000/2)
	{
		lst = mlx->enemy;
		while (lst)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50, (lst->content.x + 1) * 50);
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img11, lst->content.y * 50, (lst->content.x + 1) * 50);
			lst = lst->next;
		}
		i = 0;
	}
	return (0);
}