/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:43:07 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/26 13:20:38 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_join_map_line(char *line, char **joined_str)
{
	char	*aux;

	aux = ft_strjoin(*joined_str, line);
	if (!aux)
	{
		free(*joined_str);
		free(line);
		return (0);
	}
	free(*joined_str);
	free(line);
	*joined_str = aux;
	if (!*joined_str)
		return (0);
	return (1);
}

static void	ft_process_map_line(char *joined_str, t_game *game)
{
	ft_get_width(joined_str, game);
	ft_get_height(joined_str, game);
	ft_map_is_valid(game, joined_str);
	game->map = malloc(sizeof(t_map *) * game->map_heigth);
	if (!game->map)
		ft_free_joined_line(joined_str, game, "Error\nMap not allocated.");
	ft_innit_x_row(game, joined_str);
	ft_fill_x_row(game, joined_str);
	ft_valid_route(game, joined_str);
}

void	ft_fill_x_row(t_game *game, char *joined_str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < game->map_heigth)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (joined_str[x] == '\n')
			{
				x++;
				continue ;
			}
			game->map[i][j].x = i;
			game->map[i][j].y = j;
			game->map[i][j].value = joined_str[x];
			j++;
			x++;
		}
		i++;
	}
}

void	ft_innit_x_row(t_game *game, char *joined_str)
{
	int	i;

	i = 0;
	while (i < game->map_heigth)
	{
		game->map[i] = malloc(sizeof(t_map) * game->map_width);
		if (!game->map[i])
			ft_free_joined_line(joined_str, game,
				"Error\nError alocating the map.");
		i++;
	}
}

void	ft_init_map(t_game *game, char *file)
{
	char	*joined_str;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(game);
		ft_print_error("Error\nFile not found.");
	}
	joined_str = ft_calloc(1, sizeof(char));
	if (!joined_str)
		ft_free_game(game, 0, "Error\nError with memory.");
	line = get_next_line(fd);
	while (line)
	{
		if (ft_join_map_line(line, &joined_str) == 0)
			ft_free_joined_line(joined_str, game,
				"Error\nError joining map line.");
		line = get_next_line(fd);
	}
	close(fd);
	ft_process_map_line(joined_str, game);
	free(joined_str);
}
