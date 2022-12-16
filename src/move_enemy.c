/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:56:15 by esalim            #+#    #+#             */
/*   Updated: 2022/12/16 15:55:53 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int move_enemy(t_data *mlx)
{
    static int  x;
	int o,p,r;

	r = &o - &p;
    // static int  w;
    x++;
    t_list *lst;
	// int a = 0;

	// void	*img = mlx_xpm_file_to_image(mlx->ptr, "./assets/background/bg3.xpm", &a, &a);
    lst = mlx->lists.enemy;
    if (x == 12000)
    {
		// mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50 - 50, lst->content.y * 50);
        if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
        {
            mlx->map[lst->content.x][lst->content.y] = '0';
            mlx->map[lst->content.x][lst->content.y + 1] = 'X';
            // mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img0, lst->content.x * 50 - 50, lst->content.y * 50);
            for (size_t i = 0; mlx->map[i]; i++)
                ft_printf("%s", mlx->map[i]);
            setup_background(*mlx);
            drawing_map(mlx);
			if (mlx->map[lst->content.x][lst->content.y + 1] == 'P')
			{
				ft_printf("=======> You lose <======\n");
				exit(1);
			}
            lst->content.y += 1;
			if (mlx->map[lst->content.x  - 1][lst->content.y] == '0')
				x = 0;
			if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
				x = 12001;
			if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
				x = 4001;
        }
    }
    if (x == 8000)
    {
		// mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50 - 50, lst->content.y * 50);
        if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
        {

            mlx->map[lst->content.x][lst->content.y] = '0';
            mlx->map[lst->content.x][lst->content.y - 1] = 'X';
            // mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img0, lst->content.x * 50 - 50, lst->content.y * 50);
            for (size_t i = 0; mlx->map[i]; i++)
                ft_printf("%s", mlx->map[i]);
            setup_background(*mlx);
            drawing_map(mlx);
			if (mlx->map[lst->content.x][lst->content.y - 1] == 'P')
			{
				ft_printf("=======> You lose <======\n");
				exit(1);
			}
            lst->content.y -= 1;
			if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
				x = 12001;
			if (mlx->map[lst->content.x - 1][lst->content.y] == '0')
				x = 0;
			if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
				x = 8001;
        }
    }
	if (x == 4000)
    {
		// mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50 - 50, lst->content.y * 50);
        if (mlx->map[lst->content.x - 1][lst->content.y] == '0')
        {

            mlx->map[lst->content.x][lst->content.y] = '0';
            mlx->map[lst->content.x - 1][lst->content.y] = 'X';
            // mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img0, lst->content.x * 50 - 50, lst->content.y * 50);
            for (size_t i = 0; mlx->map[i]; i++)
                ft_printf("%s", mlx->map[i]);
            setup_background(*mlx);
            drawing_map(mlx);
			if (mlx->map[lst->content.x - 1][lst->content.y] == 'P')
			{
				ft_printf("=======> You lose <======\n");
				exit(1);
			}
            lst->content.x -= 1;	
			if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
				x = 8001;
			if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
				x = 12001;
			if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
				x = 4001;
        }
    }
	if (x == 16000)
    {
		// mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50 - 50, lst->content.y * 50);
        if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
        {

            mlx->map[lst->content.x][lst->content.y] = '0';
            mlx->map[lst->content.x + 1][lst->content.y] = 'X';
            // mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img0, lst->content.x * 50 - 50, lst->content.y * 50);
            for (size_t i = 0; mlx->map[i]; i++)
                ft_printf("%s", mlx->map[i]);
            setup_background(*mlx);
            drawing_map(mlx);
			if (mlx->map[lst->content.x + 1][lst->content.y] == 'P')
			{
				ft_printf("=======> You lose <======\n");
				exit(1);
			}
            lst->content.x += 1;
            if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
				x = 4001;
			if (mlx->map[lst->content.x - 1][lst->content.y] == '0')
				x = 0;
			if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
				x = 8001;
        }
    }
    // if (x == 8000 && mlx->map[lst->content.x][lst->content.y - 1] == '0')
    // {
	// 	// mlx_put_image_to_window(mlx->ptr, mlx->win, img, lst->content.x * 50, lst->content.y * 50);
    //     mlx->map[lst->content.x][lst->content.y] = '0';
    //     mlx->map[lst->content.x][lst->content.y - 1] = 'X';
	// 	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->imgs.enemy.img0, lst->content.x * 50 + 50, lst->content.y * 50);
    //     for (size_t i = 0; mlx->map[i]; i++)
    //     {
    //         ft_printf("%s", mlx->map[i]);
    //     }
    //     drawing_map(mlx);
    //     x = 0;
    //     return (0);
    // }
    return 0;
}