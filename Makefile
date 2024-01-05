NAME = cub3D
FLAGS = -Wall -Wextra -Werror 
# -fsanitize=address -g
LIBRARIES = -Lmlx -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(MINILIBX_DIR) -I$(LIBFT_DIR) -I$(INCLUDES_DIR)

SRCS = 	srcs/main.c\
		srcs/data_define_1.c\
		srcs/data_define_2.c\
		srcs/data_define_3.c\
		srcs/data_get_1.c\
		srcs/data_get_2.c\
		srcs/movement_1.c\
		srcs/movement_2_key.c\
		srcs/raycast_1.c\
		srcs/raycast_2.c\
		srcs/raycast_3.c\
		srcs/utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES_DIR = ./include/
INCLUDES_FILE = cub_main.h cub_struct.h

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADER = $(LIBFT_DIR)

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./mlx/

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	cc $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJS) -o $(NAME)

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)


$(MINILIBX):
	$(MAKE) -sC $(MINILIBX_DIR)

%o: %c $(addprefix $(INCLUDES_DIR), $(INCLUDES_FILE))
	cc $(FLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MINILIBX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(MINILIBX)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
