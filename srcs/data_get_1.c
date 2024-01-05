#include "../include/cub_main.h"

static void	rgb_init(t_data *data, char *line)
{
	char	*tmp;

	tmp = line;
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		tmp += 2;
		data->rgb[0] = ft_strdup(tmp);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		tmp += 2;
		data->rgb[1] = ft_strdup(tmp);
	}
}

static void	texture_init(t_data *data, char **arr_2d)
{
	if (ft_strncmp(arr_2d[0], "NO", 3) == 0)
		data->xpm[0] = ft_strdup(arr_2d[1]);
	else if (ft_strncmp(arr_2d[0], "EA", 3) == 0)
		data->xpm[1] = ft_strdup(arr_2d[1]);
	else if (ft_strncmp(arr_2d[0], "SO", 3) == 0)
		data->xpm[2] = ft_strdup(arr_2d[1]);
	else if (ft_strncmp(arr_2d[0], "WE", 3) == 0)
		data->xpm[3] = ft_strdup(arr_2d[1]);
}

static int	info_init(t_data *data, char *line)
{
	char	**arr_2d;

	arr_2d = 0;
	if (line && ft_strlen(line) > 2 && (ft_strncmp(line, "F ", 2) == 0 || \
			ft_strncmp(line, "C ", 2) == 0))
		rgb_init(data, line);
	else
	{
		arr_2d = ft_split(line, ' ');
		if (arr_2d && ft_arrchar2d_len(arr_2d) == 2)
			texture_init(data, arr_2d);
		else
			return (FALSE);
	}
	if (arr_2d)
		ft_free_2d(arr_2d);
	return (TRUE);
}

static int	info_get(t_data *data, int fd)
{
	char	*line;
	int		gnl_num;

	while (ft_arrchar2d_len(data->xpm) != 4 || ft_arrchar2d_len(data->rgb) != 2)
	{
		gnl_num = get_next_line(fd, &line);
		if (gnl_num == -1)
			return (FALSE);
		if (ft_strlen(line) == 0)
			;
		else if (info_init(data, line) == FALSE)
		{
			free(line);
			return (FALSE);
		}
		free(line);
		if (gnl_num == 0)
			break ;
	}
	return (TRUE);
}

void	data_get(char **argv, t_data *data)
{
	int		fd;
	size_t	len;

	len = ft_strlen(argv[1]);
	if (len < 4)
		error_exit(data, "Unknown file type: ", argv[1]);
	if (!(argv[1][len - 1] == 'b' && argv[1][len - 2] == 'u' \
		&& argv[1][len - 3] == 'c' && argv[1][len - 4] == '.'))
		error_exit(data, "Unknown file type: ", argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit(data, "Cannot open file: ", argv[1]);
	if (info_get(data, fd) == FALSE)
		error_exit (data, "Invalid information in file: ", argv[1]);
	if (map_get(data, fd) == FALSE)
		error_exit (data, "Invalid map in file: ", argv[1]);
	close(fd);
}
