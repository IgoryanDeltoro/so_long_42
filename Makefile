NAME = so_long
CC = cc
MLX_DIR = ./include/minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror
RM = rm -rf


SRC =	./src/main.c  ./src/parse_map.c ./src/utils/get_next_line.c ./src/utils/get_next_line_utils.c\
		./src/utils/ft_strlen.c ./src/valid_map.c ./src/render_map.c ./src/utils/ft_strchr.c
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