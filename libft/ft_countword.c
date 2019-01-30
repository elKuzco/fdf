/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:33:47 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/08 20:50:16 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countword(char *str, char sep)
{
	int	inaword;
	int	count;
	int i;

	inaword = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			if (inaword == 0)
			{
				inaword = 1;
				count++;
			}
		}
		else
			inaword = 0;
		i++;
	}
	return (count);
}
