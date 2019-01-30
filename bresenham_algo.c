/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:19:19 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/26 17:06:33 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"
#include <math.h>

void fill_pixel(int *my_image_string, int x, int y, int color)
{
//	printf("Start fill_pixel\n x: %i | y: %i\n", x,y);
/*	if (color == 0)
		color = 0xff;
	else 
		color = 16775680; // Blue 0xF800
*/	
	//printf(" %i\n",y * WINDOW_WIDTH + x);
	/*
	if (x < 0)
		x = 0;
	if (x >= WINDOW_WIDTH)
		x = WINDOW_WIDTH - 1 ;
	if (y < 0)
		y = 0;
	if (y > WINDOW_HEIGHT)
		y = WINDOW_HEIGHT;
		if ((y * WINDOW_WIDTH + x) < WINDOW_WIDTH * WINDOW_HEIGHT )
			my_image_string[y * WINDOW_WIDTH + x] = color;
*/

	if ((x < WINDOW_WIDTH ) && (x >= 0 ) && (y < WINDOW_HEIGHT) && (y >= 0))
	{	
	//	if (my_image_string[y * WINDOW_WIDTH + x] != 0xff)
			my_image_string[y * WINDOW_WIDTH + x] = color;
	}
	//printf("End fill_pixel\n");
}
/*
int choice_color(t_lst_coord *pt1, t_lst_coord *pt2)
{
	if ((pt1->z == 10) || pt2->z == 10)
		return (convert_rgb(0x0,0xff,0x0,0x0));
	return(255);
}*/

/*int choice_color(t_lst_coord *pt1, t_lst_coord *pt2, int coef;)
{
	
	int r;
	
	if (pt1->z < pt2->z)
	{
	//	printf("Color R[%i]G[%i]B[%i]\n",pt1->rcolor,pt1->gcolor,pt1->bcolor);
		pt1->rcolor += 2 ;
		if (pt1->gcolor > 0)
			pt1->gcolor -= 2;
	//	printf(" After Color{<} R[%i]G[%i]B[%i]\n",pt1->rcolor,pt1->gcolor,pt1->bcolor);
		return (convert_rgb(0x0,pt1->rcolor,pt1->gcolor,pt1->bcolor));
	}
	else if (pt1->z == pt2->z)
		return (convert_rgb(0x0,pt2->rcolor,pt2->gcolor,pt2->bcolor));
	else if (pt1->z > pt2->z)
		{
	//		printf("Color R[%i]G[%i]B[%i]\n",pt1->rcolor,pt1->gcolor,pt1->bcolor);
			pt1->bcolor += 2 ;
			if (pt1->gcolor > 0)
				pt1->gcolor -= 2;
			printf(" After Color {>} R[%i]G[%i]B[%i]\n",pt1->rcolor,pt1->gcolor,pt1->bcolor);
			return (convert_rgb(0x0,pt1->rcolor,pt1->gcolor,pt1->bcolor));
		}
	//return (convert_rgb(0x0,0x0,0x0,0xff));
	//return(255);
}*/

double calcul_ratio(t_lst_coord *pt1, t_lst_coord *pt2, double middle)
{
	double distance;

	//distance = sqrt(pow(pt2->c_x - pt1->c_x,2) +pow(pt2->c_y - pt1->c_y,2));
	distance = sqrt(pow(pt2->c_x - pt1->c_x,2) +pow(pt2->c_y - pt1->c_y,2) +pow(pt2->c_z - pt1->c_z,2));
	//printf("distance = %f\n",255/distance);
	if (pt2->z > middle)
		return (pt2->rcolor/distance);
	else
		return (pt2->bcolor/distance);
}

