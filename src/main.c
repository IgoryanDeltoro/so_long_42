/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:41:09 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 16:05:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_allocated_memory(t_game *game)
{
	if (!game)
		return ;
	free_map(game->map);
	destroy_img(game);
	free_mlx(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_error("FD"), 1);
	if (check_map_fd(av[1]) == -1)
		return (1);
	initial_project(&game);
	if (parse_map(&game, av[1]) == -1)
		return (1);
	if (initial_mlx(&game) == -1)
		return (free_map(game.map), 1);
	if (create_mlx_images(&game) == -1)
		return (free_allocated_memory(&game), 1);
	if (create_mlx_window(&game) == -1)
		return (free_allocated_memory(&game), 1);
	render_map(&game);
	listen_event(&game);
	mlx_loop(game.mlx);
	return (0);
}
