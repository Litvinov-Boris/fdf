/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:54:36 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/15 03:21:40 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"

typedef struct	s_map	t_map;
typedef struct	s_point	t_point;

struct			s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
};

struct			s_map
{
	int			length;
	int			width;
	t_point		**map;
};


void	put_tail(t_list **head, t_list **tail, void *content);
void	error();

void	init_point(char *str, int color,int x, int y, t_point *point);

void	parser(int fd, t_map *map);
#endif