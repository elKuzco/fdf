/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:00:31 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/19 11:20:17 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	else
	{
		ft_memset(ptr, 0, size);
		return ((void *)ptr);
	}
}
