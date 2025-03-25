/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:35:25 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/24 10:39:34 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_key(int keycode, t_game *game)
{
	if (keycode == 119)
		ft_move_up(game);
	else if (keycode == 97)
		ft_move_left(game);
	else if (keycode == 115)
		ft_move_down(game);
	else if (keycode == 100)
		ft_move_right(game);
	return (0);
}

int	ft_on_keypress(int keycode, t_game *data)
{
	if (keycode == 65307)
		ft_close_window(data);
	else
		ft_handle_key(keycode, data);
	return (0);
}

int	ft_close_window(t_game *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_print_error("Error\nIncorrect arguments.");
	if (!ft_is_ber(argv[1]))
		ft_print_error("Error\nInvalid file.");
	game = ft_init_game(argv[1]);
	mlx_hook(game->mlx_win, 17, 1L << 17, ft_close_window, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, ft_on_keypress, game);
	mlx_loop(game->mlx);
	return (0);
}
