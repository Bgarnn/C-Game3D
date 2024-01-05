#include "../include/cub_main.h"

static void	calculate_step_and_side_dist_x(t_data *data)
{
	if (data->var.ray_dir_x < 0)
	{
		data->var.step_x = -1;
		data->var.side_dist_x = (data->var.position_x \
			- data->var.map_x) * data->var.delta_dist_x;
	}
	else
	{
		data->var.step_x = 1;
		data->var.side_dist_x = (data->var.map_x + 1.0 \
			- data->var.position_x) * data->var.delta_dist_x;
	}
}

static void	calculate_step_and_side_dist_y(t_data *data)
{
	if (data->var.ray_dir_y < 0)
	{
		data->var.step_y = -1;
		data->var.side_dist_y = (data->var.position_y \
			- data->var.map_y) * data->var.delta_dist_y;
	}
	else
	{
		data->var.step_y = 1;
		data->var.side_dist_y = (data->var.map_y + 1.0 \
			- data->var.position_y) * data->var.delta_dist_y;
	}
}

static void	set_texture(t_data *data)
{
	if (data->var.side == 0)
	{
		if (data->var.map_x > data->var.position_x)
			data->var.texture_number = 1;
		else
			data->var.texture_number = 3;
	}
	else
	{
		if (data->var.map_y > data->var.position_y)
			data->var.texture_number = 2;
		else
			data->var.texture_number = 0;
	}
}

static void	dda(t_data *data)
{
	while (data->var.hit == 0)
	{
		if (data->var.side_dist_x < data->var.side_dist_y)
		{
			data->var.side_dist_x += data->var.delta_dist_x;
			data->var.map_x += data->var.step_x;
			data->var.side = 0;
		}
		else
		{
			data->var.side_dist_y += data->var.delta_dist_y;
			data->var.map_y += data->var.step_y;
			data->var.side = 1;
		}
		if (data->map[data->var.map_y][data->var.map_x] == '1')
		{
			data->var.hit = 1;
			set_texture(data);
		}
	}
}

void	raycast_2(t_data *data)
{
	calculate_step_and_side_dist_x(data);
	calculate_step_and_side_dist_y(data);
	dda(data);
}
