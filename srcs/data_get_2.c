#include "../include/cub_main.h"

static char	**ft_reallocation(char **ptr, int size)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc(sizeof(char *) * size);
	if (!res)
		return (NULL);
	while (ptr[i])
	{
		res[i] = ptr[i];
		i++;
	}
	res[i] = NULL;
	res[i + 1] = NULL;
	free(ptr);
	return (res);
}

static int	map_init(t_data *data, char *line)
{
	char	**tmp;

	if (!data->map)
	{
		data->map = malloc(sizeof(char *) * 2);
		if (!data->map)
			return (FALSE);
		data->map[0] = ft_strdup(line);
		data->map[1] = NULL;
	}
	else
	{
		tmp = ft_reallocation(data->map, ft_arrchar2d_len(data->map) + 2);
		if (!tmp)
			return (FALSE);
		data->map = tmp;
		data->map[ft_arrchar2d_len(data->map)] = ft_strdup(line);
	}
	return (TRUE);
}

int	map_get(t_data *data, int fd)
{
	char	*line;
	int		gnl_num;

	while (1)
	{
		gnl_num = get_next_line(fd, &line);
		if (gnl_num == -1)
			return (FALSE);
		if (ft_strlen(line) == 0 && !data->map)
			;
		else if (map_init(data, line) == FALSE)
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
