/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:07:06 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/09 13:12:14 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (ft_isascii((char)c) == 0)
		return (NULL);
	while ((s[i] != '\0') && ((s[i]) != (char)c))
		i++;
	if ((s[i] == (char)c))
		return ((char *)&s[i]);
	return (NULL);
}
