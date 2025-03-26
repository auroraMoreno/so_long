/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:31:07 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/26 13:38:05 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_images(t_game *game)
{
	if (game->floor.img_ptr)
		mlx_destroy_image(game->mlx, game->floor.img_ptr);
	if (game->player.img_ptr)
		mlx_destroy_image(game->mlx, game->player.img_ptr);
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx, game->wall.img_ptr);
	if (game->collectable.img_ptr)
		mlx_destroy_image(game->mlx, game->collectable.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx, game->exit.img_ptr);
}

void	ft_free_joined_line(char *joined_str, t_game *game, char *msg)
{
	if (joined_str)
		free(joined_str);
	if (game)
		free(game);
	ft_print_error(msg);
}

char	**free_map_copy(char **map_copy, int i)
{
	while (--i >= 0)
		free(map_copy[i]);
	free(map_copy);
	map_copy = NULL;
	return (map_copy);
}

void	ft_destroy_mlx(t_game *game)
{
	if (game->mlx_win && game->mlx)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
