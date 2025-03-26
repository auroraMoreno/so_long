/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:18 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/26 13:34:15 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_game(t_game *game, int n, char *msg)
{
	int	i;

	if (game)
	{
		if (game->map_heigth && game->map)
		{
			i = 0;
			while (i < game->map_heigth)
			{
				free(game->map[i]);
				i++;
			}
			free(game->map);
		}
		ft_destroy_images(game);
		ft_destroy_mlx(game);
		free(game);
	}
	if (n == 1)
		ft_end_game();
	else if (n == 0)
		ft_print_error(msg);
}

void	ft_end_game(void)
{
	ft_putendl_fd("CONGRATULATIONS! YOU WON!", 1);
	exit(EXIT_SUCCESS);
}

void	ft_print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}
