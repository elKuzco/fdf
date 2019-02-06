/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:08:59 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/09 13:13:10 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	if (ft_isascii((char)c) == 0)
		return (NULL);
	while ((i > 0) && ((s[i]) != (char)c))
		i--;
	if ((s[i] == (char)c))
		return ((char *)&s[i]);
	return (NULL);
}