int choice_color(t_lst_coord *pt1, t_lst_coord *pt2, int coef, double ratio)
{
	
	int r;
	int g;
	int b;
	//printf("%f",ratio);
	//ratio = 1;
	
	g = pt1->gcolor;
	r = pt1->rcolor;
	b = pt1->bcolor;
	if (pt1->z < pt2->z)
	{
	//	printf("[X:%i][Y:%i]Color R[%i]G[%i]B[%i]\n",pt1->x,pt1->y,pt1->rcolor,pt1->gcolor,pt1->bcolor);
		r = pt1->rcolor + ratio * coef ;
	/*	if (pt1->gcolor > 0)
			g = pt1->gcolor - ratio * coef;*/
	//	printf(" After Color{<} R[%i]G[%i]B[%i]\n",pt1->rcolor,pt1->gcolor,pt1->bcolor);
		return (convert_rgb(0x0,r,g,b));
	}
	else if (pt1->z == pt2->z)
	{
	//	printf("[X:%i][Y:%i]Color R[%i]G[%i]B[%i]\n",pt1->x,pt1->y,pt1->rcolor,pt1->gcolor,pt1->bcolor);
		return (convert_rgb(0x0,pt1->rcolor,pt1->gcolor,pt1->bcolor));
	}
	else
		{
	//		printf("[X:%i][Y:%i]Color R[%i]G[%i]B[%i]\n",pt1->x,pt1->y,pt1->rcolor,pt1->gcolor,pt1->bcolor);
//			b = pt2->bcolor;
			b = pt1->bcolor + ratio * coef ;
			//b = pt2->bcolor + ratio *coef; ;
/*			if (pt1->gcolor > 0)
				g = pt1->gcolor - ratio * coef;*/
	//		printf(" After Color {>} R[%i]G[%i]B[%i]\n",pt1->rcolor,pt1->gcolor,pt1->bcolor);
			return (convert_rgb(0x0,r,g,b));
		}
	return (convert_rgb(0x0,0x0,0x0,0xff));
	//return(255);
}

int draw_line(t_lst_coord *point1, t_lst_coord *point2, t_lst_env **img)
{
	double ex;
	double ey;
	double dx;
	double dy;
	double diff_x;
	double diff_y;
	int i;
	int xincr;
	int yincr;
	double x1;
	double x2;
	double y1;
	double y2;
	double ratio;
	
	ratio = calcul_ratio(point1, point2, (*img)->middle);
	
	x1 = point1->c_x;
	y1 = point1->c_y;
	x2 = point2->c_x;
	y2 = point2->c_y;
	xincr = 1;
	yincr = 1;
	ex = fabs(x2 - x1);
	ey = fabs(y2 - y1);
	dx = 2 * ex;
	dy = 2 * ey;
	diff_x = ex;
	diff_y = ey;
	/*
	if (point1->x== 0 && point1->y == 1)
	{
		printf("##############\n");
	}
	printf("drawline ex : %f | ey: %f | dx: %f | dy: %f | diff_x : %f | diff_y : %f \n",ex,ey,dx,dy,diff_x,diff_y);
	*/
	i = 0;
	if (x1 > x2)
		xincr = -1;
	if (y1 > y2)
		yincr = -1;
	if (diff_x > diff_y)
	{
		while (i <= diff_x)
		{
			fill_pixel((*img)->data, x1, y1,choice_color(point1, point2,i, ratio));
			i++;
			x1 += xincr;
			ex -= dy;
			if (ex < 0)
			{
				y1 += yincr;
				ex += dx;
			}
		}
	}
	else /*if (diff_x < diff_y)*/
	{
		while (i <= diff_y)
		{
			fill_pixel((*img)->data, x1, y1, choice_color(point1, point2,i,ratio));
			i++;
			y1 += yincr;
			ey -= dx;
			if (ey < 0)
			{
				x1 += xincr;
				ey += dy;
			}
		}
	}
	printf("i= %i | ratio = %f\n",i,ratio);
	return (1);
}


/*
int draw_line(t_lst_coord *point1, t_lst_coord *point2, t_lst_env **img) {
  
  int dx,dy,i,xinc,yinc,cumul,x,y,xi,yi,xf,yf ;
  xi = point1->c_x;
  yi = point1->c_y;
  xf = point2->c_x;
  yf = point2->c_y;
  
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx) ;
  dy = abs(dy) ;
  fill_pixel((*img)->data, x, y, choice_color(point1->z, point2->z));
  if ( dx > dy ) {
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ ) {
      x += xinc ;
      cumul += dy ;
      if ( cumul >= dx ) {
        cumul -= dx ;
        y += yinc ; }
     fill_pixel((*img)->data, x, y, choice_color(point1->z, point2->z)) ; } }
    else {
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) {
      y += yinc ;
      cumul += dx ;
      if ( cumul >= dy ) {
        cumul -= dy ;
        x += xinc ; }
     fill_pixel((*img)->data, x, y, point1->z) ; } }
	 return (1);
}*/