/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:30:49 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/25 10:40:16 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_characters(t_game *game, char *joined_str, int p)
{
	if (joined_str[p] == 'P')
		game->counter.n_player++;
	else if (joined_str[p] == 'E')
		game->counter.n_exits++;
	else if (joined_str[p] == 'C')
		game->num_collect++;
	else if (joined_str[p] == '0')
		game->counter.n_floor++;
	return (1);
}

static int	ft_issurrounded(t_game *game, int i)
{
	if (i < game->map_width
		|| i > (game->map_heigth - 1) * (game->map_width + 1)
		|| i % (game->map_width + 1) == 0
		|| i % (game->map_width + 1) == game->map_width - 1
	)
		return (1);
	return (0);
}

void	ft_map_is_valid(t_game	*game, char	*joined_str)
{
	int	i;

	i = -1;
	while (joined_str[++i] != 0)
	{
		if (joined_str[i] == '\n')
			continue ;
		if (ft_issurrounded(game, i))
		{
			if (joined_str[i] != '1')
				ft_free_joined_line(joined_str, game,
					"Error\nMap must be fully surrounded by walls.");
		}
		ft_check_map_characters(game, joined_str, i);
	}
	if (game->counter.n_floor == 0)
		ft_free_joined_line(joined_str, game, "Error\nNo valid route.");
	if (game->counter.n_player > 1 || game->counter.n_player == 0)
		ft_free_joined_line(joined_str, game, "Error\nError with player.");
	if (game->counter.n_exits > 1 || game->counter.n_exits == 0)
		ft_free_joined_line(joined_str, game, "Error\nWrong number of exits.");
	if (game->num_collect == 0)
		ft_free_joined_line(joined_str, game, "Error\nNo collectables.");
}

int	ft_is_ber(char *str)
{
	char	*sub_str;
	int		i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] != '.' && str[i])
		i--;
	if (i <= 0)
		return (0);
	sub_str = ft_substr(str, i, 5);
	if (ft_strncmp(sub_str, ".ber", 5) == 0)
	{
		free(sub_str);
		return (1);
	}
	free(sub_str);
	return (0);
}
