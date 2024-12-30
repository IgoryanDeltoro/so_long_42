/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:21 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 13:35:07 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_image_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x
			* game->def_size_img, y * game->def_size_img);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, x
			* game->def_size_img, y * game->def_size_img);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.weapon, x
			* game->def_size_img, y * game->def_size_img);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.hearo, x
			* game->def_size_img, y * game->def_size_img);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.door, x
			* game->def_size_img, y * game->def_size_img);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	if (!game)
		return ;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			put_image_to_window(game, x, y);
			x++;
		}
		y++;
	}
}
