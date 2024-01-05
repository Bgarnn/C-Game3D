#include "../include/cub_main.h"

static int	game_quit(t_data *data)
{
	return (clear_and_exit0(data), 0);
}

static void	background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->res_x)
	{
		j = -1;
		while (++j < data->res_y / 2)
			mlx_place_pixel(data, i, j, data->c_color_hex);
		i++;
	}
	i = 0;
	while (i < data->res_x)
	{
		j = data->res_y / 2 - 1;
		while (++j < data->res_y)
			mlx_place_pixel(data, i, j, data->f_color_hex);
		i++;
	}
}

static int	game_launch(t_data *data)
{
	data->img_scr.ptr_to_img = mlx_new_image(data->mlx, data->res_x, \
		data->res_y);
	data->img_scr.addr = (int *)mlx_get_data_addr(data->img_scr.ptr_to_img, \
		&data->img_scr.bits_per_pxl, &data->img_scr.line_len, \
		&data->img_scr.endian);
	background(data);
	raycast(data);
	movement(data);
	data->var.frame_time = 16 / 1000.0;
	data->var.move_speed = data->var.frame_time * 5.0;
	data->var.rotate_speed = data->var.frame_time * 3.0;
	mlx_put_image_to_window(data->mlx, data->win, data->img_scr.ptr_to_img, \
		0, 0);
	mlx_destroy_image(data->mlx, data->img_scr.ptr_to_img);
	return (0);
}

static void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit(data, "mlx init failed", NULL);
	data->win = 0;
	ft_bzero(data->xpm, 5);
	ft_bzero(data->rgb, 3);
	data->map = 0;
	data->res_x = DEFAULT_RES_X;
	data->res_y = DEFAULT_RES_Y;
	data->f_color_hex = 0xDB000000;
	data->c_color_hex = 0xDB000000;
	data->key.w = KEY_IS_RELEASED;
	data->key.a = KEY_IS_RELEASED;
	data->key.s = KEY_IS_RELEASED;
	data->key.d = KEY_IS_RELEASED;
	data->key.left = KEY_IS_RELEASED;
	data->key.right = KEY_IS_RELEASED;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_exit(&data, "Input should be \"cub3D [cub file]\" \nsuch as \n", "                \"./cub3D ./maps/demo.cub \"\n");
	data_init(&data);
	data_get(argv, &data);
	data_define(&data);
	data.win = mlx_new_window(data.mlx, data.res_x, data.res_y, "cub3D");
	mlx_loop_hook(data.mlx, &game_launch, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_hook(data.win, X_EVENT_KEY_RELEASE, 0, &key_release, &data);
	mlx_hook(data.win, X_EVENT_EXIT, 0, &game_quit, &data);
	mlx_loop(data.mlx);
	return (0);
}
