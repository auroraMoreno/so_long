/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:22:06 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/26 09:55:39 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_skip_exit(t_game *game, int x, int y)
{
	int	old_x;
	int	old_y;

	if (game->map[y][x].value && game->map[y][x].value != '1'
	&& y >= 0 && x >= 0
	&& y <= game->map_heigth && x <= game->map_width)
	{
		if (game->map[y][x].value == 'C')
			game->num_collect--;
		old_x = game->player.x_pos;
		old_y = game->player.y_pos;
		game->player.y_pos = y;
		game->player.x_pos = x;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img_ptr,
			(game->player.x_pos * 64), (game->player.y_pos * 64));
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr,
			(old_x * 64), (old_y * 64));
		game->map[game->player.y_pos][game->player.x_pos].value = '0';
		game->map[y][x].value = 'P';
	}
}

void	ft_handle_exit(t_game *game, int x, int y)
{
	if (x == game->player.x_pos)
	{
		if (game->player.y_pos > y)
			ft_skip_exit(game, x, y - 1);
		else if (game->player.y_pos < y)
			ft_skip_exit(game, x, y + 1);
	}
	else if (y == game->player.y_pos)
	{
		if (game->player.x_pos > x)
			ft_skip_exit(game, x - 1, y);
		else if (game->player.y_pos < x)
			ft_skip_exit(game, x + 1, y);
	}
}

int	ft_validate_move(t_game *game, int x, int y)
{
	if (game->map[y][x].value == '1')
		return (0);
	else if (game->map[y][x].value == 'E')
	{
		if (game->num_collect == 0)
		{
			ft_free_game(game, 1, "");
			return (1);
		}
		else
		{
			ft_handle_exit(game, x, y);
			return (0);
		}
	}
	else if (game->map[y][x].value == 'C')
	{
		game->num_collect--;
		return (1);
	}
	return (1);
}

void	ft_change_value(t_game *game, int old_x, int old_y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img_ptr,
		(game->player.x_pos * 64), (game->player.y_pos * 64));
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr,
		(old_x * 64), (old_y * 64));
	game->map[old_y][old_x].value = '0';
	game->map[game->player.y_pos][old_x].value = 'P';
}
