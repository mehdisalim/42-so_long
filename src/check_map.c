/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:00:39 by esalim            #+#    #+#             */
/*   Updated: 2022/12/09 20:32:15 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	doublestrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_size(char **s)
{
	int		i;
	size_t	len;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (!len)
		{
			len = ft_strlen(s[i]);
			continue ;
		}
		if (!ft_strchr(s[i], '\n'))
		{
			if (len != ft_strlen(s[i]) + 1)
				return (ft_printf("Error: the size is not the same.\n"), 0);
			return (1);
		}
		else if (len != ft_strlen(s[i]))
			return (ft_printf("Error: the size is not the same.\n"), 0);
	}
	return (1);
}

int	check_wall(char **content)
{
	int	x;
	int	y;
	int	xlen;
	int	ylen;

	x = 0;
	y = 0;
	xlen = ft_strlen(content[y]) - 1;
	ylen = doublestrlen(content);
	while (x < xlen)
	{
		if (!ft_strchr(content[ylen - 1], '\n') && !x)
			xlen -= 1;
		if (content[y][x] != '1' || content[ylen - 1][x] != '1')
			return (ft_printf("Error: wall is incorrect !\n"), 0);
		x++;
	}
	y = -1;
	while (++y < ylen)
		if (content[y][0] != '1'
			|| (content[y][xlen] != '1' && (y == ylen))
			|| (content[y][xlen - 1] != '1' && (y + 1 == ylen)))
			return (ft_printf("Error: wall is incorrect !\n"), 0);
	return (1);
}

int	check_players(char **s)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] == 'P')
				p++;
	}
	if (p == 1)
		return (1);
	return (ft_printf("Error: there is no (or multi) players in the map\n"), 0);
}
