/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_general_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:43:07 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/03 11:24:56 by aumoreno         ###   ########.fr       */
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


void ft_init_map(t_game *game, void *file)
{
    // primero open el fichero 

    // luego tendremos que ir linea a linea 
    //(podremos uusar el gnl i guess)

    // si resulta que es un cuadrado, devolvemos error 
    
    
}


//inicializa el juego 
t_game *ft_init_mlx(void **file)
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
    //inicializar el map (.ber) (initialize map)
    ft_init_map(game,file);
   /*
    inicializar las img
    de momento solo el suelo 
   */
    game->floor.img_ptr = ft_init_images(game);
    //mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr,110,110);
        
    //renderizar la imagen en base al mapa .ber 

    /*
        de momento va a pintar solo el suelo pero luego pintará 
        los collectables y demás
    */
   //AQUI SOLO PINTA EL MAPA
    ft_render_map(game); 

    // devolver el new game
    return (game);
     
}