/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:18 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/05 10:49:43 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    for error methods and freeing memory
*/

#include "so_long.h"

// ARREGLAR ESTE MÉTODO PARA QUE SEA MÁS ABSTRACTO!!!
// QUE SE PUEDA USAR TANTO SI GANO COMO SI PIERDO!! 
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
    int i;
    if(game)
    {
        if(game->ghost.img_ptr)
            mlx_destroy_image(game->mlx, game->ghost.img_ptr); 
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

void ft_print_error(char *error)
{
    ft_putendl_fd(error,2);
    exit(EXIT_FAILURE);
}