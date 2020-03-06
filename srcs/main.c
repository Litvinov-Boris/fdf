/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:04:25 by svivienn          #+#    #+#             */
/*   Updated: 2020/03/06 16:09:28 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if defined(__linux__)
# define K_ESC 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
#elif defined(__APPLE__)
# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124
#endif

int		update(t_data *data, t_map *map)
{
	static t_data	*saved_data;
	static t_map	*saved_map;

	if (data && map)
	{
		saved_data = data;
		saved_map = map;
	}
	else
		mlx_clear_window(saved_data->mlx_ptr, saved_data->mlx_win);
	draw_field(saved_map, saved_data);
	return (0);
}

void	shift(int shift_x, int shift_y, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->length)
		{
			map->map[i][j].x += shift_x;
			map->map[i][j].y += shift_y;
			j++;
		}
		i++;
	}
	update(0, 0);
}

int		key_proc(int key, t_map *map)
{
	if (key == K_UP || key == K_DOWN)
		key == K_UP ? shift(0, -30, map) : shift(0, 30, map);
	if (key == K_LEFT || key == K_RIGHT)
		key == K_LEFT ? shift(-30, 0, map) : shift(30, 0, map);
	if (key == K_ESC)
		exit(0);
	return (0);
}

int		pick_projection(void)
{
	int	type;

	write(1, "Pick projection type:\n 0 - Parallel\n 1 - Isometric\n", 51);
	read(0, &type, 1);
	type -= 48;
	if (type != 0 && type != 1)
		error();
	return (type);
}

int		main(int argc, char **argv)\
{
	int		fd;
	t_map	*map;
	t_data	*data;

	if (argc != 2)
		error();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error();
	map = (t_map *)malloc(sizeof(t_map));
	data = (t_data *)malloc(sizeof(t_data));
	ft_bzero(map, sizeof(t_map));
	parser(fd, map);
	map->projection_type = pick_projection();
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data->mlx_win =
		mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF")) == NULL)
		return (EXIT_FAILURE);
	map_process(map, 28);
	update(data, map);
	close(fd);
	mlx_key_hook(data->mlx_win, key_proc, map);
	mlx_loop(data->mlx_ptr);
	return (0);
}
