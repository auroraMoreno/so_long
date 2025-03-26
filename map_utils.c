/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:55:46 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/26 13:42:27 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_select_image(t_game *game, char pos, int x, int y)
{
	if (pos == 'P')
	{
		game->player.x_pos = y;
		game->player.y_pos = x;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.img_ptr, y * 64, x * 64);
	}
	else if (pos == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->collectable.img_ptr, y * 64, x * 64);
	else if (pos == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit.img_ptr, y * 64, x * 64);
	else if (pos == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall.img_ptr, y * 64, x * 64);
}

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_heigth)
	{
		y = 0;
		while (y < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->floor.img_ptr, (y * 64), (x * 64));
			ft_select_image(game, game->map[x][y].value, x, y);
			y++;
		}
		x++;
	}
}

void	ft_get_width(char	*joined_str, t_game	*game)
{
	game->map_width = 0;
	while (joined_str[game->map_width] && joined_str[game->map_width] != '\n')
		game->map_width++;
	if (game->map_width == 0 || joined_str[game->map_width] == 0)
		ft_free_joined_line(joined_str, game,
			"Error\nError with map dimensions.");
}

void	ft_get_height(char *joined_str, t_game *game)
{
	int	i;
	int	current_line_len;

	game->map_heigth = 0;
	i = 0;
	while (joined_str[i] != '\0')
	{
		current_line_len = 0;
		while (joined_str[i] != '\0' && joined_str[i] != '\n')
		{
			current_line_len++;
			i++;
		}
		if (game->map_width != current_line_len)
			ft_free_joined_line(joined_str, game,
				"Error.\nMap has the wrong shape.");
		if (current_line_len > 0)
			game->map_heigth++;
		if (joined_str[i] == '\n')
			i++;
	}
}
