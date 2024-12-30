/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hearo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:40:44 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 13:09:24 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_movimg(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == 'C')
		return (1);
	if (game->map[y][x] == 'E')
		return (1);
	return (0);
}

static void	rewrite_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C' && game->collectibles > 0)
		game->collectibles -= 1;
	if (game->map[y][x] != 'E')
		game->map[game->exit_y][game->exit_x] = 'E';
	game->map[y][x] = 'P';
	if (game->player_y != game->exit_y || game->player_x != game->exit_x)
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	render_map(game);
	game->moves += 1;
	print_movings(game);
	if (game->player_y == game->exit_y && game->player_x == game->exit_x
		&& game->collectibles == 0)
		close_game(game);
}

void	move_hearo(t_game *game, char *str)
{
	if (!game)
		return ;
	if (ft_strcmp(str, "LEFT") == 0)
	{
		if (check_movimg(game, game->player_x - 1, game->player_y))
			rewrite_map(game, game->player_x - 1, game->player_y);
	}
	if (ft_strcmp(str, "UP") == 0)
	{
		if (check_movimg(game, game->player_x, game->player_y - 1))
			rewrite_map(game, game->player_x, game->player_y - 1);
	}
	if (ft_strcmp(str, "RIGHT") == 0)
	{
		if (check_movimg(game, game->player_x + 1, game->player_y))
			rewrite_map(game, game->player_x + 1, game->player_y);
	}
	if (ft_strcmp(str, "DOWN") == 0)
	{
		if (check_movimg(game, game->player_x, game->player_y + 1))
			rewrite_map(game, game->player_x, game->player_y + 1);
	}
}
