/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_general_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:43:07 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/04 14:08:57 by aumoreno         ###   ########.fr       */
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
    int fd;
    char *joined_str;
    char *line; 
    // primero open el fichero 
    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        free(game);
        free(file);
        ft_putendl_fd("Error\n",2);
        exit(EXIT_FAILURE);
    }
    // luego tendremos que ir linea a linea 
    joined_str = ft_calloc(1, sizeof(char));
    if(!joined_str)
    {
        free(joined_str);
        free(game);
        ft_putendl_fd("Error\n",2);
        exit(EXIT_FAILURE);
    }
    //(podremos uusar el gnl i guess)
    line = get_next_line(fd);
    // si resulta que es un cuadrado, devolvemos error 
    while(line)
    {
        //join the line 
        //update line
    }
    close(fd);
    //process map: the function will get the l¡height and width
    //it will also check if the map is valid

    free(joined_str); //since we are using join inside the loop 
    
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