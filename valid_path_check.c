/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:46:06 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/25 13:39:41 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_copy(t_map **map, int map_width, int map_height)
{
	char	**map_copy;
	int		i;
	int		j;

	i = 0;
	map_copy = malloc(sizeof(char *) * (map_height + 1));
	if (!map_copy)
		return (NULL);
	while (i < map_height)
	{
		j = 0;
		map_copy[i] = malloc(sizeof(char) * (map_width + 1));
		if (!map_copy[i])
			return (free_map_copy(map_copy, i), (NULL));
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

void	ft_flood_fill(char **map_copy, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_heigth)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	ft_flood_fill(map_copy, x + 1, y, game);
	ft_flood_fill(map_copy, x - 1, y, game);
	ft_flood_fill(map_copy, x, y + 1, game);
	ft_flood_fill(map_copy, x, y - 1, game);
}

void	ft_find_player_and_fill(char **map_copy, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_heigth)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (map_copy[i][j] == 'P')
			{
				ft_flood_fill(map_copy, j, i, game);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_validate_flood_fill(t_game *game, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_heigth)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				printf("Invalid path\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	ft_valid_route(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = ft_map_copy(game->map, game->map_width, game->map_heigth);
	if (!map_copy)
	{
		exit(EXIT_FAILURE);
	}
	ft_find_player_and_fill(map_copy, game);
	ft_validate_flood_fill(game, map_copy);
	i = 0;
	while (i < game->map_heigth)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
