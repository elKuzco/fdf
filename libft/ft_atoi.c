/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:12:46 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/09 12:28:13 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	nb;
	long long	neg;

	i = 0;
	neg = 1;
	nb = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		i++;
		neg = -1;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) != 0)
	{
		nb = (str[i] - '0') + nb * 10;
		i++;
	}
	return (nb * neg);
}
