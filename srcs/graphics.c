# include <math.h>
#include "fdf.h"

#define X 0
#define Y 1

/*
void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
void	*mlx_new_image(void *mlx_ptr,int width,int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop (void *mlx_ptr);
int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
		       char *string);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param);

int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
int	mlx_do_sync(void *mlx_ptr);
*/

int		ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

int		isometric(int *x, int *y, int z)
{
	double	angle;

	angle = 0.8;//0.523599;
	*x = (double)(*x - *y) * cos(angle);
	*y = (double)(*x + *y) * sin(angle) - z;
	return (0);
}

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

void	color_pick(int *color, int color_final, int range, int mode)
{
	static double	r_step;
	static double	g_step;
	static double	b_step;
	static int		pos;
	static int		color_start;

	if (mode && range)
	{
//		printf("color = %06x, final = %06x, range = %d\n", *color, color_final, range);
		r_step = (double)((((color_final & 0xff0000) - ((*color) & 0xff0000)) >> 16) + 1) / range;
//		printf("r_step = %f\n", r_step);
		g_step = (double)((((color_final & 0x00ff00) - ((*color) & 0x00ff00)) >> 8) + 1) / range;
//		printf("g_step = %f\n", g_step);
		b_step = (double)((color_final & 0x0000ff) - ((*color) & 0x0000ff) + 1) / range;
//		printf("b_step = %f\n", b_step);
		color_start = *color;
		pos = 0;
	}
	else
	{
		if (pos < range)
			*color = color_apply(color_start, (int)(r_step * pos), (int)(g_step * pos), (int)(b_step * pos));
		else
			*color = color_final;
//		printf("color = %06x\n", *color);
	 	pos++;
	}
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
	color_pick(&p0.color, p1.color, d_c[X] > -d_c[Y] ? d_c[X] : -d_c[Y], 1);
	while(1)
	{
		color_pick(&p0.color, p1.color, d_c[X] > -d_c[Y] ? d_c[X] : -d_c[Y], 0);
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, p0.x, p0.y, p0.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break;
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
			(i + 1 != map->width) && draw_line(data, map->map[i][j], map->map[i + 1][j]);
			(j + 1 != map->length) && draw_line(data, map->map[i][j], map->map[i][j + 1]);
			j++;
		}
		i++;
	}
	printf("Drawing finished\n");
}

void	map_process(t_map *map, int	zoom)
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
	printf("Processing finished\n");
}

/*
int     main(void)
{
    t_data      data;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
	draw_field(&data, 10, 10, 30);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}*/
