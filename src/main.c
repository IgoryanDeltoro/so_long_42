/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:41:09 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/12 13:27:55 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game game;
	
	if (ac != 2)
	{
		write(2, "Error\nUsage: ./so_long <map_file.ber>\n", 38);
        return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
    {
        write(2, "Error\nFailed to initialize MLX\n", 31);
        return (1);
    }
    parse_map(&game, av[1]);
    game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
    render_map(&game);
    // mlx_key_hook(game.win, handle_input, &game);
    mlx_loop(game.mlx);
    free_map(&game);
    return (0);
}