/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:18:08 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:46:10 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "math.h"

/*
**                 ########################################
**                 ########### rotation_axis_z ############
**                 ########################################
**
** In first, place the object's center at the origin, and apply matrice
** rotation of the z axis.
** Angle is convert from degree to radiant.
*/

void	rotation_axis_z(t_lst_coord *point, double angle, int width, int height)
{
	angle = angle * M_PI / 180;
	point->c_x = cos(angle) * (point->x - (width / 2))
	- sin(angle) * (point->y - (height / 2));
	point->c_y = sin(angle) * (point->x - (width / 2))
	+ cos(angle) * (point->y - (height / 2));
	point->c_z = point->z;
}

/*
**                 ########################################
**                 ########### rotation_axis_y ############
**                 ########################################
**
** Apply matrice rotation of the y axis to previously transformed point.
** Angle is convert from degree to radiant.
*/

void	rotation_axis_y(t_lst_coord *point, double angle)
{
	int tmp;

	tmp = point->c_x;
	angle = angle * M_PI / 180;
	point->c_x = sin(angle) * (point->c_z) + cos(angle) * point->c_x;
	point->c_z = cos(angle) * (point->c_z) - sin(angle) * tmp;
}

/*
**                 ########################################
**                 ########### rotation_axis_x ############
**                 ########################################
**
** Apply matrice rotation of the x axis to previously transformed point.
** Angle is convert from degree to radiant.
*/

void	rotation_axis_x(t_lst_coord *point, double angle)
{
	int tmp;

	tmp = point->c_y;
	angle = angle * M_PI / 180;
	point->c_y = cos(angle) * point->c_y - sin(angle) * (point->c_z);
	point->c_z = sin(angle) * tmp + cos(angle) * (point->c_z);
}

/*
**                 ########################################
**                 ############# translation ##############
**                 ########################################
**
** Translate the point, ot his previous place (center in the middle of the
** window) and add any movement that the user could ask.
*/

void	translation(t_lst_coord *point, t_lst_env **env)
{
	(*env)->center_x = ((*env)->w_width / 2);
	(*env)->center_y = ((*env)->w_height / 2);
	point->c_x += (*env)->center_x + (*env)->x;
	point->c_y += (*env)->center_y + (*env)->y;
}

/*
**                 #######################################
**                 ############## scale_up ###############
**                 #######################################
**
** Calcul the actual coordonate of the point, after the scale transformation.
*/

void	scale_up(t_lst_coord *point, t_lst_env **env)
{
	point->c_x *= (*env)->coef_x;
	point->c_y *= (*env)->coef_y;
	point->c_z *= (*env)->coef_z;
}
