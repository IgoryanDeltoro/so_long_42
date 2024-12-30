/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:40:40 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/28 11:44:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

static int	count_collectibles(t_game *game, int x, int y)
{
	int	count;

	count = 0;
	if (game->map[y][x] == 'C')
		game->collectibles += 1;
	if (game->map[y][x] == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		count++;
	}
	if (game->map[y][x] == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
		count++;
	}
	return (count);
}

static char	*validate_map_size(t_game *game)
{
	int	sizex;
	int	sizey;

	if (!game)
		return ("FMP");
	sizex = game->def_size_img * game->map_width;
	sizey = game->def_size_img * game->map_height;
	if (sizex > MAX_X_SCREEN_SIZE || sizex < MIN_Y_SCREEN_SIZE * 2)
		return ("IMS");
	if (sizey > MAX_Y_SCREEN_SIZE || sizey < MIN_Y_SCREEN_SIZE)
		return ("IMS");
	return ("OK");
}

static char	*check_path_validity(t_game *game)
{
	int		i;
	char	**temp_map;
	int		reachable_items;

	temp_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!temp_map)
		return ("FMP");
	i = 0;
	while (i < game->map_height)
	{
		temp_map[i] = ft_strdup(game->map[i]);
		if (!temp_map[i])
		{
			temp_map = free_alocated_memory(temp_map, i);
			return ("FMP");
		}
		i++;
	}
	temp_map[game->map_height] = NULL;
	reachable_items = game->collectibles + 1;
	flood_fill(temp_map, game->player_x, game->player_y, &reachable_items);
	free_map(temp_map);
	if (reachable_items != 0)
		return ("NVP");
	return ("OK");
}

static char	*validate_map_items(t_game *game)
{
	int	x;
	int	y;
	int is_double;
	
	y = 0;
	is_double = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (ft_strchr("01CEP", game->map[y][x]) == NULL)
				return ("ICM");
			is_double += count_collectibles(game, x, y);
			x++;
		}
		if (game->map_width != ft_strlen(game->map[y]))
			return ("MSL");
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
			return ("IW");
		y++;
	}
	if (is_double != 2 || game->collectibles < 1)
		return ("TMI");
	return ("OK");
}

int	validate_map(t_game *game)
{
	char	*res;

	if (!game)
		return (-1);
	res = validate_map_items(game);
	if (ft_strcmp(res, "OK") != 0)
		return (print_error(res), -1);
	res = validate_map_size(game);
	if (ft_strcmp(res, "OK") != 0)
		return (print_error(res), -1);
	res = check_path_validity(game);
	if (ft_strcmp(res, "OK") != 0)
		return (print_error(res), -1);
	return (1);
}
