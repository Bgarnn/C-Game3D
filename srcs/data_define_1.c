#include "../include/cub_main.h"

static unsigned long	rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

static void	rgb_convert(t_data *data, int *rgb, int i)
{
	unsigned long	tmp_ulong;

	if (i == 0)
	{
		tmp_ulong = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data->f_color_hex = tmp_ulong;
	}
	if (i == 1)
	{
		tmp_ulong = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
		data->c_color_hex = tmp_ulong;
	}
}

static int	rgb_validate(char **array, int *rgb_3num)
{
	int		i;
	char	*trim_tmp;

	i = 0;
	while (array[i])
	{
		trim_tmp = ft_strtrim(array[i], " ");
		if (ft_isnum(trim_tmp) == FALSE)
		{
			free(trim_tmp);
			return (FALSE);
		}
		rgb_3num[i] = ft_atoi(trim_tmp);
		free(trim_tmp);
		if (rgb_3num[i] < 0 || rgb_3num[i] > 255)
			return (FALSE);
		i++;
	}
	rgb_3num[i] = 0;
	return (TRUE);
}

static int	rgb_define(t_data *data)
{
	int				i;
	char			**arr_2d;
	int				rgb_3num[4];

	i = 0;
	ft_bzero(rgb_3num, 4);
	while (data->rgb[i])
	{
		arr_2d = ft_split(data->rgb[i], ',');
		if (!arr_2d)
			return (FALSE);
		if (ft_arrchar2d_len(arr_2d) != 3 || \
			rgb_validate(arr_2d, rgb_3num) == FALSE)
		{
			ft_free_2d(arr_2d);
			return (FALSE);
		}
		rgb_convert(data, rgb_3num, i);
		ft_free_2d(arr_2d);
		i++;
	}
	return (TRUE);
}

void	data_define(t_data *data)
{
	if (texture_define(data) == FALSE)
		error_exit(data, "Cannot define texture", NULL);
	if (rgb_define(data) == FALSE)
		error_exit(data, "Cannot define color", NULL);
	if (map_validate(data) == FALSE)
		error_exit(data, "Invalid map\n", NULL);
	if (data->res_x <= 0 || data->res_y <= 0)
		error_exit(data, "Incorrect resolutuion", NULL);
	if (data->res_x > 5218 || data->res_y > 5218)
		error_exit(data, "Resolution too big for mlx", NULL);
	if (data->f_color_hex == 0xDB000000)
		error_exit(data, "Incorrect ceiling color", NULL);
	if (data->c_color_hex == 0xDB000000)
		error_exit(data, "Incorrect floor color", NULL);
}
