/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalim <esalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:13:22 by esalim            #+#    #+#             */
/*   Updated: 2022/12/15 10:00:12 by esalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(t_content))
{
	t_list	*list;

	if (!lst || !del)
		return ;
	list = *lst;
	while (list)
	{
		list = list->next;
		ft_lstdelone(*lst, del);
		*lst = list;
	}
}
