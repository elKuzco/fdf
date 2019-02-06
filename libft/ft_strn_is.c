/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:20:33 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/18 19:01:17 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strn_is(char *str, char *charset, size_t n)
{
	size_t	i;
	char	same;

	same = 1;
	while (str && *str && n-- && same)
	{
		i = 0;
		same = 0;
		while (charset[i])
			if (*str == charset[i++])
				same = 1;
		if (same)
			str++;
	}
	return (same ? 1 : 0);
}
