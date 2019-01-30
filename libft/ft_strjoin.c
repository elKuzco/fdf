/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:34:51 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/19 12:07:13 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		size;

	if (!(s1) && (s2))
		return (ft_strdup(s2));
	if (!(s2) && (s1))
		return (ft_strdup(s1));
	if (!(s1) && !(s2))
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = '\0';
	return (str - size);
}
