/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:36:50 by igoryan           #+#    #+#             */
/*   Updated: 2024/12/12 13:26:28 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     parse_map(t_game *game, const char *file)
{
    int fd;
    int i;
    char *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "open: %s: %s (errno = %d)\n",
            file, strerror(errno), errno);
        exit(EXIT_FAILURE);
    }
    game->map = malloc(sizeof(char*) * 6);
    while ((line = get_next_line(fd)))
    {
        game->map[i++] = line;
        printf("line: %s\n", line);
    }
    game->map[i] = '\0';
    game->height = i;
    game->width = ft_strlen(game->map[0]);
    validate_map(game);
    close(fd);
    return (1);
}