/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:19:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 13:15:25 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"
#include "mlx.h"
#include <math.h>

/*
**                 #######################################
**                 ############### fill_pix ##############
**                 #######################################
**
** Change in the imag->data, the color of the pixel at the coordonnate
** x and y; image data is a char*, each 4 octets is a pixel.
*/

void	fill_pix(t_lst_env **img, int x, int y, int color)
{
	if ((*img)->color_mode == false)
		color = 0xffff;
	if ((x < (*img)->w_width) && (x >= 0)
		&& (y < (*img)->w_height) && (y >= 0))
	{
		(*img)->data[y * (*img)->w_width + x] = color;
	}
}

/*
**                 #########################################
**                 ############### calcul_ratio ############
**                 #########################################
**
** Calcul the distance between two points and divide the ending color by
** that value. That's create a smooth blend effect.
*/

double	calcul_ratio(t_lst_coord *pt1, t_lst_coord *pt2, double middle)
{
	double distance;

	distance = sqrt(pow(pt2->c_x - pt1->c_x, 2)
		+ pow(pt2->c_y - pt1->c_y, 2) + pow(pt2->c_z - pt1->c_z, 2));
	if (pt2->z > middle)
		return (round(pt2->rcolor / distance));
	else
		return (round(pt2->bcolor / distance));
}

/*
**                 #########################################
**                 ############### increase_x ##############
**                 #########################################
**
** Part of the bresenham's algorithm, calcul the value of the closest pixel
** and call fill_pix function. More informations about bresenham and the tab
** below.
*/

void	increase_x(t_lst_coord *point1, t_lst_coord *point2, t_lst_env **img,
		double *tab)
{
	int		i;

	if (tab[0] > tab[2])
		tab[5] = -1;
	if (tab[1] > tab[3])
		tab[6] = -1;
	i = 0;
	while (i <= tab[11])
	{
		fill_pix(img, tab[0], tab[1], choice_color(point1, point2, i, tab[4]));
		i++;
		tab[0] += tab[5];
		tab[7] -= tab[10];
		if (tab[7] < 0)
		{
			tab[1] += tab[6];
			tab[7] += tab[9];
		}
	}
}

/*
**                 #########################################
**                 ############### increase_y ##############
**                 #########################################
**
** Part of the bresenham's algorithm, calcul the value of the closest pixel
** and call fill_pix function. More informations about bresenham and the tab
** below.
*/

void	increase_y(t_lst_coord *point1, t_lst_coord *point2, t_lst_env **img,
		double *tab)
{
	int		i;

	if (tab[0] > tab[2])
		tab[5] = -1;
	if (tab[1] > tab[3])
		tab[6] = -1;
	i = 0;
	while (i <= tab[12])
	{
		fill_pix(img, tab[0], tab[1], choice_color(point1, point2, i, tab[4]));
		i++;
		tab[1] += tab[6];
		tab[8] -= tab[9];
		if (tab[8] < 0)
		{
			tab[0] += tab[5];
			tab[8] += tab[10];
		}
	}
}

/*
**                 #########################################
**                 ############### draw_line ##############
**                 #########################################
**
** Main part of the Bresenham algorithm
** tab[0] = x1 { point 1 coordonate x }
** tab[1] = y1 { point 1 coordonate y }
** tab[2] = x2 { point 2 coordonate x }
** tab[3] = y2  { point 2 coordonate y }
** tab[4] = ratio {Ratio between distance between points and final color }
** tab[5] = xincr {incrementation of x}
** tab[6] = yincr {incrementation of y}
** tab[7] = ex margin of error for x
** tab[8] = ey margin of error for y
** tab[9] = dx gradient (slope) of x
** tab[10] = dy gradient (slope) of y
** tab[11] = diff_x {Different (abs) between x2 and x1 }
** tab[12] = diff_y {Different (abs) between y2 and y1 }
*/

int		draw_line(t_lst_coord *point1, t_lst_coord *point2, t_lst_env **img)
{
	double *tab;

	if (!(tab = (double*)malloc(sizeof(double) * 13)))
		return (0);
	tab[0] = point1->c_x;
	tab[1] = point1->c_y;
	tab[2] = point2->c_x;
	tab[3] = point2->c_y;
	tab[4] = calcul_ratio(point1, point2, (*img)->middle);
	tab[5] = 1;
	tab[6] = 1;
	tab[7] = fabs(tab[2] - tab[0]);
	tab[8] = fabs(tab[3] - tab[1]);
	tab[9] = 2 * tab[7];
	tab[10] = 2 * tab[8];
	tab[11] = tab[7];
	tab[12] = tab[8];
	if (tab[11] > tab[12])
		increase_x(point1, point2, img, tab);
	else
		increase_y(point1, point2, img, tab);
	free(tab);
	return (1);
}
