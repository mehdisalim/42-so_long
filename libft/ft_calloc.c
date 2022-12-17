/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:02:23 by esalim            #+#    #+#             */
/*   Updated: 2022/12/09 13:29:31 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;

	if (count >= SIZE_MAX && size >= SIZE_MAX)
		return (0);
	dest = (char *)malloc(count * size);
	if (!dest)
		return (0);
	ft_bzero(dest, count * size);
	return (dest);
}
