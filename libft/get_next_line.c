/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:43:34 by qlouisia          #+#    #+#             */
/*   Updated: 2018/12/05 11:57:40 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static t_list_gnl		*new_list(int fd, t_list_gnl **alst)
{
	t_list_gnl *new;
	t_list_gnl *ptr;

	ptr = *alst;
	while (ptr)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	if (!(new = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = *alst;
	*alst = new;
	return (new);
}

static int				read_buff(int fd, t_list_gnl *current, int *ret)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	*ret = 1;
	ft_bzero(&buff, BUFF_SIZE + 1);
	if ((!current->str))
	{
		*ret = read(fd, &buff, BUFF_SIZE);
		buff[*ret] = '\0';
		current->str = ft_strdup(buff);
	}
	while (!ft_strchr(current->str, '\n') && *ret >= 0)
	{
		*ret = read(fd, buff, BUFF_SIZE);
		buff[*ret] = '\0';
		tmp = current->str;
		if (!(current->str = ft_strjoin(current->str, buff)))
			return (-1);
		free(tmp);
		if (*ret == 0)
			return (0);
	}
	if (*ret < 0)
		return (-1);
	return (1);
}

static size_t			find_eol(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] != '\0') && (str[i] != '\n'))
		i++;
	return (i);
}

int						get_next_line(const int fd, char **line)
{
	int					ret;
	static t_list_gnl	*list = NULL;
	char				*tmp;
	t_list_gnl			*cur;
	size_t				n;

	if ((fd < 0) || (BUFF_SIZE < 1) || !(line) || !(cur = new_list(fd, &list))
				|| ((ret = read_buff(fd, cur, &ret)) < 0))
		return (-1);
	if ((ft_strchr(cur->str, '\n')))
	{
		n = find_eol(cur->str);
		tmp = cur->str;
		*line = ft_strndup(tmp, n);
		cur->str = ft_strdup(tmp + n + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(cur->str);
		ft_strclr(cur->str);
	}
	if (ft_strlen(cur->str) == 0 && ret == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
