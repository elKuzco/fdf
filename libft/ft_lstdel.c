/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:47:27 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/17 16:05:35 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *next_link;

	if ((!alst) && !(*alst))
		return ;
	next_link = (*alst)->next;
	while (next_link)
	{
		next_link = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next_link;
	}
	*alst = NULL;
}
