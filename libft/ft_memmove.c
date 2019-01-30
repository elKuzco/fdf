/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:01:12 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/19 11:23:12 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*ptrd;
	const unsigned char		*ptrs;

	if (!len)
		return (dst);
	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
			ptrd[len] = ptrs[len];
	}
	else if (src > dst)
	{
		while (len--)
			*(ptrd++) = *(ptrs++);
	}
	return (dst);
}
