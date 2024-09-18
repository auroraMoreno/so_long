/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_general_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 07:43:07 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/18 11:53:37 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funcion para unir todo el mapa en una misma linea 
// y asi sea más facil calcular el width y el height
// maybe use it to parse too
static int ft_join_map_line(char *line, char **joined_str)
{
    char *aux;
    aux = ft_strjoin(*joined_str,line);
    //si da fallo we free line and joined_str
    //devolvemos 0
    if(!aux)
    {
        free(*joined_str);
        free(line);
        return (0);
    }
    //si todo va bien devolvemos 1 
    free(*joined_str);
    free(line);
    *joined_str = aux;
    //si está vacía: 
    if(!*joined_str)
        return(0);
    return (1);
}

static void ft_process_map_line(char *joined_str, t_game *game)
{
    // hay que obtener el width and height primero 
    // porq lo vamos a usar en el map is valid 
    //calculate width and height
    ft_get_width(joined_str, game);
    ft_get_height(joined_str, game);
    
    //check if map is valid
    if(ft_map_is_valid(game, joined_str) == 0)
        ft_free_game(game, "El mapa no es válido");
    

    // de momento returns int 1 si todo guay y 0 si algo va mal  
}

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
        ft_putendl_fd("Error en el suelo",2);
    return img_ptr;
}


void ft_init_map(t_game *game, char *file)
{
    int fd;
    char *joined_str;
    char *line; 
    // primero open el fichero 
    fd = open(file, O_RDONLY);
    if(fd == -1)
        ft_free_game(game, "Error en fd");
    // luego tendremos que ir linea a linea 
    joined_str = ft_calloc(1, sizeof(char));
    if(!joined_str)
        ft_free_game(game, "Error en calloc");
    //(podremos uusar el gnl i guess)
    line = get_next_line(fd);
    // si resulta que es un cuadrado, devolvemos error 
    while(line)
    {
        //join the line 
        if(ft_join_map_line(line,&joined_str) == 0)
            // SI RETURNS 0 ESQ ESTÁ MAL 
            ft_free_game(game, "Error en el joinmapline");
        //update line
        line = get_next_line(fd);
    }
    close(fd);
    //process map: the function will get the line height and width
    //it will also check if the map is valid
    ft_process_map_line(joined_str, game);
    free(joined_str); //since we are using join inside the loop 
    
}


//inicializa el juego 
t_game *ft_init_mlx(char *file)
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
    ft_init_map(game,file); // ya tenemos el width y height
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