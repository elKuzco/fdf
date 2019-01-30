/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:00:31 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/17 18:18:27 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = NULL;
	if (!list)
		return (NULL);
	while (list)
	{
		ft_lstadd_end(&new, f(list));
		list = list->next;
	}
	return (new);
}
