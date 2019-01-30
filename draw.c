/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:08:57 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/26 14:48:13 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft/libft.h"

/*                ####################################
*                 ############## Print Ui#############
*                 ####################################
*                 Print all the UI, X,Y,Z and instructions 
*/ 


void print_ui(t_lst_env **env)
{
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 30, 10, 255255255, "Z :" );
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 60, 10, 255255255, ft_itoa((*env)->rotz));
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 30, 30, 255255255, "X :" );
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 60, 30, 255255255, ft_itoa((*env)->rotx));
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 30, 50, 255255255, "Y :" );
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 60, 50, 255255255, ft_itoa((*env)->roty));
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 30, 70, 255255255, "Isometric [Press X]" );
	mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr, 30, 90, 255255255, "Reset [Press R]" );
	if ((*env)->rotz == 45  && (*env)->rotx > 35 && (*env)->rotx < 36 && (*env)->roty == 0)
		mlx_string_put ( (*env)->mlx_ptr, (*env)->win_ptr,
		 WINDOW_WIDTH /2 - 80, 20, 255255255, " Isomectric projection" );
	
}

/*                    ############################################ 
*                     ############### Refresh_image ##############
*                     ############################################
* 
* Change to black all pixel (store in data) then refresh position of all points.
*           clean the window and finaly print the image in the window 
*/

void refresh_image(t_lst_env **env)
{
	int i;
	int n;
	
	n = WINDOW_WIDTH * WINDOW_HEIGHT;
	i = 0;
	while (i < n)
	{
		(*env)->data[i] = 0;
		i++;
	}
	draw_grid(env);
	mlx_clear_window((*env)->mlx_ptr, (*env)->win_ptr);
	mlx_put_image_to_window((*env)->mlx_ptr, (*env)->win_ptr, (*env)->img_ptr, 0, 0);
	print_ui(env);
}


/*                  ######################################## 
*                   ############### scale_lst ##############
*                   ########################################
*
* Apply to all point of the list, transformation and set them to 
* their current coordonates.  
*/

void scale_lst(t_lst_env **env)
{
	t_lst_coord *ptr;
	ptr = (*env)->first;
	int i;
	
	i = 0;
	
	while (ptr)
	{
	//	printf("Previous value[%i] of x = %i | y = %i | c_x: %f | c_y = %f | z = %i \n",i,ptr->x, ptr->y,ptr->c_x,ptr->c_y, ptr->z);
		//parallele(ptr, env);
		rotation_axis_z(ptr, (*env)->rotz, (*env)->column,(*env)->line);
		scale_up(ptr, env);
		rotation_axis_y(ptr, (*env)->roty, (*env)->column,(*env)->line);
		rotation_axis_x(ptr, (*env)->rotx, (*env)->column,(*env)->line);
		

	//	printf("new Value after Rotation:[%i]\nc_x[%i]: %f | [%i]c_y = %f | z[%i] = %f Link to: \n",ptr->y,ptr->x,ptr->c_x,ptr->y,ptr->c_y,ptr->z, ptr->c_z);

		//scale_up(ptr, env);
		translation(ptr, env);
		
//		printf("new Value after scale & trans:[%i][%i] \nc_x: %f | c_y = %f | z = %f Link to: \n",ptr->x,ptr->y,ptr->c_x,ptr->c_y, ptr->c_z);
		//ptr->c_x = ptr->c_x + (*env)->center_x + (*env)->x;
		//ptr->c_y = ptr->c_y + (*env)->center_y + (*env)->y;
		
		//ptr->c_x = ptr->c_x * (*env)->coef_x;
		//ptr->c_y = ptr->c_y * (*env)->coef_y;
		
		//ptr->c_x = ptr->x * (*env)->coef_x + (*env)->center_x + (*env)->x;
		//ptr->c_y = ptr->y * (*env)->coef_y  + (*env)->center_y + (*env)->y;
	//	rotation_axis_z(ptr, (*env)->rot);
	//	ptr->c_x = (ptr->c_x + 0.1 * ptr->c_z) * (*env)->coef_x + (*env)->center_x + (*env)->x;
	//	ptr->c_y = (ptr->c_y + 0.1/2 * ptr->c_z) * (*env)->coef_y  + (*env)->center_y + (*env)->y; 
	//	printf("new Value after scale \nc_x: %f | c_y = %f | z = %d Link to: \n",ptr->c_x,ptr->c_y, ptr->z);
		i++;
	//	printf("\n#########################################\n");
		ptr = ptr->next;
	}
}

/*             ######################################## 
*              ############### draw_grid ##############
*              ########################################
*
* Draw the map using coordonate of the list, linking point to the next 
* and the one below.
*/

int draw_grid(t_lst_env **env)
{
	t_lst_coord *ptr;

	scale_lst(env);
	ptr = (*env)->first;
	while (ptr)
	{
		if (ptr->next && (ptr->y == ptr->next->y))
		{
		/*	if (ptr->x== 0 && ptr->y == 1)
				printf("call Drawline Hor for linking [%i][%i] x[%f] y[%f] and [%i][%i][%f][%f]\n",ptr->x,ptr->y,ptr->c_x,ptr->c_y,ptr->next->x,ptr->next->y,ptr->next->c_x, ptr->next->c_y);
			*/draw_line(ptr, ptr->next, env);
		}
		if (ptr->upon)
		{
			/*if (ptr->x== 0 && ptr->y == 1)
				printf("call Drawline Vert for linking [%i][%i][%f][%f] and x[%i]y[%i][%f][%f]\n",ptr->x,ptr->y,ptr->c_x,ptr->c_y,ptr->upon->x,ptr->upon->y,ptr->upon->c_x,ptr->upon->c_y);
			*/draw_line(ptr, ptr->upon, env);
		}
		ptr = ptr->next;
	}
/*	while (j < (*env)->line)
	{
		while (i < (*env)->column)
		{
			if (i < (*env)->column - 1)
				draw_line(coef_x * i + center_x, coef_y * j + center_y , coef_x * (i+1) + center_x, coef_y * j + center_y, display);
			if (j < (*env)->line - 1)
				draw_line(coef_x * i + center_x, coef_y * j + center_y , coef_x * i + center_x, coef_y * (j+1) + center_y, display);
			i++;
		}
		i = 0;
		j++;
	}*/
	return (0);
}