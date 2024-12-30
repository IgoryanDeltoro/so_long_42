/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:08:50 by igoryan           #+#    #+#             */
/*   Updated: 2024/12/27 15:59:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100
# define MAX_X_SCREEN_SIZE 1920
# define MAX_Y_SCREEN_SIZE 900
# define MIN_Y_SCREEN_SIZE 300
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_texture
{
	void				*wall;
	void				*floor;
	void				*weapon;
	void				*hearo;
	void				*door;
}						t_texture;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				**map;
	int					map_width;
	int					map_height;
	int					def_size_img;
	int					player_x;
	int					player_y;
	int					exit_x;
	int					exit_y;
	int					collectibles;
	int					moves;
	struct s_texture	img;
}						t_game;

int						get_next_line(int fd, char **line);
char					*ft_strdup(char *s);
char					*ft_strjoin(char *s1, char *s2);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strchr(char *s, int c);
int						ft_strlen(const char *s);
int						ft_two_d_len(char **s);
char					**ft_split(char const *s, char c);
int						ft_strlcpy(char *dst, const char *src, int size);
char					*ft_strchr(char *s, int c);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_itoa(int n);
void					flood_fill(char **map, int x, int y,
							int *reachable_items);
void					*free_alocated_memory(char **words, int count);
void					initial_project(t_game *game);
int						parse_map(t_game *game, const char *file);
void					render_map(t_game *game);
void					free_map(char **map);
int						validate_map(t_game *game);
int						initial_mlx(t_game *game);
int						create_mlx_images(t_game *game);
int						create_mlx_window(t_game *game);
void					destroy_img(t_game *game);
void					free_mlx(t_game *game);
void					listen_event(t_game *game);
void					close_game(t_game *game);
void					move_hearo(t_game *game, char *str);
void					print_movings(t_game *game);
void					print_error(char *error);
int 					check_map_fd(char *str);

#endif
