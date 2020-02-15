/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:04:25 by svivienn          #+#    #+#             */
/*   Updated: 2020/02/15 03:28:40 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(/*int argc, char **argv*/ void)\
{
	int		fd;
	t_map	*map;
	int k;

	fd = open("./42.fdf", O_RDONLY);
	map = (t_map*)malloc(sizeof(t_map));
	ft_bzero(map, sizeof(t_map));
	parser(fd, map);
	for(int i = 0; i < map->width; i++)
	{
		for (int j = 0; j < map->length; j++)
		{
			k = (int)map->map[i][j].z;
			printf("%i\t", k);
		}
		printf("\n");
	}
	close(fd);
	return (0);
}