/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:31:50 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 13:04:55 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	create_images(t_game *game, char *paths[], void **textures[])
{
	int	h;
	int	w;
	int	i;

	w = 0;
	h = 0;
	i = 0;
	while (i < 5)
	{
		*(textures[i]) = mlx_xpm_file_to_image(game->mlx, paths[i], &w, &h);
		if (!textures[i] || game->def_size_img != h || game->def_size_img != w)
			return (print_error("FLT"), -1);
		i++;
	}
	return (1);
}

int	create_mlx_images(t_game *game)
{
	char	*paths[5];
	void	*textures[5];

	if (!game)
		return (print_error("FLT"), -1);
	paths[0] = "./assets/textures/wall.xpm";
	paths[1] = "./assets/textures/floor.xpm";
	paths[2] = "./assets/textures/weapon.xpm";
	paths[3] = "./assets/textures/hearo.xpm";
	paths[4] = "./assets/textures/door.xpm";
	textures[0] = &game->img.wall;
	textures[1] = &game->img.floor;
	textures[2] = &game->img.weapon;
	textures[3] = &game->img.hearo;
	textures[4] = &game->img.door;
	if (create_images(game, paths, (void ***)textures) == -1)
		return (print_error("FLT"), -1);
	return (1);
}
