/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:07:15 by esalim            #+#    #+#             */
/*   Updated: 2022/12/15 19:08:24 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_content	getcontent(char c, int x, int y)
{
	t_content content;
	content.c = c;
	content.x = x;
	content.y = y;
	return (content);
}

t_linkedlist	init_lists(char **map)
{
	int i, j;
	t_linkedlist	lists = {0};

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
				ft_lstadd_back(&lists.enemy, ft_lstnew(getcontent('X', i, j)));
			if (map[i][j] == 'C')
				ft_lstadd_back(&lists.player, ft_lstnew(getcontent('C', i, j)));
			if (map[i][j] == 'P')
				ft_lstadd_back(&lists.coins, ft_lstnew(getcontent('P', i, j)));
			if (map[i][j] == 'E')
				ft_lstadd_back(&lists.door, ft_lstnew(getcontent('E', i, j)));
			j++;
		}
		i++;
	}
	return (lists);
}