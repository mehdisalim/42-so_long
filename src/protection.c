/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:00:32 by esalim            #+#    #+#             */
/*   Updated: 2022/12/22 10:36:07 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*get_image(t_data *mlx, char *filename)
{
	void	*img;
	int		a;
	char	*message;

	a = 50;
	img = mlx_xpm_file_to_image(mlx->ptr, filename, &a, &a);
	if (!img)
	{
		message = ft_strjoin("Error: Can not access to the file ", filename);
		ft_printf("%s \n", message);
		free(message);
		destroy_game(mlx, "");
		exit(1);
	}
	return (img);
}
