/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:48:09 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:46:05 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "../include/fdf.h"

void	link_verticaly(t_lst_env **env)
{
	t_lst_coord *ptr;
	t_lst_coord *ptr_nextline;
	int			i;

	ptr = (*env)->first;
	ptr_nextline = (*env)->first;
	i = 0;
	while ((i < (*env)->column) && ptr_nextline)
	{
		set_color_gradient(ptr_nextline, env);
		ptr_nextline = ptr_nextline->next;
		i++;
	}
	while (ptr_nextline)
	{
		ptr->upon = ptr_nextline;
		set_color_gradient(ptr_nextline, env);
		ptr_nextline = ptr_nextline->next;
		ptr = ptr->next;
	}
}

/*
**                 #########################################
**                 ############### resize_map ##############
**                 #########################################
**
** Need to create a function that add result from convert_nbr and malloc
**to the remain
*/

int		resize_map(t_lst_env **env, int *tab)
{
	int i;

	i = 0;
	while (i < (*env)->column)
	{
		create_lst(&((*env)->first), &((*env)->lst));
		(*env)->lst->x = i;
		(*env)->lst->y = (*env)->line;
		(*env)->lst->z = tab[i];
		(*env)->lst->c_y = (*env)->line;
		(*env)->lst->c_x = i;
		(*env)->lst->c_z = tab[i];
		if ((*env)->lst->z > (*env)->max_z)
			(*env)->max_z = (*env)->lst->z;
		else if ((*env)->lst->z < (*env)->min_z)
			(*env)->min_z = (*env)->lst->z;
		i++;
	}
	(*env)->line++;
	return (1);
}

/*
**                 #########################################
**                 ############### convert_nbr #############
**                 #########################################
**
** Get the result from ft_strsplit and convert into an int tab
*/

int		*convert_nbr(char **str, t_lst_env **env)
{
	int *tab;
	int size;
	int i;

	size = 0;
	i = 0;
	while (str[size])
		size++;
	if (size != (*env)->column || !(tab = (int *)malloc(sizeof(int) * size)))
		return (free_tab(str, size));
	while (i < (*env)->column)
	{
		tab[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (tab);
}

/*
**                 #########################################
**                 ############## check_string #############
**                 #########################################
**
** Check string and return 1 if it's only number
*/

int		check_string(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ' '))
		{
			if (!((str[i] == '-' || str[i] == '+') &&
			str[i + 1] && ft_isdigit(str[i + 1])))
				return (0);
		}
		i++;
	}
	return (i);
}

/*
**                 #########################################
**                 ############# create_matrice ############
**                 #########################################
**
** Function get line from the file and convert it into int tab
*/

int		create_matrice(int fd, t_lst_env **env)
{
	char	*line;
	char	**tmp_tab;
	int		*test;
	t_bool	first_read;

	line = NULL;
	test = NULL;
	first_read = true;
	while (get_next_line(fd, &line) != 0)
	{
		if (!check_string(line))
			return (free_parsing(test, line));
		if (first_read)
			(*env)->column = ft_countword(line, ' ');
		first_read = false;
		tmp_tab = ft_strsplit(line, ' ');
		if (!(test = convert_nbr(tmp_tab, env)) || !(resize_map(env, test)))
			return (free_parsing(test, line));
		free_parsing(test, line);
	}
	if (first_read)
		return (free_parsing(test, line));
	link_verticaly(env);
	free(line);
	return (1);
}
