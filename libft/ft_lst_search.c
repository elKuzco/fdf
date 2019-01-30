/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:58:20 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/18 17:04:35 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_search(t_list **alst, void *content, size_t len)
{
	int		i;
	t_list	*ptr;

	if (!*alst || !alst)
		return (0);
	i = 0;
	ptr = (*alst);
	while (ptr)
	{
		if (ft_memcmp(content, ptr->content, len) == 0)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (0);
}
