/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:46:06 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/20 11:22:57 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_map_copy(t_map **map, int map_width, int map_height)
{
    char **map_copy;
    int i;
    int j;

    i = 0;
    map_copy = malloc(sizeof(char *) * (map_height + 1));
    if (!map_copy)
        return (NULL);

    while (i < map_height)
    {
        j = 0;
        map_copy[i] = malloc(sizeof(char) * (map_width + 1));
        if (!map_copy[i])
        {
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (NULL);
        }

        while (j < map_width)
        {
            map_copy[i][j] = map[i][j].value;
            j++;
        }
        map_copy[i][j] = '\0';
        i++;
    }
    map_copy[i] = NULL;

    return (map_copy);
}

void ft_flood_fill(char **map_copy, int x, int y, int map_width, int map_height)
{
    if (x < 0 || y < 0 || x >= map_width || y >= map_height)
        return;
    if (map_copy[y][x] == '1' || map_copy[y][x] == 'V') // '1' is wall, 'F' is visited
        return;

    // Mark current position as visited
    map_copy[y][x] = 'V';

    // Recursive flood fill in all directions (up, down, left, right)
    ft_flood_fill(map_copy, x + 1, y, map_width, map_height); // Right
    ft_flood_fill(map_copy, x - 1, y, map_width, map_height); // Left
    ft_flood_fill(map_copy, x, y + 1, map_width, map_height); // Down
    ft_flood_fill(map_copy, x, y - 1, map_width, map_height); // Up
}


void ft_valid_route(t_game *game)
{
    char **map_copy;
    int i;
    int j;

    // coger el map y convertirlo en matriz 
    map_copy = ft_map_copy(game->map, game->map_width, game->map_heigth);
    if(!map_copy)
    {
        //free(game);
        exit(EXIT_FAILURE); // de momento esto pero habrá que cambiarlo
    }

    //get player innit pos
    i = 0;
    while (i < game->map_heigth)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (map_copy[i][j] == 'P')
            {
                ft_flood_fill(map_copy, j, i, game->map_width, game->map_heigth);
                break;
            }
            j++;
        }
        i++;
    }

    //hacer la comprobacion
        i = 0;
        while (i < game->map_heigth)
        {
            j = 0;
            while (j < game->map_width)
            {
                if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
                {
                    // If any collectible or exit is not reachable, print error and exit
                    //ft_free_game(game, "Error: Not all collectibles or exit are reachable");
                    printf("Invalid path\n");
                    exit(EXIT_FAILURE);
                }
                j++;
            }
            i++;
        }
    
    // hacer el free
        i = 0;
        while (i < game->map_heigth)
        {
            free(map_copy[i]);
            i++;
        }
        free(map_copy);

}