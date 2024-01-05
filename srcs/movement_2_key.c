#include "../include/cub_main.h"

void	player_rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->var.dir_x;
	data->var.dir_x = data->var.dir_x * cos(data->var.rotate_speed) \
		- data->var.dir_y * sin(data->var.rotate_speed);
	data->var.dir_y = old_dir_x * sin(data->var.rotate_speed) \
		+ data->var.dir_y * cos(data->var.rotate_speed);
	old_plane_x = data->var.plane_x;
	data->var.plane_x = data->var.plane_x * cos(data->var.rotate_speed) \
		- data->var.plane_y * sin(data->var.rotate_speed);
	data->var.plane_y = old_plane_x * sin(data->var.rotate_speed) \
		+ data->var.plane_y * cos(data->var.rotate_speed);
}

void	player_rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->var.dir_x;
	data->var.dir_x = data->var.dir_x * cos(-data->var.rotate_speed) \
		- data->var.dir_y * sin(-data->var.rotate_speed);
	data->var.dir_y = old_dir_x * sin(-data->var.rotate_speed) \
		+ data->var.dir_y * cos(-data->var.rotate_speed);
	old_plane_x = data->var.plane_x;
	data->var.plane_x = data->var.plane_x * cos(-data->var.rotate_speed) \
		- data->var.plane_y * sin(-data->var.rotate_speed);
	data->var.plane_y = old_plane_x * sin(-data->var.rotate_speed) \
		+ data->var.plane_y * cos(-data->var.rotate_speed);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		clear_and_exit0(data);
	else if (keycode == W)
		data->key.w = KEY_IS_PRESSED;
	else if (keycode == S)
		data->key.s = KEY_IS_PRESSED;
	else if (keycode == A)
		data->key.a = KEY_IS_PRESSED;
	else if (keycode == D)
		data->key.d = KEY_IS_PRESSED;
	else if (keycode == LEFT)
		data->key.left = KEY_IS_PRESSED;
	else if (keycode == RIGHT)
		data->key.right = KEY_IS_PRESSED;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->key.w = KEY_IS_RELEASED;
	else if (keycode == S)
		data->key.s = KEY_IS_RELEASED;
	else if (keycode == A)
		data->key.a = KEY_IS_RELEASED;
	else if (keycode == D)
		data->key.d = KEY_IS_RELEASED;
	else if (keycode == LEFT)
		data->key.left = KEY_IS_RELEASED;
	else if (keycode == RIGHT)
		data->key.right = KEY_IS_RELEASED;
	return (0);
}
