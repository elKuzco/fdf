/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:58:43 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:45:28 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>
#include <stdlib.h>

/*
**              #######################################
**              ################# Zoom ################
**              #######################################
**
** Get the input and change the value of the scale parameter
** Keycode 69 = '+'
** Keycode 69 = '-'
*/

void	zoom(int keycode, t_lst_env **param)
{
	if (keycode == 69)
	{
		(*param)->coef_x += 1;
		(*param)->coef_y += 1;
		(*param)->coef_z += 1;
	}
	if (keycode == 78)
	{
		if (((*param)->coef_x - 1) > 0)
		{
			(*param)->coef_x -= 1;
			(*param)->coef_y -= 1;
			(*param)->coef_z -= 1;
		}
	}
}

/*
**              #######################################
**              ################# Move ################
**              #######################################
**
** Get the input and change the value of position of the object
** Keycode 124 = 'Arrow  right'
** Keycode 123 = 'Arrow  left'
** Keycode 125 = 'Arrow  down'
** Keycode 126 = 'Arrow  up'
*/

void	move(int keycode, t_lst_env **param)
{
	if (keycode == 124)
		(*param)->x += 10;
	if (keycode == 123)
		(*param)->x -= 10;
	if (keycode == 125)
		(*param)->y += 10;
	if (keycode == 126)
		(*param)->y -= 10;
}

/*
**              #########################################
**              ################# Rotate ################
**              #########################################
**
** Get the input and change the value of differents angles. With a modulo, to
** avoid getting over 360 degree.
** Keycode 12 = 'q'
** Keycode 14 = 'e'
** Keycode 2 = 'd'
** Keycode 0 = 'a'
** Keycode 13 = 'w'
** Keycode 1 = 's'
*/

void	rotate(int keycode, t_lst_env **param)
{
	if (keycode == 12)
		(*param)->rotz = fmod(((*param)->rotz + 1), 360.0);
	if (keycode == 14)
		(*param)->rotz = fmod(((*param)->rotz - 1), 360.0);
	if (keycode == 2)
		(*param)->roty = fmod(((*param)->roty + 1), 360.0);
	if (keycode == 0)
		(*param)->roty = fmod(((*param)->roty - 1), 360.0);
	if (keycode == 13)
		(*param)->rotx = fmod(((*param)->rotx + 1), 360.0);
	if (keycode == 1)
		(*param)->rotx = fmod(((*param)->rotx - 1), 360.0);
}

/*
**              #########################################
**              ############# automatic_view ############
**              #########################################
**
** To automatically set the view in Isometric projection or to reset all
** rotation.
** Keycode 15 = 'q'[reset]
** Keycode 7 = 'x' [Isometric view]
*/

void	automatic_view(int keycode, t_lst_env **param)
{
	if (keycode == 15)
	{
		(*param)->rotx = 0;
		(*param)->roty = 0;
		(*param)->rotz = 0;
	}
	if (keycode == 7)
	{
		(*param)->rotz = 45;
		(*param)->rotx = 35.264;
		(*param)->roty = 0;
	}
}

/*
**              ########################################
**              ############## quit_program ############
**              ########################################
**
** Quit properly the programm, and free all memory.
*/

int		quit_program(t_lst_env **param)
{
	free_map(param);
	exit(0);
}
