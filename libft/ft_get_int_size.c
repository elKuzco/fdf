/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:39:42 by qlouisia          #+#    #+#             */
/*   Updated: 2018/11/17 19:50:35 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_int_size(long long int n)
{
	int				size;
	int long long	nb;

	size = 1;
	nb = n;
	if (nb < 0)
	{
		size++;
		nb = nb * -1;
	}
	while ((nb / 10) > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}
