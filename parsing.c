/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:48:09 by qlouisia          #+#    #+#             */
/*   Updated: 2019/01/25 12:47:52 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include "fdf.h"

void link_verticaly(t_lst_env **env)
{
	t_lst_coord *ptr;
	t_lst_coord *ptr_nextline;
	int i;
	
	ptr = (*env)->first;
	ptr_nextline = (*env)->first;
	i = 0;
	while((i < (*env)->column ) && ptr_nextline)
	{
			set_color_gradient(ptr_nextline,env);
			ptr_nextline = ptr_nextline->next;
			i++;
			
	}
	
	//printf("i =%i ptr_nextline = x[%i] y[%i]\n ",i,ptr_nextline->x, ptr_nextline->y);
	while(ptr_nextline)
	{
			ptr->upon = ptr_nextline;
			set_color_gradient(ptr_nextline,env);
	//		printf("Value of link 1 x: %i | y = %i | z = %i Link to: \n",ptr->x,ptr->y, ptr->z);
	//		printf("Value of link below: %i | y = %i | z = %i \n",ptr_nextline->x,ptr_nextline->y, ptr_nextline->z);

			ptr_nextline = ptr_nextline->next;
			ptr = ptr->next;
	}
	//printf("########################\n");
	//printf("Value of link 1 x: %i | y = %i | z = %i Link to: \n",(*env)->first->next->x,(*env)->first->next->y, (*env)->first->next->z);
	//printf("Value of link below: %i | y = %i | z = %i \n",(*env)->first->next->upon->x,(*env)->first->next->upon->y, (*env)->first->next->upon->z);
	
}
/*
** Need to create a function that add result from convert_nbr and malloc
**to the remain
*/

int	resize_map(t_lst_env **env, int *tab)
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
		
		if((*env)->lst->z > (*env)->max_z)
			(*env)->max_z = (*env)->lst->z;
		else if((*env)->lst->z < (*env)->min_z)
			(*env)->min_z = (*env)->lst->z;	
		i++;
	}
	(*env)->line++;
	return (1);
}


/*
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
	{
		while (i < size)
		{
			free(str[i]);
			i++;
		}
		free(str);
		return (0);
	}
	while (i < (*env)->column)
	{

		tab[i] = ft_atoi(str[i]);
		if (i == 0)
			printf("str[0] == %s | tab[0] == %i \n",str[0],tab[0]);
		free(str[i]);
		i++;
	}
	free(str);
	return (tab);
}

/*
** Check string and return 1 if it's only number
*/

int	check_string(char *str)
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
** Function get line from the file and convert it into int tab
*/

int		create_matrice(int fd, t_lst_env **env)
{
	char *line;
	char **tmp_tab;
	int i;
	int *test;
	t_bool first_read;

	line = NULL;
	first_read = true;
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (!check_string(line))
		{
			free(line);
			return (0);
		}
		if (first_read)
			(*env)->column = ft_countword(line, ' ');
		first_read = false;
		tmp_tab = ft_strsplit(line, ' ');
		if (!(test = convert_nbr(tmp_tab, env)) || !(resize_map(env, test)))
		{
			if (test)
				free(test);
			free(line);
			return (0);
		}
		free(line);
		free(test);
	}
	printf("min z = %i | max z = %i \n",(*env)->min_z, (*env)->max_z);
	link_verticaly(env);
	free(line);
	return (1);
}
