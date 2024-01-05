#include "../include/cub_main.h"

static void	calculate_dist_perspt(t_data *data)
{
	if (data->var.side == 0)
		data->var.perspt_wall_dist = \
			data->var.side_dist_x - data->var.delta_dist_x;
	else
		data->var.perspt_wall_dist = \
			data->var.side_dist_y - data->var.delta_dist_y;
}

static void	calculate_vertical_line_height(t_data *data)
{
	data->var.line_height = \
		(int)(data->res_y / data->var.perspt_wall_dist);
}

static void	calculate_draw_start_and_draw_end(t_data *data)
{
	data->var.draw_start = (data->res_y / 2) - (data->var.line_height / 2);
	if (data->var.draw_start < 0)
		data->var.draw_start = 0;
	data->var.draw_end = (data->res_y / 2) + (data->var.line_height / 2);
	if (data->var.draw_end >= data->res_y)
		data->var.draw_end = data->res_y - 1;
}

static void	calculate_texture_x(t_data *data)
{
	if (data->var.side == 0)
		data->var.wall_x = data->var.position_y + \
			data->var.perspt_wall_dist * data->var.ray_dir_y;
	else
		data->var.wall_x = data->var.position_x + \
			data->var.perspt_wall_dist * data->var.ray_dir_x;
	data->var.wall_x -= floor(data->var.wall_x);
	data->var.texture_x = (int)(data->var.wall_x * (double)TEXTURE_WIDTH);
	if (data->var.side == 0 && data->var.ray_dir_x > 0)
		data->var.texture_x = TEXTURE_WIDTH - data->var.texture_x - 1;
	if (data->var.side == 1 && data->var.ray_dir_y < 0)
		data->var.texture_x = TEXTURE_WIDTH - data->var.texture_x - 1;
}

void	raycast_3(t_data *data)
{
	calculate_dist_perspt(data);
	calculate_vertical_line_height(data);
	calculate_draw_start_and_draw_end(data);
	calculate_texture_x(data);
}
