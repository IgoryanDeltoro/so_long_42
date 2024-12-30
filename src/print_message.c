/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:42:56 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/28 11:47:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_char(char c)
{
	write(1, &c, 1);
}

static void	print_str(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		put_char(*str);
		str++;
	}
}

static void	display_moves(t_game *game, char *str)
{
	char	*dest;

	dest = ft_strjoin("Movement count: ", str);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, dest);
	free(dest);
}

void	print_movings(t_game *game)
{
	char	*moves;

	if (!game)
		return ;
	moves = ft_itoa(game->moves);
	print_str("Movement count: ");
	print_str(moves);
	put_char('\n');
	display_moves(game, moves);
	free(moves);
}

static void	handle_rest_error(char *error)
{
	if (!ft_strcmp(error, "FCW"))
		print_str("Error\nFailed to create window.\n");
	if (!ft_strcmp(error, "FLT"))
		print_str("Error\nFailed to load texture.\n");
	if (!ft_strcmp(error, "TMI"))
		print_str("Error\nIncorrect number of items like E, P or C.\n");
	if (!ft_strcmp(error, "MSL"))
		print_str("Error\nAll the lines should be the same length.\n");
	if (!ft_strcmp(error, "IW"))
		print_str("Error\nMap must be enclosed by walls.\n");
	if (!ft_strcmp(error, "ICM"))
		print_str("Error\nInvalid character in map.\n");
	if (!ft_strcmp(error, "NVP"))
		print_str("Error\nThere's no right way in the map.\n");
	if (!ft_strcmp(error, "IMS"))
		print_str("Error\nIncorrect map size.\n");
}

void	print_error(char *error)
{
	if (!error)
		return ;
	if (!ft_strcmp(error, "FD"))
		print_str("Error\nUsage: ./so_long <map_file.ber>\n");
	if (!ft_strcmp(error, "WN"))
		print_str("Error\nThe map description file must contain a .ber ending.\n");
	if (!ft_strcmp(error, "TSN"))
		print_str("Error\nThe map name must be more than 4 characters long.\n");
	if (!ft_strcmp(error, "IFD"))
		print_str("Error\nIncorrect file name or permission denied.\n");
	if (!ft_strcmp(error, "FMP"))
		print_str("Error\nFaild map parsing.\n");
	if (!ft_strcmp(error, "FIM"))
		print_str("Error\nFailed to initialize MLX.\n");
	handle_rest_error(error);
}
