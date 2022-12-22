/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:26:00 by esalim            #+#    #+#             */
/*   Updated: 2022/12/22 12:55:27 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_coins(char **s)
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
			if (s[i][j] == 'C')
				p++;
	}
	if (p == 0)
		return (ft_printf("Error: there is no coins in the map :(\n"), 0);
	return (p);
}

int	check_door(char **s, t_data *mlx)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == 'E')
			{
				mlx->door.xdoor = i;
				mlx->door.ydoor = j;
				p++;
			}
		}
	}
	if (p == 0)
		return (ft_printf("Error: there is (no|multi) door in the map\n"), 0);
	return (1);
}

int	check_invalid_char(char **s)
{
	int		i;
	int		j;
	char	*message;

	i = -1;
	message = "Error: there is invalid characters in the map";
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (!ft_strchr("E01PCX\n", s[i][j]))
				return (ft_printf(message), 0);
	}
	return (1);
}

void	check_conditions(char **map, int *i, int *j)
{
	if (map[*i][*j] == 'P')
	{
		if (!ft_strchr("1PX", map[*i][*j + 1]))
		{
			map[*i][*j + 1] = 'P';
			*i = 0;
		}
		else if (!ft_strchr("1PX", map[*i][*j - 1]))
		{
			map[*i][*j - 1] = 'P';
			*i = 0;
		}
		else if (!ft_strchr("1PX", map[*i + 1][*j]))
		{
			map[*i + 1][*j] = 'P';
			*i = 0;
		}
		else if (!ft_strchr("1PX", map[*i - 1][*j]))
		{
			map[*i - 1][*j] = 'P';
			*i = 0;
		}
	}
}

int	check_path(char **map)
{
	int	i;
	int	j;

	if (!check_wall(map))
		return (0);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			check_conditions(map, &i, &j);
	}
	i = -1;
	while (map[++i])
		if (ft_strchr(map[i], 'C') || ft_strchr(map[i], 'E'))
			return (ft_printf("Error: map invalid !\n"), 0);
	return (1);
}
