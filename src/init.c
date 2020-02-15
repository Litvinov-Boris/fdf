/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 02:48:48 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/15 02:50:53 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_point(char *str, int color,int x, int y, t_point *point)
{
	point->color = color;
	point->x = x;
	point->y = y;
	point->z = atoi(str);
}