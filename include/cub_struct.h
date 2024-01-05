#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define DEFAULT_RES_X			800
# define DEFAULT_RES_Y			600

# define TEXTURE_HEIGHT			64
# define TEXTURE_WIDTH			64

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17

# define W 						13
# define A 						0
# define S 						1
# define D 						2
# define UP 					126
# define DOWN 					125
# define LEFT 					123
# define RIGHT 					124
# define ESC 					53

# define TRUE					1
# define FALSE					0

# define KEY_IS_PRESSED			1
# define KEY_IS_RELEASED		0

typedef struct s_var
{
	double			position_x;
	double			position_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			frame_time;
	double			move_speed;
	double			rotate_speed;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perspt_wall_dist;
	double			wall_x;
	int				map_x;
	int				map_y;
	int				hit;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				texture_number;
	int				texture_y;
	int				texture_x;
	unsigned int	color;
}					t_var;

typedef struct s_img
{
	void			*ptr_to_img;
	int				*addr;
	int				bits_per_pxl;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_key
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				right;
	int				left;
}					t_key;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	char			*xpm[5];
	char			*rgb[3];
	char			**map;
	t_img			img_scr;
	t_img			img_txt_arr[5];
	int				txt_addr_arr2d[4][TEXTURE_HEIGHT * TEXTURE_WIDTH];
	int				res_x;
	int				res_y;
	unsigned long	f_color_hex;
	unsigned long	c_color_hex;
	t_var			var;
	t_key			key;
}					t_data;

#endif
