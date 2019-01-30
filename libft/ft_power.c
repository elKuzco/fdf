/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:15:26 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/18 14:22:37 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_power(long int nb, int power)
{
	int				i;
	long long int	numbr;

	numbr = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	while (i < power)
	{
		numbr = nb * numbr;
		i++;
	}
	return (numbr);
}
