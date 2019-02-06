/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:08:57 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:46:42 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../include/fdf.h"
#include <stdlib.h>
#include "../libft/libft.h"

/*
**                 ####################################
**                 ############## Print Ui#############
**                 ####################################
**                 Print all the UI, X,Y,Z and instructions
*/

void	print_ui(t_lst_env **env)
{
	char *rotz;
	char *rotx;
	char *roty;

	rotz = ft_itoa((*env)->rotz);
	roty = ft_itoa((*env)->roty);
	rotx = ft_itoa((*env)->rotx);
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 10, 255255255, "Z :");
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 60, 10, 255255255, rotz);
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 30, 255255255, "X :");
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 60, 30, 255255255, rotx);
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 50, 255255255, "Y :");
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 60, 50, 255255255, roty);
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 70,
					255255255, "Isometric [Press X]");
	mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, 30, 90,
					255255255, "Reset [Press R]");
	if ((*env)->rotz == 45 && (*env)->rotx > 35 && (*env)->rotx < 36
		&& (*env)->roty == 0)
		mlx_string_put((*env)->mlx_ptr, (*env)->win_ptr, (*env)->w_width
			/ 2 - 80, 20, 255255255, " Isomectric projection");
	free(rotz);
	free(rotx);
	free(roty);
}

/*
**                     ############################################
**                     ############### Refresh_image ##############
**                     ############################################
**
** Change to black all pixel  then refresh position of all points.
**           clean the window and finaly print the image in the window
*/

void	refresh_image(t_lst_env **env)
{
	int i;
	int n;

	n = (*env)->w_width * (*env)->w_height;
	i = 0;
	while (i < n)
	{
		(*env)->data[i] = 0;
		i++;
	}
	draw_grid(env);
	mlx_clear_window((*env)->mlx_ptr, (*env)->win_ptr);
	mlx_put_image_to_window((*env)->mlx_ptr, (*env)->win_ptr,
	(*env)->img_ptr, 0, 0);
	print_ui(env);
}

/*
**                   ########################################
**                   ############### scale_lst ##############
**                   ########################################
**
** Apply to all point of the list, transformation and set them to
** their current coordonates.
*/

void	scale_lst(t_lst_env **env)
{
	t_lst_coord	*ptr;

	ptr = (*env)->first;
	while (ptr)
	{
		rotation_axis_z(ptr, (*env)->rotz, (*env)->column, (*env)->line);
		scale_up(ptr, env);
		rotation_axis_y(ptr, (*env)->roty);
		rotation_axis_x(ptr, (*env)->rotx);
		translation(ptr, env);
		ptr = ptr->next;
	}
}

/*
**              ########################################
**              ############### draw_grid ##############
**              ########################################
**
** Draw the map using coordonate of the list, linking point to the next
** and the one below.
*/

int		draw_grid(t_lst_env **env)
{
	t_lst_coord *ptr;

	scale_lst(env);
	ptr = (*env)->first;
	while (ptr)
	{
		if (ptr->next && (ptr->y == ptr->next->y))
		{
			if (!draw_line(ptr, ptr->next, env))
				return (0);
		}
		if (ptr->upon)
		{
			if (!draw_line(ptr, ptr->upon, env))
				return (0);
		}
		ptr = ptr->next;
	}
	return (1);
}

/*
**              ########################################
**              ############### window_size ##############
**              ########################################
**
** Calcule the most suitable scale depending the colum size , line size and the
** difference between the min altitude and the max. with a minimum value of 1;
*/

void	window_size(t_lst_env **env)
{
	if ((*env)->column > (*env)->line)
	{
		(*env)->coef_x = ((*env)->w_width - 250) / ((*env)->column
			+ (*env)->max_z + abs((*env)->min_z));
		(*env)->coef_y = ((*env)->w_width - 250) / ((*env)->column
			+ (*env)->max_z + abs((*env)->min_z));
		(*env)->coef_z = ((*env)->w_width - 250) / ((*env)->column
			+ (*env)->max_z + abs((*env)->min_z));
	}
	else
	{
		(*env)->coef_x = ((*env)->w_height - 250) / ((*env)->line
			+ (*env)->max_z + abs((*env)->min_z));
		(*env)->coef_y = ((*env)->w_height - 250) / ((*env)->line
			+ (*env)->max_z + abs((*env)->min_z));
		(*env)->coef_z = ((*env)->w_height - 250) / ((*env)->line
			+ (*env)->max_z + abs((*env)->min_z));
	}
	if ((*env)->coef_x <= 1)
	{
		(*env)->coef_x = 1;
		(*env)->coef_y = 1;
		(*env)->coef_z = 1;
	}
}
