/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:17:01 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:46:14 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>

/*
**                 #########################################
**                 ###############convert_rgb ##############
**                 #########################################
**
** Get the alpha value(a), red value(r), green(g), blue (b), and return a
** unsigned int :
**|| 1 octet || 2 octet || 3 octet || 4 octet ||
**||  alpha  ||   Red   ||  Green  ||   Blue  ||
*/

unsigned int	convert_rgb(unsigned int a, unsigned int r, unsigned int g,
	unsigned int b)
{
	unsigned int nb;

	if (a > 0xff)
		a = 0xff;
	if (r > 0xff)
		r = 0xff;
	if (g > 0xff)
		g = 0xff;
	if (b > 0xff)
		b = 0xff;
	nb = ((a << 24) | (r << 16) | (g << 8) | (b));
	return (nb);
}

/*
**                 ########################################
**                 ############### upper_alt ##############
**                 ########################################
**
** Part of the function set_color_gradient, calcul the initial color of the
** point, if it egal or upper the average altitude.
** Only the Red value change.
*/

void			upper_alt(t_lst_coord *ptr, t_lst_env **env)
{
	float ratio;

	if (ptr->z == (*env)->max_z)
	{
		ptr->rcolor = 255;
		ptr->bcolor = 0;
	}
	else
	{
		ratio = 255 / ((*env)->max_z - (*env)->middle);
		ptr->rcolor = (ratio * ptr->z);
		ptr->bcolor = 0;
	}
}

/*
**                 ########################################
**                 ############### lower_alt ##############
**                 ########################################
**
** Part of the function set_color_gradient, calcul the initial color of the
** point, if it egal or below the average altitude.
** Only the Blue value change.
*/

void			lower_alt(t_lst_coord *ptr, t_lst_env **env)
{
	float ratio;

	if (ptr->z == (*env)->min_z)
	{
		ptr->rcolor = 0;
		ptr->bcolor = 255;
	}
	else
	{
		ratio = 255 / ((*env)->middle - (*env)->min_z);
		ptr->rcolor = 0;
		ptr->bcolor = (ratio * -ptr->z);
	}
}

/*
**                 ########################################
**                 ######### set_color_gradient ###########
**                 ########################################
**
** Calcul the average altitude value = all z upper shift to red, and
** all z below shift to blue. The value of the green is flat.
*/

void			set_color_gradient(t_lst_coord *ptr, t_lst_env **env)
{
	(*env)->middle = ((*env)->max_z + (*env)->min_z);
	(*env)->middle /= 2;
	if (ptr->z >= (*env)->middle)
		upper_alt(ptr, env);
	else
		lower_alt(ptr, env);
	ptr->gcolor = 100;
}

/*
**                 ########################################
**                 ############ choice_color ##############
**                 ########################################
**
** This function is call in Bresenham algorithm (bresenham_algo.c).
** Calcul the color's value of the pixel :
** It's depend the color of the final point, and the ratio between the pixel
** and the remain distance.
*/

int				choice_color(t_lst_coord *pt1, t_lst_coord *pt2, int coef,
							double ratio)
{
	int	r;
	int	g;
	int	b;

	g = pt1->gcolor;
	r = pt1->rcolor;
	b = pt1->bcolor;
	if (pt1->z < pt2->z)
	{
		r = pt1->rcolor + ratio * coef;
		return (convert_rgb(0x0, r, g, b));
	}
	else if (pt1->z == pt2->z)
	{
		return (convert_rgb(0x0, pt1->rcolor, pt1->gcolor, pt1->bcolor));
	}
	else
	{
		b = pt1->bcolor + ratio * coef;
		return (convert_rgb(0x0, r, g, b));
	}
	return (convert_rgb(0x0, 0x0, 0x0, 0xff));
}
