/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:24:42 by esalim            #+#    #+#             */
/*   Updated: 2022/12/19 15:36:50 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	getnumberoflines(const char *filename)
{
	int		i;
	int		fd;
	char	*str;

	i = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: this file ( %s ) doesn't work !!", filename);
		exit(1);
	}
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**getfullcontent(const char *filename)
{
	int		fd;
	int		i;
	char	**text;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	text = malloc(getnumberoflines(filename) * sizeof(char *));
	if (!text)
	{
		ft_printf("Error: malloc doesn't allocate memory\n");
		exit(1);
	}
	i = -1;
	while (1)
	{
		text[++i] = get_next_line(fd);
		if (!text[i])
			break ;
	}
	close(fd);
	return (text);
}
