/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:28:46 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/26 14:03:00 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <fcntl.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>

int get_input(int keycode, t_lst_env *param)
{

	if (keycode == 69)
	{
		param->coef_x += 1;
		param->coef_y += 1;
		param->coef_z += 1;
	//	param->center_x = (WINDOW_WIDTH / 2 - ((param->column / 2) * param->coef_x))/6;
	//	param->center_y = (WINDOW_HEIGHT / 2 - ((param->line / 2) * param->coef_y))/6;
	/*	
		param->center_x -= param->coef_x* param->column/2 ;// (WINDOW_WIDTH / 2 - (param->column / 2) * param->coef_x) + param->x;
		param->center_y -= param->coef_y * param->line/2;// (WINDOW_HEIGHT / 2 - (param->line / 2) * param->coef_y) + param->y;
	*/
	}	
	if (keycode == 78)
	{
		printf("Coef = %i\n",param->coef_x);
		if ((param->coef_x - 1) > 0)
		{
			printf("Reducing\n");
			param->coef_x -= 1;
			param->coef_y -= 1;
			param->coef_z -= 1;
	//		param->center_x = (WINDOW_WIDTH / 2 - ((param->column / 2) * param->coef_x))/6;
	//		param->center_y = (WINDOW_HEIGHT / 2 - ((param->line / 2) * param->coef_y))/6;
	/*
			param->center_x += param->coef_x* param->column/2; //(WINDOW_WIDTH / 2 - (param->column / 2) * param->coef_x) + param->x;
			param->center_y += param->coef_y * param->line/2;// (WINDOW_HEIGHT / 2 - (param->line / 2) * param->coef_y) + param->y;
	*/
		}
	}
	if (keycode == 124)
		param->x += 10 ;
	if (keycode == 123)
		param->x -= 10 ;
	if (keycode == 125)
		param->y += 10 ;
	if (keycode == 126)
		param->y -= 10 ;
	if (keycode == 12)
		param->rotz = fmod((param->rotz + 1), 360.0); //M_PI/16// +2
	if (keycode == 14)
		param->rotz = fmod((param->rotz - 1), 360.0); //M_PI/16// +2	
	if (keycode == 2)
		param->roty = fmod((param->roty + 1), 360.0); //M_PI/16// +2
	if (keycode == 0)
		param->roty = fmod((param->roty - 1), 360.0); //M_PI/16// +2	
	if (keycode == 13)
		param->rotx = fmod((param->rotx + 1), 360.0); //M_PI/16// +2
	if (keycode == 1)
		param->rotx = fmod((param->rotx - 1), 360.0); //M_PI/16// +2		
	if (keycode == 15)
	{
		param->rotx = 0; //M_PI/16// +2	
		param->roty = 0;
		param->rotz = 0;
	}
	if (keycode == 7)
	{
		//vue isometric
		param->rotz = 45;
		param->rotx = 35.264;
		param->roty = 0;
		
	}
	if (keycode == 6)
	{
		param->coef_x += 1;
		param->coef_y += 1;
		param->coef_z -= 1;
	}
	
	if (keycode == 53)
	{
		free_map(&param);
		exit(0);
	}
	refresh_image(&param);
	printf("\nkeycode = %i\n",keycode);
	printf("rotation Z : %f | rotation Y : %f | rotation X : %f \n",param->rotz,param->roty, param->rotx);
	return (0);
}

int		expose_hook( t_lst_env *param)
{
	refresh_image(&param);
/*
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img_ptr, 0, 0);
		*/
	return (1);
}

int	main(int ac, char **av)
{
	int fd;
	t_lst_env *env;

	if (ac != 2)
	{
		ft_putendl("usage: ./FdF Valid_Map_File");
		return (0);
	}
	else if ((fd = open(av[1], O_RDONLY)) == -1)
	{
			ft_putendl("error");
			return (0); 
	}
	else
	{
		if (!(create_env(&env)) || !create_matrice(fd, &env))
		{
			ft_putendl("error");
			free_map(&env);
			return (0);
		}
	}
	//printf("Value of env_x : %i | y = %i | z = %i \n",env->first->x,env->first->y, env->first->z);
	//free_map(&env);
	

	 
	//while(1);


	draw_grid(&env);
	//free_map(&env);
	mlx_hook(env->win_ptr, 2, 3, get_input, env);
	mlx_expose_hook(env->win_ptr, expose_hook, env);
	mlx_loop(env->mlx_ptr);	
}
