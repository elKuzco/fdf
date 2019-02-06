/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:59:33 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/19 11:33:32 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t n;

	if (ft_strlen(nee) == 0)
		return ((char *)hay);
	n = ft_strlen(nee);
	while ((*hay) && (len >= n))
	{
		if (ft_strncmp(hay, nee, n) == 0)
			return ((char *)hay);
		hay++;
		len--;
	}
	return (0);
}
