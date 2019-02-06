/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:46:48 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/17 19:10:39 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		size_max;
	int		null_term;

	j = 0;
	null_term = 1;
	if (ft_strlen(dst) >= size)
	{
		i = (int)size;
		null_term = 0;
	}
	else
		i = (ft_strlen(dst));
	size_max = i;
	while ((src[j] != '\0') && (j < ((int)(size) - size_max - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (null_term == 1)
		dst[i] = '\0';
	return ((size_t)(size_max + ft_strlen(src)));
}
