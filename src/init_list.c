/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:07:15 by esalim            #+#    #+#             */
/*   Updated: 2022/12/18 19:38:49 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_content	getcontent(char c, int x, int y)
{
	t_content	content;

	content.c = c;
	content.x = x;
	content.y = y;
	return (content);
}

t_list	*init_lists(char **map)
{
	t_list	*enemy;
	int		i;
	int		j;

	enemy = NULL;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'X')
				ft_lstadd_back(&enemy, ft_lstnew(getcontent('X', i, j)));
	}
	return (enemy);
}
