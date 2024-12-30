/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:56:03 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 13:14:34 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_img(t_game *game)
{
	if (game->img.wall)
	{
		mlx_destroy_image(game->mlx, game->img.wall);
		game->img.wall = NULL;
	}
	if (game->img.floor)
	{
		mlx_destroy_image(game->mlx, game->img.floor);
		game->img.floor = NULL;
	}
	if (game->img.weapon)
	{
		mlx_destroy_image(game->mlx, game->img.weapon);
		game->img.weapon = NULL;
	}
	if (game->img.hearo)
	{
		mlx_destroy_image(game->mlx, game->img.hearo);
		game->img.hearo = NULL;
	}
	if (game->img.door)
	{
		mlx_destroy_image(game->mlx, game->img.door);
		game->img.door = NULL;
	}
}

void	free_mlx(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map || !(*map))
		return ;
	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		map = NULL;
	}
}

void	*free_alocated_memory(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}
