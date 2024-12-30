/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:37:43 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 13:31:04 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	create_mlx_window(t_game *game)
{
	if (!game)
		return (print_error("FCW"), -1);
	game->win = mlx_new_window(game->mlx, game->map_width * game->def_size_img,
			game->map_height * game->def_size_img, "so_long");
	if (!game->win)
		return (print_error("FCW"), -1);
	return (1);
}
