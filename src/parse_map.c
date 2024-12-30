/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:36:50 by igoryan           #+#    #+#             */
/*   Updated: 2024/12/27 13:27:48 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parse_map(t_game *game, const char *file)
{
	int		fd;
	char	*line;
	int		res;

	if (!game)
		return (print_error("FMP"), -1);
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("IFD"), -1);
	res = get_next_line(fd, &line);
	if (res == -1)
		return (print_error("FMP"), free(line), close(fd), -1);
	if (res == 0)
	{
		game->map = ft_split(line, '\n');
		free(line);
		if (!(game->map))
			return (print_error("FMP"), close(fd), -1);
		game->map_height = ft_two_d_len(game->map);
		game->map_width = ft_strlen(game->map[0]);
		if (validate_map(game) == -1)
			return (free_map(game->map), close(fd), -1);
	}
	return (close(fd), 1);
}
