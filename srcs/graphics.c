/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:10:13 by hshawand          #+#    #+#             */
/*   Updated: 2020/03/06 16:07:52 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#define X 0
#define Y 1

int		ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

int		isometric(int *x, int *y, int z)
{
	double	angle;

	angle = 0.8;
	*x = (double)(*x - *y) * cos(angle);
	*y = (double)(*x + *y) * sin(angle) - z;
	return (0);
}

int		draw_line(t_data *data, t_point p0, t_point p1)
{
	int		d_c[2];
	int		err[2];
	int		s_c[2];

	d_c[X] = ft_abs(p1.x - p0.x);
	d_c[Y] = -ft_abs(p1.y - p0.y);
	err[0] = d_c[X] + d_c[Y];
	s_c[X] = p0.x < p1.x ? 1 : -1;
	s_c[Y] = p0.y < p1.y ? 1 : -1;
	col_pick(&p0.color, p1.color, d_c[X] > -d_c[Y] ? d_c[X] : -d_c[Y], 1);
	while (1)
	{
		col_pick(&p0.color, p1.color, d_c[X] > -d_c[Y] ? d_c[X] : -d_c[Y], 0);
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, p0.x, p0.y, p0.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= d_c[Y] && ((err[0] += d_c[Y]) || 1))
			p0.x += s_c[X];
		if (err[1] <= d_c[X] && ((err[0] += d_c[X]) || 1))
			p0.y += s_c[Y];
	}
	return (0);
}

void	draw_field(t_map *map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->length)
		{
			(i + 1 != map->width) && draw_line(data, map->map[i][j],
				map->map[i + 1][j]);
			(j + 1 != map->length) && draw_line(data, map->map[i][j],
				map->map[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	map_process(t_map *map, int zoom)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->length)
		{
			(map->map[i][j]).x *= zoom;
			(map->map[i][j]).y *= zoom;
			(map->map[i][j]).z *= zoom;
			map->projection_type &&
				isometric(&((map->map[i][j]).x),
					&((map->map[i][j]).y), (map->map[i][j]).z);
			j++;
		}
		i++;
	}
}
