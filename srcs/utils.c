#include "../include/cub_main.h"

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int	ft_arrchar2d_len(char **str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	if (!str[len])
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	mlx_place_pixel(t_data *data, int x, int y, int colour)
{
	char	*addr;

	addr = (char *)data->img_scr.addr + \
		(y * data->img_scr.line_len + x * (data->img_scr.bits_per_pxl / 8));
	*(unsigned int *)addr = colour;
}

void	clear_and_exit0(t_data *data)
{
	if (data->map)
		ft_free_2d(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	data = 0;
	exit(0);
}

void	error_exit(t_data *data, char *str1, char *str2)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str1, 1);
	ft_putstr_fd(str2, 1);
	ft_putstr_fd("\n", 1);
	clear_and_exit0(data);
}
