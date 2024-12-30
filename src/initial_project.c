/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_project.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:42:35 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 12:45:07 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initial_project(t_game *game)
{
	if (!game)
		return ;
	game->mlx = NULL;
	game->win = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->def_size_img = 50;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collectibles = 0;
	game->moves = 0;
	game->img.wall = NULL;
	game->img.floor = NULL;
	game->img.weapon = NULL;
	game->img.hearo = NULL;
	game->img.door = NULL;
}
