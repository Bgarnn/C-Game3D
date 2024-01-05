#include "../include/cub_main.h"

static void	fill_text_arr_2d(t_data *data, int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->img_txt_arr[i].height)
	{
		x = -1;
		while (++x < data->img_txt_arr[i].width)
		{
			data->txt_addr_arr2d[i][data->img_txt_arr[i].height * y + x] = \
			(data->img_txt_arr[i].addr[data->img_txt_arr[i].height * y + x]);
		}
	}
}

int	texture_define(t_data *data)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		data->img_txt_arr[i].ptr_to_img = mlx_xpm_file_to_image(data->mlx, \
			data->xpm[i], &(data->img_txt_arr[i].width), \
			&(data->img_txt_arr[i].height));
		if (!data->img_txt_arr[i].ptr_to_img)
			return (FALSE);
		data->img_txt_arr[i].addr = \
			(int *)mlx_get_data_addr(data->img_txt_arr[i].ptr_to_img, \
			&data->img_txt_arr[i].bits_per_pxl, \
			&data->img_txt_arr[i].line_len, \
			&data->img_txt_arr[i].endian);
		if (!data->img_txt_arr[i].addr)
			return (FALSE);
		fill_text_arr_2d(data, i);
		mlx_destroy_image(data->mlx, data->img_txt_arr[i].ptr_to_img);
		i++;
	}
	return (TRUE);
}

static int	is_closed_check_by_floodfill(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0' \
		|| (data->map[i][j] != '1' && data->map[i][j] != ' '))
	{
		if (i == 0 || !data->map[i + 1] || j == 0 || !data->map[i][j + 1])
			return (FALSE);
		if (data->map[i - 1] && data->map[i - 1][j]
			&& data->map[i - 1][j] == ' ')
			return (FALSE);
		if (data->map[i + 1] && data->map[i + 1][j]
			&& data->map[i + 1][j] == ' ')
			return (FALSE);
		if (data->map[i] && data->map[i][j - 1]
			&& data->map[i][j - 1] == ' ')
			return (FALSE);
		if (data->map[i] && data->map[i][j + 1]
			&& data->map[i][j + 1] == ' ')
			return (FALSE);
	}
	return (TRUE);
}

static int	is_end(t_data *data, int index)
{
	int		i;

	i = index;
	i++;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > 0)
			return (FALSE);
		i++;
	}
	data->map[i] = NULL;
	return (TRUE);
}

int	map_validate(t_data *data)
{
	int	i;
	int	j;

	if (ft_arrchar2d_len(data->map) < 3 || char_check(data) != 1)
		return (FALSE);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) == 0)
		{
			if (is_end(data, i) == FALSE)
				return (FALSE);
			break ;
		}
		j = 0;
		while (data->map[i][j])
		{
			if (is_closed_check_by_floodfill(data, i, j) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
