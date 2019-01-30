/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:17:01 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/26 17:01:50 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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
	nb = ((a << 24) |(r << 16) |(g << 8) | (b));
	return (nb);
}

/* Penser a creer ration in event*/
/*
int set_color_gradient(t_lst_coord *ptr,t_lst_env **env)
{
	float ratio;
	int (*env)->middle =0 ;
	
	
	
	//(*env)->middle = ((*env)->max_z + abs((*env)->min_z))/2;
	
	
	if (ptr->z > 0)
	{
		if ((*env)->max_z == 0)
		{
			ptr->rcolor = 0;
		//	ptr->gcolor = 255;
			ptr->bcolor = 255;
		}
		else 
		{
			ratio = 255/ (*env)->max_z; 
			ptr->rcolor = (ratio * ptr->z);
		//	ptr->gcolor = 255;
			ptr->bcolor = 0;
		}
	}
	else 
	{	
		if ((*env)->min_z == (*env)->middle)
		{
			ptr->rcolor = 0;
		//	ptr->gcolor = 255;
			ptr->bcolor = 255;
		}
		else 
		{
			ratio = 255/ -(*env)->min_z; 
			ptr->rcolor = 0;
		//	ptr->gcolor = 255;
			ptr->bcolor = (ratio * -ptr->z);
		}
	}
	ptr->gcolor = 100;
	printf("[X:%i][Y:%i] = R(%i)G(%i)B(%i)\n ",ptr->x,ptr->y,ptr->rcolor,ptr->gcolor,ptr->bcolor);
	
}
*/
int set_color_gradient(t_lst_coord *ptr,t_lst_env **env)
{
	float ratio;
	
	
	//if ((*env)->min_z < 0)
		(*env)->middle = ((*env)->max_z + (*env)->min_z);
		(*env)->middle /= 2 ;
	//else 
	//	(*env)->middle = ((*env)->max_z - (*env)->min_z)/2 ;
		
	printf("(*env)->middle = %f\n",(*env)->middle);
	
	if (ptr->z >= (*env)->middle) // work with 0 
	{
		if (ptr->z == (*env)->max_z)
		{
			ptr->rcolor = 255;
			ptr->bcolor = 0;
		}
		else 
		{
			ratio = 255/ ((*env)->max_z -(*env)->middle) ; 
			ptr->rcolor = (ratio * ptr->z);
			ptr->bcolor = 0;
			printf("ratio = %f\n",ratio);
		}
	}
	else 
	{	
		if (ptr->z == (*env)->min_z)
		{
			ptr->rcolor = 0;
			ptr->bcolor = 255;
		}
		else 
		{
			ratio = 255/ ((*env)->middle -(*env)->min_z); 
			
			ptr->rcolor = 0;
			ptr->bcolor = (ratio * -ptr->z);
			printf("ratio = %f\n",ratio);
		}
	}
	ptr->gcolor = 100;
	
	printf("[X:%i][Y:%i] = R(%i)G(%i)B(%i)\n ",ptr->x,ptr->y,ptr->rcolor,ptr->gcolor,ptr->bcolor);
	
}