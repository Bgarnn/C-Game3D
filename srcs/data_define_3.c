#include "../include/cub_main.h"

static void	vector_init_2(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E')
	{
		data->var.dir_x = 1;
		data->var.dir_y = 0;
		data->var.plane_x = 0;
		data->var.plane_y = 0.66;
	}
	else if (data->map[y][x] == 'W')
	{
		data->var.dir_x = -1;
		data->var.dir_y = 0;
		data->var.plane_x = 0;
		data->var.plane_y = -0.66;
	}
}

static void	vector_init(t_data *data, int x, int y)
{
	data->var.position_x = x + 0.5;
	data->var.position_y = y + 0.5;
	if (data->map[y][x] == 'N')
	{
		data->var.dir_x = 0;
		data->var.dir_y = -1;
		data->var.plane_x = 0.66;
		data->var.plane_y = 0;
	}
	else if (data->map[y][x] == 'S')
	{
		data->var.dir_x = 0;
		data->var.dir_y = 1;
		data->var.plane_x = -0.66;
		data->var.plane_y = 0;
	}
	vector_init_2(data, x, y);
}

int	char_check(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_strchr(" 10NSEW", data->map[i][j]))
				return (0);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				vector_init(data, j, i);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	if (!str[i])
		return (FALSE);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
