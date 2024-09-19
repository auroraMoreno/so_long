/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:18 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/19 11:09:06 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    for error methods and freeing memory
*/

#include "so_long.h"

void ft_free_game(t_game *game, char *error)
{
    //add destroy image for the rest of images
    if(game)
    {
        if(game->floor.img_ptr)
            mlx_destroy_image(game->mlx, game->floor.img_ptr); 
        mlx_destroy_window(game->mlx, game->mlx_win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        free(game);
        ft_print_error(error);
    }
}

void ft_print_error(char *error)
{
    ft_putendl_fd(error,2);
    exit(EXIT_FAILURE);
}