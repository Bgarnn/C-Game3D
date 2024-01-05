NAME =	libft.a
FLAGS = -Wall -Wextra -Werror
SRC =	ft_bzero.c ft_strlen.c ft_atoi.c ft_strchr.c ft_strncmp.c \
		ft_strdup.c ft_substr.c ft_strtrim.c ft_split.c ft_putstr_fd.c \
		get_next_line.c get_next_line_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%o: %c
	gcc $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re