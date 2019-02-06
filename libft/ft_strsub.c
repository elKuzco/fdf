/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:40:15 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/19 11:39:51 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!(s))
		return (0);
	while ((*s) && i < start)
	{
		s++;
		i++;
	}
	if (ft_strlen(s) < len)
		return (NULL);
	if (!(str = ft_strndup(s, len)))
		return (NULL);
	str[len] = '\0';
	return (str);
}
