/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:40:40 by igoryan           #+#    #+#             */
/*   Updated: 2024/12/12 13:26:41 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Helper function for flood-fill
static void flood_fill(char **map, int x, int y, int *reachable_items)
{
    // If out of bounds or not a valid cell, return
    if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0' || map[y][x] == '1')
        return;

    // If we encounter collectibles or exit, count them as reachable
    if (map[y][x] == 'C' || map[y][x] == 'E')
        (*reachable_items)--;

    // Mark the cell as visited (use a unique character like 'V')
    map[y][x] = 'V';

    // Recursively flood in all four directions
    flood_fill(map, x + 1, y, reachable_items);
    flood_fill(map, x - 1, y, reachable_items);
    flood_fill(map, x, y + 1, reachable_items);
    flood_fill(map, x, y - 1, reachable_items);
}

int check_path_validity(t_game *game)
{
    char **temp_map;
    int x, y;
    int reachable_items;

    // Copy the map for path validation (without modifying the original map)
    temp_map = malloc(sizeof(char *) * (game->height + 1));
    for (y = 0; y < game->height; y++)
        temp_map[y] = strdup(game->map[y]);
    temp_map[game->height] = NULL;

    // Count collectibles and exit as "reachable items"
    reachable_items = 0;
    for (y = 0; y < game->height; y++)
        for (x = 0; x < game->width; x++)
            if (temp_map[y][x] == 'C' || temp_map[y][x] == 'E')
                reachable_items++;

    // Locate the player's starting position (`P`)
    for (y = 0; y < game->height; y++)
        for (x = 0; x < game->width; x++)
            if (temp_map[y][x] == 'P')
                flood_fill(temp_map, x, y, &reachable_items);

    // Free the temporary map
    for (y = 0; temp_map[y] != NULL; y++)
        free(temp_map[y]);
    free(temp_map);

    // Return 1 if all items are reachable, otherwise 0
    return (reachable_items == 0);
}


void validate_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while  (y < game->height)
    {
        x = 0;
        if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
            exit(write(2, "Error\nMap must be enclosed by walls\n", 35));
        while (x < game->width)
        {
            if (ft_strchr("01CEP", game->map[y][x]) == NULL)
                exit(write(2, "Error\nInvalid character in map\n", 31));
            x++;
        }
        y++;
    }
    return ;
    if (!check_path_validity(game))
        exit(write(2, "Error\nNo valid path in map\n", 27));
}
