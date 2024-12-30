/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:22:07 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 12:45:11 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	initial_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (print_error("FIM"), -1);
	return (1);
}
