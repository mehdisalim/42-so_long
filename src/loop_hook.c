/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:30 by esalim            #+#    #+#             */
/*   Updated: 2022/12/18 13:53:00 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	setimage(t_data	*mlx, void	*img, int *i)
{
	t_list	*lst;

	lst = mlx->enemy;
	while (lst)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.smallbg,
			lst->content.y * 50, (lst->content.x + 1) * 50);
		mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.y * 50,
			(lst->content.x + 1) * 50);
		lst = lst->next;
	}
	if (*i == 11000 / 2)
		*i = 0;
}

int	loop_hook(t_data *mlx)
{
	static int	i;

	if (++i == 1000 / 2)
		setimage(mlx, mlx->imgs.enemy.img0, &i);
	if (i == 2000 / 2)
		setimage(mlx, mlx->imgs.enemy.img1, &i);
	if (i == 3000 / 2)
		setimage(mlx, mlx->imgs.enemy.img2, &i);
	if (i == 4000 / 2)
		setimage(mlx, mlx->imgs.enemy.img3, &i);
	if (i == 5000 / 2)
		setimage(mlx, mlx->imgs.enemy.img4, &i);
	if (i == 6000 / 2)
		setimage(mlx, mlx->imgs.enemy.img5, &i);
	if (i == 7000 / 2)
		setimage(mlx, mlx->imgs.enemy.img6, &i);
	if (i == 8000 / 2)
		setimage(mlx, mlx->imgs.enemy.img7, &i);
	if (i == 9000 / 2)
		setimage(mlx, mlx->imgs.enemy.img8, &i);
	if (i == 10000 / 2)
		setimage(mlx, mlx->imgs.enemy.img9, &i);
	if (i == 11000 / 2)
		setimage(mlx, mlx->imgs.enemy.img10, &i);
	return (0);
}
