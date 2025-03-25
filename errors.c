/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:18 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/25 22:45:14 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free_game(t_game *game, char *msg)
{
    if(game)
    {
        if(game->floor.img_ptr)
            mlx_destroy_image(game->mlx, game->floor.img_ptr); 
        if(game->player.img_ptr)
            mlx_destroy_image(game->mlx, game->player.img_ptr);
        if(game->wall.img_ptr)
            mlx_destroy_image(game->mlx, game->wall.img_ptr);
        if(game->collectable.img_name)
            mlx_destroy_image(game->mlx, game->collectable.img_ptr);
        if(game->exit.img_name)
            mlx_destroy_image(game->mlx, game->exit.img_ptr);
        
        mlx_destroy_window(game->mlx, game->mlx_win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        free(game);
        ft_print_error(msg);
    }
}

void ft_end_game(t_game *game)
{
    int i;
    printf("fin.\n");
    if(game)
    {
        if(game->player.img_ptr)
            mlx_destroy_image(game->mlx, game->player.img_ptr); 
        if(game->collectable.img_ptr)
            mlx_destroy_image(game->mlx, game->collectable.img_ptr); 
        if(game->floor.img_ptr)
            mlx_destroy_image(game->mlx, game->floor.img_ptr); 
        if(game->wall.img_ptr)
            mlx_destroy_image(game->mlx, game->wall.img_ptr); 
        if(game->exit.img_ptr)
            mlx_destroy_image(game->mlx, game->exit.img_ptr);

        i = 0; 
        while(i < game->map_heigth)
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
        mlx_destroy_window(game->mlx, game->mlx_win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        free(game);
        printf("Yay!! u won!!");
        exit(EXIT_SUCCESS);
    }
}

void	ft_free_joined_line(char *joined_str, t_game *game, char *msg)
{
	free(joined_str);
	free(game);
	ft_print_error(msg);
}

void	free_map_copy(char **map_copy, int i)
{
	while (--i >= 0)
		free(map_copy[i]);
	free(map_copy);
}

void	ft_print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}
