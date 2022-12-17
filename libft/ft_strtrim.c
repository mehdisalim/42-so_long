/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:07:06 by esalim            #+#    #+#             */
/*   Updated: 2022/12/09 18:23:01 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (0);
	while (ft_strchr((char *)set, *s))
		s++;
	len = ft_strlen(s) - 1;
	while (ft_strchr((char *)set, s[len]))
		len--;
	dest = malloc (len + 1);
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
