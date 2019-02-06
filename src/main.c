/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:28:46 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:47:28 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "mlx.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <math.h>

/*
**              ##########################################
**              ################ get_input ###############
**              ##########################################
**
** Get the input and dispatch all the instructions between several functions
*/

int		get_input(int keycode, t_lst_env **param)
{
	if (keycode == 69 || keycode == 78)
		zoom(keycode, param);
	if (keycode >= 123 && keycode <= 126)
		move(keycode, param);
	if ((keycode >= 12 && keycode <= 14) || (keycode >= 0 && keycode <= 2))
		rotate(keycode, param);
	if (keycode == 15 || keycode == 7)
		automatic_view(keycode, param);
	if (keycode == 8)
		(*param)->color_mode = !(*param)->color_mode;
	if (keycode == 53)
		quit_program(param);
	refresh_image(param);
	return (0);
}

/*
**              ##########################################
**              ############### expose_hook ##############
**              ##########################################
**
** If no input is receive, refresh the display
*/

int		expose_hook(t_lst_env **param)
{
	refresh_image(param);
	return (1);
}

/*
**              ##########################################
**              ############# initiate_graphic############
**              ##########################################
**
** Initiate the display, and use some hooks to handle user's inputs
*/

void	initiate_graphic(t_lst_env **env)
{
	if (!draw_grid(env))
		quit_program(env);
	mlx_hook((*env)->win_ptr, 2, 3, get_input, env);
	mlx_hook((*env)->win_ptr, 17, 1L << 17, quit_program, env);
	mlx_expose_hook((*env)->win_ptr, expose_hook, env);
	mlx_loop((*env)->mlx_ptr);
}

int		main(int ac, char **av)
{
	int			fd;
	t_lst_env	*env;

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
		if (!(create_env(&env)) || !create_matrice(fd, &env)
			|| !create_window(&env, av[1]))
		{
			ft_putendl("error");
			return (free_map(&env));
		}
	}
	initiate_graphic(&env);
}
