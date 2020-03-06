/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 02:48:48 by svivienn          #+#    #+#             */
/*   Updated: 2020/03/04 04:59:43 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_point(char *str, int x, int y, t_point *point)
{
	char **work;

	if (!(work = ft_strsplit(str, ',')))
		error();
	if (work[1] != NULL)
		point->color = atoi_hex(work[1]);
	else
		point->color = 0xffffff;
	point->x = x;
	point->y = y;
	point->z = atoi(work[0]);
	free(work[0]);
	if (work[1] != NULL)
		free(work[1]);
	free(work);
}
