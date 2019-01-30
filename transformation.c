/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:18:08 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/23 12:14:37 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

void rotation_axis_z(t_lst_coord *point, double angle, int width, int height)
{
	
	angle = angle * M_PI/180;
	//point->c_x = cos(angle) * point->x  -sin(angle) * point->y;
	//point->c_y = sin(angle) * point->x + cos(angle) * point->y;
	
	point->c_x = cos(angle) * (point->x -(width/2)) -sin(angle) * (point->y - (height/2));
	point->c_y = sin(angle) * (point->x -(width/2)) + cos(angle) * (point->y - (height/2));
	point->c_z = point->z;
/*
	point->c_x = (cos(angle) * point->c_x + -sin(angle) * point->c_y);
	point->c_y = sin(angle) * point->c_x + cos(angle) * point->c_y;
*/
}

void rotation_axis_y(t_lst_coord *point, double angle, int width, int height)
{
	int tmp;
	
	tmp = point->c_x;
	angle = angle * M_PI/180;
	point->c_x = sin(angle) * (point->c_z)+ cos(angle) * point->c_x;
	point->c_z = cos(angle) * (point->c_z) - sin(angle) * tmp;

	
	//point->c_x = cos(angle) * point->c_x  -sin(angle) * (point->z);
	//point->c_z = sin(angle) * tmp + cos(angle) * (point->z);
	
	/*
	point->c_x = cos(angle) * (point->x -(width/2)) + -sin(angle) * (point->z - (height/2));
	point->c_z = -sin(angle) * (point->x -(width/2)) + cos(angle) * (point->z - (height/2));
	*/
}

void rotation_axis_x(t_lst_coord *point, double angle, int width, int height)
{
	int tmp;

	tmp = point->c_y;
	angle = angle * M_PI/180;
	point->c_y = cos(angle) * point->c_y  - sin(angle) * (point->c_z);
	point->c_z = sin(angle) * tmp + cos(angle) * (point->c_z);
	/*point->c_x = cos(angle) * (point->x -(width/2)) + -sin(angle) * (point->z - (height/2));
	point->c_z = -sin(angle) * (point->x -(width/2)) + cos(angle) * (point->z - (height/2));*/
}

void	translation(t_lst_coord *point, t_lst_env **env)
{
	/*(*env)->center_x = (WINDOW_WIDTH / 2 - ((*env)->column / 2) * (*env)->coef_x)/6;
	(*env)->center_y = (WINDOW_HEIGHT / 2 - ((*env)->line / 2) * (*env)->coef_y)/6;
	*/
	(*env)->center_x = (WINDOW_WIDTH / 2);
	(*env)->center_y = (WINDOW_HEIGHT / 2);
	point->c_x += (*env)->center_x + (*env)->x ;
	point->c_y += (*env)->center_y + (*env)->y;
	
}

void	parallele(t_lst_coord *point, t_lst_env **env)
{
	(*env)->rotx = 0; //M_PI/16// +2	
	(*env)->roty = 0;
	(*env)->rotz = 0;
	
	point->c_x = point->x + 0.5 * point->z;
	point->c_y = point->y + 0.5/2 * point->z;
}

void	scale_up(t_lst_coord *point, t_lst_env **env)
{
	point->c_x *= (*env)->coef_x;
	point->c_y *= (*env)->coef_y; 
	point->c_z *= (*env)->coef_z;
	
}
