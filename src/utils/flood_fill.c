/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:32:10 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 13:32:39 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	flood_fill(char **map, int x, int y, int *reachable_items)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == 'H'
		|| map[y][x] == '1')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*reachable_items)--;
	map[y][x] = 'H';
	flood_fill(map, x + 1, y, reachable_items);
	flood_fill(map, x - 1, y, reachable_items);
	flood_fill(map, x, y + 1, reachable_items);
	flood_fill(map, x, y - 1, reachable_items);
}
