/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:14:26 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/17 18:21:48 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!(alst))
		return ;
	if (!(*alst))
		(*alst) = new;
	else
	{
		ptr = (*alst);
		while ((ptr)->next)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
	}
	new->next = NULL;
}
