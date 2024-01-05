#ifndef CUB_MAIN_H
# define CUB_MAIN_H

# include "cub_struct.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

void	data_define(t_data *data);
int		texture_define(t_data *data);
int		map_validate(t_data *data);
int		char_check(t_data *data);
int		ft_isnum(char *str);
void	data_get(char **argv, t_data *data);
int		map_get(t_data *data, int fd);
void	movement(t_data *data);
void	player_rotate_right(t_data *data);
void	player_rotate_left(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	raycast(t_data *data);
void	raycast_2(t_data *data);
void	raycast_3(t_data *data);
void	ft_free_2d(char **str);
int		ft_arrchar2d_len(char **str);
void	mlx_place_pixel(t_data *data, int x, int y, int colour);
void	clear_and_exit0(t_data *data);
void	error_exit(t_data *data, char *str1, char *str2);

#endif
