/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:32:31 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/18 16:57:55 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_len(t_list **alst)
{
	int		i;
	t_list	*ptr;

	if (!alst || !(*alst))
		return (0);
	i = 1;
	ptr = (*alst);
	while (ptr->next)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
