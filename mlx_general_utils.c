/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_general_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:43:07 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/03 09:15:51 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *ft_init_images(t_game *game)
{
    //init the floor
    char *path;
    void *img_ptr;
    int px;

    px = 110;
    path = "xpm/floor.xpm";
    img_ptr = mlx_xpm_file_to_image(game->mlx,path,&px,&px);
    if(!img_ptr)
    {
        ft_putendl_fd("Error en el suelo",2);
    }
    return img_ptr;
}

t_game *ft_init_mlx()
{
    t_game  *game;

    //hacemos  malloc
    game = (t_game *)malloc(sizeof(t_game));
    //comprobar que ha hecho el alloc
    if(!game)
    {
        free(game);
        exit(EXIT_FAILURE); //REVISAR**
    }
    /*
        inicializar el mlx y la win
        no se si esto es necesario aqui
    */
   game->mlx = mlx_init();
   game->mlx_win = mlx_new_window(game->mlx,750,600,"so_long_aurora");

   /*
    inicializar las img
    de momento solo el suelo 
   */
    game->floor.img_ptr = ft_init_images(game);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr,110,110);
    // devolver el new game
    return (game);
     
}