/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:16:33 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/25 13:24:47 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	int	old_y_pos;

	if (ft_validate_move(game, game->ghost.x_pos, game->ghost.y_pos - 1) == 1)
	{
		old_y_pos = game->ghost.y_pos;
		game->ghost.y_pos -= 1;
		ft_change_value(game, game->ghost.x_pos, old_y_pos);
		game->steps_counter++;
		printf("Steps: %d\n", game->steps_counter);
	}
}

void	ft_move_down(t_game *game)
{
	int	old_y_pos;

	if (ft_validate_move(game, game->ghost.x_pos, game->ghost.y_pos + 1) == 1)
	{
		old_y_pos = game->ghost.y_pos;
		game->ghost.y_pos += 1;
		ft_change_value(game, game->ghost.x_pos, old_y_pos);
		game->steps_counter++;
		printf("Steps: %d\n", game->steps_counter);
	}
}

void	ft_move_left(t_game *game)
{
	int	old_x_pos;

	if (ft_validate_move(game, game->ghost.x_pos - 1, game->ghost.y_pos) == 1)
	{
		old_x_pos = game->ghost.x_pos;
		game->ghost.x_pos -= 1;
		ft_change_value(game, old_x_pos, game->ghost.y_pos);
		game->steps_counter++;
		printf("Steps: %d\n", game->steps_counter);
	}
}

void	ft_move_right(t_game *game)
{
	int	old_x_pos;

	if (ft_validate_move(game, game->ghost.x_pos + 1, game->ghost.y_pos) == 1)
	{
		old_x_pos = game->ghost.x_pos;
		game->ghost.x_pos += 1;
		ft_change_value(game, old_x_pos, game->ghost.y_pos);
		game->steps_counter++;
		printf("Steps: %d\n", game->steps_counter);
	}
}
