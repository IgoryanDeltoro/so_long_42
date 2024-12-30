/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:32:50 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 12:45:03 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	close_window_handler(t_game *game)
{
	close_game(game);
	return (0);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65361 || keycode == 97)
		move_hearo(game, "LEFT");
	if (keycode == 65362 || keycode == 119)
		move_hearo(game, "UP");
	if (keycode == 65363 || keycode == 100)
		move_hearo(game, "RIGHT");
	if (keycode == 65364 || keycode == 115)
		move_hearo(game, "DOWN");
	if (keycode == 65307)
		close_game(game);
	return (1);
}

void	listen_event(t_game *game)
{
	if (!game)
		return ;
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_window_handler, game);
}
