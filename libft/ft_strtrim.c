/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:43:25 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/19 11:36:22 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_start(char const *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static	int		ft_end(char const *str)
{
	int i;

	i = (ft_strlen(str) - 1);
	while (ft_isspace(str[i]))
		i--;
	return ((i));
}

static	char	*return_blank(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		size;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	start = ft_start(s);
	i = 0;
	size = ft_strlen(s);
	end = ft_end(s);
	if (end <= 0)
		return (return_blank());
	size = size - (size - end) - start;
	if (!(str = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	while (start < end + 1)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
