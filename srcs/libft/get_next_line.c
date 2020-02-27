/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:56:34 by svivienn          #+#    #+#             */
/*   Updated: 2019/09/06 18:30:12 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*take_fd(const int fd, t_list **list)
{
	t_list *work;

	work = *list;
	while (work)
	{
		if (work->content_size == (size_t)fd)
			return (work);
		work = work->next;
	}
	if (!(work = ft_lstnew("\0", 1)))
		return (NULL);
	work->content_size = fd;
	ft_lstadd(list, work);
	return (work);
}

static int		read_line(t_list *elem)
{
	int		lread;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((lread = read(elem->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[lread] = '\0';
		tmp = elem->content;
		if (!(elem->content = ft_strjoin(elem->content, buf)))
			return (-1);
		ft_memdel((void**)&tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (lread);
}

static void		memclear(t_list **list, t_list *elem)
{
	if (*list == elem)
	{
		*list = (*list)->next;
	}
	else
	{
		while ((*list)->next != elem)
			(*list) = (*list)->next;
		(*list)->next = (*list)->next->next;
	}
	ft_memdel((void**)&elem->content);
	ft_memdel((void**)&elem);
}

static int		get_line(char **line, t_list *elem)
{
	char *tmp;
	char *tmp2;

	if ((tmp = ft_strchr(elem->content, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strdup(elem->content)))
		{
			*tmp = '\n';
			return (-1);
		}
	}
	else
	{
		if (!(*line = ft_strdup(elem->content)))
			return (-1);
	}
	if (!tmp)
		tmp = ft_strchr(elem->content, '\0') - 1;
	tmp2 = elem->content;
	if (!(elem->content = ft_strdup(tmp + 1)))
		return (-1);
	ft_memdel((void**)&tmp2);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_list			*elem;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 ||
						!(elem = take_fd(fd, &fd_list)))
		return (-1);
	if (*(char*)(elem->content) == '\0' || !ft_strchr(elem->content, '\n'))
		if (read_line(elem) == -1)
			return (-1);
	if (*(char*)(elem->content) == '\0')
	{
		memclear(&fd_list, elem);
		return (0);
	}
	return (get_line(line, elem));
}
