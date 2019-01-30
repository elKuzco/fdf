/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:00:37 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/18 18:58:02 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_sqrt(double nb)
{
	double precision;
	double sup;

	if (nb <= 0)
		return (0);
	precision = 0.01;
	sup = 1;
	while (sup * sup < nb)
		sup++;
	while (sup * sup > nb)
		sup -= precision;
	return (sup);
}
