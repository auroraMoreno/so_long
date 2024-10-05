/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:18 by aumoreno          #+#    #+#             */
/*   Updated: 2024/10/05 18:57:05 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    for error methods and freeing memory
*/

#include "so_long.h"

// ARREGLAR ESTE MÉTODO PARA QUE SEA MÁS ABSTRACTO!!!
void ft_free_game(t_game *game, char *msg)
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
        ft_print_error(msg);
    }
}

void ft_end_game(t_game *game)
{
    if(game)
    {
        if(game->floor.img_ptr)
            mlx_destroy_image(game->mlx, game->floor.img_ptr); 
        mlx_destroy_window(game->mlx, game->mlx_win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        free(game);
        printf("Yay!! u won!!");
        exit(EXIT_SUCCESS);
    }
}

void ft_print_error(char *error)
{
    ft_putendl_fd(error,2);
    exit(EXIT_FAILURE);
}