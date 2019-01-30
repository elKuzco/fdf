/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:17:58 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/19 11:21:56 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptrs1;
	unsigned char *ptrs2;

	ptrs1 = (unsigned char*)s1;
	ptrs2 = (unsigned char*)s2;
	while (n--)
	{
		if (*ptrs1 != *ptrs2)
			return ((int)(*ptrs1 - *ptrs2));
		ptrs1++;
		ptrs2++;
	}
	return (0);
}
