NAME = so_long
CC = cc

MLX_DIR = ./include/minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC =	\
		./src/utils/ft_strjoin.c \
		./src/utils/get_next_line.c \
		./src/utils/ft_strdup.c \
		./src/utils/ft_strlen.c \
		./src/utils/ft_strchr.c \
		./src/utils/ft_strcmp.c \
		./src/utils/ft_split.c \
		./src/utils/ft_strlcpy.c \
		./src/utils/ft_itoa.c \
		./src/utils/flood_fill.c \
		./src/free_memory.c\
		./src/validate_map.c \
		./src/render_map.c \
		./src/main.c  \
		./src/parse_map.c \
		./src/initial_mlx.c \
		./src/create_mlx_images.c \
		./src/create_mlx_window.c \
		./src/initial_project.c \
		./src/listen_event.c \
		./src/close_game.c \
		./src/move_hearo.c \
		./src/print_message.c \
		./src/check_map_fd.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
