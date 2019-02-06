/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:55:55 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:47:03 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdlib.h>
#include "mlx.h"
#include "../libft/libft.h"

/*
**                 #######################################
**                 ############# create_env ##############
**                 #######################################
**
** Create the main struct of the programm :
** column = number of points in a line
** line = number of lines
** first = ptr on the first link of the point list
** coef x,y,z = scale (pixel number between two points)
** x, y = store all move of the image
** rot x,y,z = the current amount of rotation in the 3 axis
** min_z = the lowest value of the z in all points
** max_z = the highest value of z in all points
** win_ptr = pointer window
** color_mode = toggle between unicolor color (false), and color (true)
*/

int	create_env(t_lst_env **env)
{
	if (!(*env = (t_lst_env*)malloc(sizeof(t_lst_env))))
		return (0);
	(*env)->column = 0;
	(*env)->line = 0;
	(*env)->first = NULL;
	(*env)->lst = NULL;
	(*env)->coef_x = 20;
	(*env)->coef_y = 20;
	(*env)->coef_z = 20;
	(*env)->x = 0;
	(*env)->y = 0;
	(*env)->rotx = 0;
	(*env)->roty = 0;
	(*env)->rotz = 0;
	(*env)->min_z = 0;
	(*env)->max_z = 0;
	(*env)->win_ptr = NULL;
	(*env)->color_mode = false;
	return (1);
}

/*
**                 ########################################
**                 ############ create_window #############
**                 ########################################
**
** Set all value needed for the display :
** w_width = width of the screen
** w_height = height of the screen
** mlx_ptr = ptr on mlw
** img_ptr = pointer on the image
** data = cast in a (*int), char * where all 4 octet represent a pixel
*/

int	create_window(t_lst_env **env, char *av)
{
	int width;
	int height;

	width = ((*env)->column + (*env)->max_z + abs((*env)->min_z)) * 40;
	height = ((*env)->line + (*env)->max_z + abs((*env)->min_z)) * 45;
	if (width > 2300)
		width = 2300;
	if (width < 800)
		width = 800;
	if (height > 1300)
		height = 1300;
	if (height < 600)
		height = 600;
	(*env)->w_width = width;
	(*env)->w_height = height;
	window_size(env);
	(*env)->mlx_ptr = mlx_init();
	(*env)->win_ptr = mlx_new_window((*env)->mlx_ptr, (*env)->w_width,
	(*env)->w_height, av);
	(*env)->img_ptr = mlx_new_image((*env)->mlx_ptr, (*env)->w_width,
	(*env)->w_height);
	(*env)->data = (int *)mlx_get_data_addr((*env)->img_ptr, &(*env)->bpp,
	&(*env)->size_l, &(*env)->endian);
	return (1);
}

/*
**                 ########################################
**                 ############## free_map ###############
**                 ########################################
**
** Free all the link in point's chain, and destroy image and window
*/

int	free_map(t_lst_env **env)
{
	t_lst_coord *tmp;

	while ((*env)->first)
	{
		tmp = (*env)->first->next;
		free((*env)->first);
		(*env)->first = tmp;
	}
	if ((*env)->win_ptr)
	{
		mlx_destroy_image((*env)->mlx_ptr, (*env)->img_ptr);
		mlx_destroy_window((*env)->mlx_ptr, (*env)->win_ptr);
	}
	free(*env);
	return (0);
}

/*
**                 ########################################
**                 ############ free_parsing ##############
**                 ########################################
**
** Function to free in the parsing part
*/

int	free_parsing(int *test, char *line)
{
	if (test)
		free(test);
	if (line)
		free(line);
	return (0);
}

/*
**                 ######################################
**                 ############# free_tab ###############
**                 ######################################
**
** Function to free properly tab in the convert_nbr function
*/

int	*free_tab(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}
