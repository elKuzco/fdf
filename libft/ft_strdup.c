/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:35:31 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/20 16:38:38 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		size;

	size = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	return (ft_strcpy(s2, s1));
}
