/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:55:55 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/24 14:10:30 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include "mlx.h"
#include "libft/libft.h"

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
	(*env)->min_z =0;
	(*env)->max_z =0;
	(*env)->mlx_ptr = mlx_init();
	(*env)->win_ptr = mlx_new_window((*env)->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
	printf("create image \n");
	(*env)->img_ptr = mlx_new_image((*env)->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	printf("pointer image create \n");
	(*env)->data = (int *)mlx_get_data_addr((*env)->img_ptr, &(*env)->bpp, &(*env)->size_l,
		&(*env)->endian);
	printf(" end create image \n");
	return (1);
}

int	free_map(t_lst_env **env)
{
	t_lst_coord *tmp;
	
	while ((*env)->first)
	{
		tmp = (*env)->first->next;
		//(*env)->first->upon = NULL;
		free((*env)->first);
		(*env)->first = tmp;
	}
	tmp = NULL;
	
	ft_memdel((*env)->win_ptr);
//	ft_memdel((*env)->img_ptr);
	//ft_memdel((void**)&(*env)->data);
	ft_memdel((*env)->mlx_ptr);
	
	mlx_destroy_image ((*env)->mlx_ptr,(*env)->img_ptr);
	mlx_destroy_window ((*env)->mlx_ptr, (*env)->win_ptr);
	
	(*env)->win_ptr = NULL;
	(*env)->img_ptr = NULL;;
	(*env)->data = NULL;
	(*env)->mlx_ptr = NULL;
	free(*env);
	return (0);
}
