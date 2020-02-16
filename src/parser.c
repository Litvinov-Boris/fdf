/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:04:31 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/17 00:20:01 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		valid_point(char *str)
{
	int i;

	if ((i = ft_countwords(str, ',')) == 2)
	{
		while (*str != ',')
			if (!ft_isdigit(*str++))
				error();
		if ((*(str + 1) != '0') || (*(str + 2) != 'x'))
			error();
		str = str + 2;
		i = -1;
		while (++i <= 6 && *(++str) != '\0')
			if ((*str < 'A' || *str > 'F') && !ft_isdigit(*str))
				error();
		if (*str != '\0')
			error();
	}
	else
	{
		while (*str != '\0')
			if (!ft_isdigit(*str++))
				error();
	}
}

static t_point	*get_points(int length, char *str, int y)
{
	t_point	*points;
	char	**zs;
	int		i;

	if (!(points = (t_point*)malloc(sizeof(t_point) * length)))
		error();
	if (!(zs = ft_strsplit(str, ' ')))
		error();
	i = -1;
	while (++i < length)
	{
		valid_point(zs[i]);
		init_point(zs[i], 0, i+1, y, &points[i]);
		free(zs[i]);
	}
	free(zs);
	return (points);
}

static void		pull_map(t_map *map, t_list *head)
{
	t_list	*tail;
	int		get;

	get = 0;
	while (head != NULL)
	{
		map->map[get++] = head->content;
		tail = head;
		head = head->next;
		free(tail);
	}
}

void	parser(int fd, t_map *map)
{
	t_list	*head;
	t_list	*tail;
	char	*str;
	int		get;

	head = NULL;
	tail = NULL;
	while ((get = get_next_line(fd, &str) != 0))
	{
		if (get == -1)
			error();
		if (map->length == 0)
			map->length = ft_countwords(str, ' ');
		if (ft_countwords(str, ' ') != map->length)
			error();
		map->width++;
		put_tail(&head, &tail, get_points(map->length, str, map->width));
		free(str);
	}
	if(!(map->map = (t_point**)malloc(sizeof(t_point*) * map->width)))
		error();
	pull_map(map, head);
}