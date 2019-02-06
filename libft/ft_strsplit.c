/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:34:13 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 16:29:40 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		count_char(char *str, char sep)
{
	int i;

	i = 0;
	while ((str[i] != sep) && (str[i] != '\0'))
		i++;
	return (i);
}

static char		*ft_strndup2(char **s1, char sep)
{
	char	*s2;
	int		i;
	size_t	n;

	n = count_char(*s1, sep);
	i = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * n + 1)))
		return (0);
	while ((**s1 != sep) && (**s1 != '\0'))
	{
		s2[i] = **s1;
		(*s1)++;
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		n;

	if ((!s) || (!c))
		return (NULL);
	i = 0;
	n = ft_countword((char*)s, c);
	if (!(tab = (char**)malloc(sizeof(char *) * n + 1)))
		return (NULL);
	while ((*s != '\0') && i < n)
	{
		while (*s == c)
			s++;
		if ((*s != c) && (*s))
		{
			if (!(tab[i++] = ft_strndup2((char **)&s, c)))
			{
				free(tab);
				return (NULL);
			}
		}
	}
	tab[i] = 0;
	return (tab);
}
