/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:10:15 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 13:13:47 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	free_mlx(game);
	exit(1);
}
