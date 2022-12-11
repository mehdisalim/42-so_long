/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:26:00 by esalim            #+#    #+#             */
/*   Updated: 2022/12/09 20:37:28 by esalim           ###   ########.fr       */
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

int	check_door(char **s)
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
			if (s[i][j] == 'E')
				p++;
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

	message = "Error: there is invalid characters in the map";
	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (!ft_strchr("E01PCX\n", s[i][j]))
				return (ft_printf(message), 0);
	}
	return (1);
}

int	check_condition(char **s)
{
	int	i;
	int	j;

	if (!check_wall(s))
		return (0);
	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == 'C' || s[i][j] == 'P' || s[i][j] == 'E')
				if (s[i - 1][j] == '1' && s[i + 1][j] == '1'
					&& s[i][j - 1] == '1' && s[i][j + 1] == '1')
					return (ft_printf("the condition is inside wall :(\n"), 0);
		}
	}
	return (1);
}