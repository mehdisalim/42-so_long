/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:07:15 by esalim            #+#    #+#             */
/*   Updated: 2022/12/17 13:44:46 by esalim           ###   ########.fr       */
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

t_list	*init_lists(char **map)
{
	int i, j;
	t_list	*enemy = NULL;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
				ft_lstadd_back(&enemy, ft_lstnew(getcontent('X', i, j)));

			j++;
		}
		i++;
	}
	return (enemy);
}