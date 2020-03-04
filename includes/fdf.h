/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:54:36 by svivienn          #+#    #+#             */
/*   Updated: 2020/03/04 04:41:27 by boris            ###   ########.fr       */
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
# include <math.h>
//# include <mlx.h>
# include "libft.h"

typedef struct	s_map	t_map;
typedef struct	s_point	t_point;

struct			s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
};

struct			s_map
{
	int			length;
	int			width;
	t_point		**map;
};

typedef struct      s_data
{
	 int			color;
     void           *mlx_ptr;
     void           *mlx_win;
}                   t_data;


void	put_tail(t_list **head, t_list **tail, void *content);
void	error();
int		atoi_hex(char *str);

void	init_point(char *str, int x, int y, t_point *point);

void	parser(int fd, t_map *map);

void	draw_field(t_map *map, t_data *data);

void	map_process(t_map *map, int	zoom);
#endif
