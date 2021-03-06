/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:47:05 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:45:37 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>

/*
**                 ########################################
**                 ############ create_lst #############
**                 ########################################
**
** Create a list of points :
** x = initial x value
** y = initial y value
** z = initial z value
** c_x = current x value
** c_y = current y value
** c_z = current z value
** next = ptr on the next points
** upon = ptr on the points below (same x, y + 1)
** color = value of red, green, blue (0 ->255)
*/

int		create_lst(t_lst_coord **first, t_lst_coord **lst)
{
	if (*first)
	{
		if (!((*lst)->next = (t_lst_coord*)malloc(sizeof(t_lst_coord))))
			return (0);
		(*lst) = (*lst)->next;
	}
	else
	{
		if (!((*lst) = (t_lst_coord*)malloc(sizeof(t_lst_coord))))
			return (0);
		*first = *lst;
	}
	(*lst)->x = 0;
	(*lst)->y = 0;
	(*lst)->z = 0;
	(*lst)->rcolor = 0;
	(*lst)->gcolor = 0;
	(*lst)->bcolor = 0;
	(*lst)->c_x = 0;
	(*lst)->c_y = 0;
	(*lst)->next = NULL;
	(*lst)->upon = NULL;
	return (1);
}
