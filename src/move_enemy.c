/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:56:15 by esalim            #+#    #+#             */
/*   Updated: 2022/12/16 21:13:35 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int move_enemy(t_data *mlx)
{
    static int  x;
	static int t,d,r,l;

    x++;
    t_list *lst;
    loop_hook(mlx);
    lst = mlx->lists.enemy;
	if (x == 4000)
    {
        while (lst)
        {
            if (mlx->map[lst->content.x - 1][lst->content.y] == '0' && l++ < 4)
            {

                mlx->map[lst->content.x][lst->content.y] = '0';
                mlx->map[lst->content.x - 1][lst->content.y] = 'X';
                for (size_t i = 0; mlx->map[i]; i++)
                    ft_printf("%s", mlx->map[i]);
                setup_background(*mlx);
                drawing_map(mlx);
                lst->content.x -= 1;	
                if (mlx->map[lst->content.x - 1][lst->content.y] == 'P')
                {
                    ft_printf("=======> You lose <======\n");
                    exit(1);
                }
                if (mlx->map[lst->content.x  - 1][lst->content.y] == '0')
                    x = 1;
                else if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
                    x = 4001;
                else if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
                    x = 12001;
                else if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
                    x = 8001;
				else
					x = 0;
            }
            lst = lst->next;
        }
    }
    lst = mlx->lists.enemy;
    if (x == 8000)
    {
        while (lst)
        {
            if (mlx->map[lst->content.x][lst->content.y - 1] == '0' && d++ < 4)
            {

                mlx->map[lst->content.x][lst->content.y] = '0';
                mlx->map[lst->content.x][lst->content.y - 1] = 'X';
                setup_background(*mlx);
                drawing_map(mlx);
                lst->content.y -= 1;
                if (mlx->map[lst->content.x][lst->content.y - 1] == 'P')
                {
                    ft_printf("=======> You lose <======\n");
                    exit(1);
                }
                if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
                    x = 4001;
                else if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
                    x = 12001;
                else if (mlx->map[lst->content.x  - 1][lst->content.y] == '0')
                    x = 1;
                else if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
                    x = 8001;
				else
					x = 1;
            }
            lst = lst->next;
        }
    }
    lst = mlx->lists.enemy;
    if (x == 12000)
    {
        while (lst)
        {
            if (mlx->map[lst->content.x][lst->content.y + 1] == '0' && t++ < 4)
            {
                mlx->map[lst->content.x][lst->content.y] = '0';
                mlx->map[lst->content.x][lst->content.y + 1] = 'X';
                for (size_t i = 0; mlx->map[i]; i++)
                    ft_printf("%s", mlx->map[i]);
                setup_background(*mlx);
                drawing_map(mlx);
                lst->content.y += 1;
                if (mlx->map[lst->content.x][lst->content.y + 1] == 'P')
                {
                    ft_printf("=======> You lose <======\n");
                    exit(1);
                }
                if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
                    x = 8001;
                else if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
                    x = 4001;
                else if (mlx->map[lst->content.x  - 1][lst->content.y] == '0')
                    x = 1;
                else if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
                    x = 12001;
				else
					x = 0;
            }
            lst = lst->next;
        }
    }
    lst = mlx->lists.enemy;
	if (x == 16000)
    {
        while (lst)
        {
            if (mlx->map[lst->content.x + 1][lst->content.y] == '0' && r++ < 4)
            {

                mlx->map[lst->content.x][lst->content.y] = '0';
                mlx->map[lst->content.x + 1][lst->content.y] = 'X';
                for (size_t i = 0; mlx->map[i]; i++)
                    ft_printf("%s", mlx->map[i]);
                setup_background(*mlx);
                drawing_map(mlx);
                lst->content.x += 1;
                if (mlx->map[lst->content.x + 1][lst->content.y] == 'P')
                {
                    ft_printf("=======> You lose <======\n");
                    exit(1);
                }
                if (mlx->map[lst->content.x + 1][lst->content.y] == '0')
                    x = 12001;
                else if (mlx->map[lst->content.x][lst->content.y + 1] == '0')
                    x = 8001;
                else if (mlx->map[lst->content.x  - 1][lst->content.y] == '0')
                    x = 1;
                else if (mlx->map[lst->content.x][lst->content.y - 1] == '0')
                    x = 4001;
				else
					x = 0;
            }
			
            lst = lst->next;
        }
    }
    return 0;
}