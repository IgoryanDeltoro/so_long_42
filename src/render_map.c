/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:21 by igoryan           #+#    #+#             */
/*   Updated: 2024/12/12 11:59:16 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void render_map(t_game *game)
{
    int x, y;

    for (y = 0; y < game->height; y++)
    {
        for (x = 0; x < game->width; x++)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, "assets/textures/Dirt.png", x * 64, y * 64);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, "assets/textures/player.png", x * 64, y * 64);
            // Handle other characters (0, C, E) similarly
        }
    }
}
