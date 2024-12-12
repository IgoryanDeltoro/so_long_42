/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:08:50 by igoryan           #+#    #+#             */
/*   Updated: 2024/12/12 12:50:28 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <errno.h>

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
}   t_game;

//--------------------- UTILS------------------------//
//      get_next_line 
char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, char *src, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
//-------------~~~~~~~~~~~~~~-----------------------//
int	ft_strlen(const char *s);
void    validate_map(t_game *game);
char	*ft_strchr(char *s, int c);

int     parse_map(t_game *game, const char *file);
void    render_map(t_game *game);

#endif 