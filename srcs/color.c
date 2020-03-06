/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:13:00 by hshawand          #+#    #+#             */
/*   Updated: 2020/03/06 15:13:25 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_apply(int color_base, int r_diff, int g_diff, int b_diff)
{
	int		r_new;
	int		g_new;
	int		b_new;

	r_new = ((color_base & 0xff0000) >> 16) + r_diff;
	g_new = ((color_base & 0x00ff00) >> 8) + g_diff;
	b_new = (color_base & 0xff) + b_diff;
	return (((r_new & 0xff) << 16) + ((g_new & 0xff) << 8) + (b_new & 0xff));
}

void	col_pick(int *color, int color_final, int range, int mode)
{
	static double	r_step;
	static double	g_step;
	static double	b_step;
	static int		pos;
	static int		color_start;

	if (mode && range)
	{
		r_step = (double)((((color_final & 0xff0000) -
			((*color) & 0xff0000)) >> 16) + 1) / range;
		g_step = (double)((((color_final & 0x00ff00) -
			((*color) & 0x00ff00)) >> 8) + 1) / range;
		b_step = (double)((color_final & 0x0000ff) -
			((*color) & 0x0000ff) + 1) / range;
		color_start = *color;
		pos = 0;
	}
	else
	{
		pos < range ? *color = color_apply(color_start, (int)(r_step * pos),
			(int)(g_step * pos), (int)(b_step * pos)) : (*color = color_final);
		pos++;
	}
}
