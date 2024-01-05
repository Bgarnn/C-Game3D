#include "../include/cub_main.h"

static void	calculate_ray_position_and_dir(t_data *data, int x)
{
	data->var.camera_x = 2 * x / (double) data->res_x - 1;
	data->var.ray_dir_x = data->var.dir_x + \
							data->var.plane_x * data->var.camera_x;
	data->var.ray_dir_y = data->var.dir_y + \
							data->var.plane_y * data->var.camera_x;
}

static void	set_box_position(t_data *data)
{
	data->var.map_x = (int) data->var.position_x;
	data->var.map_y = (int) data->var.position_y;
	data->var.hit = 0;
}

static void	calculate_delta_dist(t_data *data)
{
	if (data->var.ray_dir_x == 0)
		data->var.delta_dist_x = 1e30;
	else
		data->var.delta_dist_x = fabs(1 / data->var.ray_dir_x);
	if (data->var.ray_dir_y == 0)
		data->var.delta_dist_y = 1e30;
	else
		data->var.delta_dist_y = fabs(1 / data->var.ray_dir_y);
}

static void	draw_vertical_texture_stripe(t_data *data, int x)
{
	double	step;
	double	texture_position;
	int		y;

	step = 1.0 * TEXTURE_HEIGHT / data->var.line_height;
	texture_position = (data->var.draw_start - data->res_y / 2 \
		+ data->var.line_height / 2) * step;
	y = data->var.draw_start;
	while (y < data->var.draw_end)
	{
		data->var.texture_y = (int) texture_position & (TEXTURE_HEIGHT - 1);
		texture_position += step;
		data->var.color = data->txt_addr_arr2d[data->var.texture_number][\
			TEXTURE_HEIGHT * data->var.texture_y + data->var.texture_x];
		if (data->var.side == 1)
			data->var.color = (data->var.color >> 1) & 8355711;
		mlx_place_pixel(data, x, y, data->var.color);
		y++;
	}
}

void	raycast(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->res_x)
	{
		calculate_ray_position_and_dir(data, x);
		set_box_position(data);
		calculate_delta_dist(data);
		raycast_2(data);
		raycast_3(data);
		draw_vertical_texture_stripe(data, x);
		x++;
	}
}
