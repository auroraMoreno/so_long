/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:16:33 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/26 12:55:20 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_print_steps(int steps)
{
	ft_putstr_fd("Steps: ", STDOUT_FILENO);
	ft_putnbr_fd(steps, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ft_move_up(t_game *game)
{
	int	old_y_pos;

	if (ft_validate_move(game, game->player.x_pos, game->player.y_pos - 1) == 1)
	{
		old_y_pos = game->player.y_pos;
		game->player.y_pos -= 1;
		ft_change_value(game, game->player.x_pos, old_y_pos);
		game->steps_counter++;
		ft_print_steps(game->steps_counter);
	}
}

void	ft_move_down(t_game *game)
{
	int	old_y_pos;

	if (ft_validate_move(game, game->player.x_pos, game->player.y_pos + 1) == 1)
	{
		old_y_pos = game->player.y_pos;
		game->player.y_pos += 1;
		ft_change_value(game, game->player.x_pos, old_y_pos);
		game->steps_counter++;
		ft_print_steps(game->steps_counter);
	}
}

void	ft_move_left(t_game *game)
{
	int	old_x_pos;

	if (ft_validate_move(game, game->player.x_pos - 1, game->player.y_pos) == 1)
	{
		old_x_pos = game->player.x_pos;
		game->player.x_pos -= 1;
		ft_change_value(game, old_x_pos, game->player.y_pos);
		game->steps_counter++;
		ft_print_steps(game->steps_counter);
	}
}

void	ft_move_right(t_game *game)
{
	int	old_x_pos;

	if (ft_validate_move(game, game->player.x_pos + 1, game->player.y_pos) == 1)
	{
		old_x_pos = game->player.x_pos;
		game->player.x_pos += 1;
		ft_change_value(game, old_x_pos, game->player.y_pos);
		game->steps_counter++;
		ft_print_steps(game->steps_counter);
	}
}
