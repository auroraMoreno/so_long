/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:33:51 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/25 22:46:04 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game_props(t_game *game)
{
	game->num_collect = 0;
	game->counter.n_exits = 0;
	game->counter.n_player = 0;
	game->counter.n_floor = 0;
	game->steps_counter = 0;
}

void	*ft_set_images(t_game *game, char *img)
{
	char	*path;
	void	*img_ptr;

	path = ft_strjoin(XPM_PATH, img);
	img_ptr = mlx_xpm_file_to_image(game->mlx, path,
			&game->player.width, &game->player.height);
	if (!img_ptr)
		ft_free_game(game, "Error en init images");
	free(path);
	return (img_ptr);
}

void	ft_init_images(t_game *game)
{
	game->floor.img_ptr = ft_set_images(game, FLOOR_XPM);
	game->player.img_ptr = ft_set_images(game, PLAYER_XPM);
	game->wall.img_ptr = ft_set_images(game, WALL_XPM);
	game->collectable.img_ptr = ft_set_images(game, COLLECTABLE_XPM);
	game->exit.img_ptr = ft_set_images(game, EXIT_XPM);
}

t_game	*ft_init_game(char *file)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free(game);
		exit(EXIT_FAILURE);
	}
	ft_init_game_props(game);
	ft_init_map(game, file);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_free_game(game, "MLX mal instanciado");
	game->mlx_win = mlx_new_window(game->mlx,
			game->map_width * 64, game->map_heigth * 64, "so_long");
	if (!game->mlx_win)
		ft_free_game(game, "MLX win mal instanciado");
	ft_init_images(game);
	ft_render_map(game);
	return (game);
}
