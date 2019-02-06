/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:29:35 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/12 13:39:26 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(str = ft_strdup((char *)s)))
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = f(str[i]);
		i++;
	}
	return (str);
}
