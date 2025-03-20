/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:55:46 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/20 17:41:14 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * metodo que dependiendo de si es una e,0,p o c 
 * va a pintar una imagen u otra
 */
// ARREGLAR QUE AQUI LA X DEBERIA SER EL ANCHO Y NO AL REVES!! 
void ft_select_image(t_game *game, char pos, int x, int y)
{
    //mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, y * 40, x * 40);
    if(pos == 'P')
    {
        //esto habra que moverlo de sitio
        //inicializamos al ghost con sus coordenadas iniciales
        // esto nos permite que luego en move cogemos su pos y sumamos 
        game->ghost.x_pos = y;
        game->ghost.y_pos = x; // tengo que coger el indice y moverlo al siguiente ??? 
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, y * 64, x * 64); 
    }
    else  if(pos == 'C')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable.img_ptr, y * 64, x * 64);
    else if(pos == 'E')
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit.img_ptr, y * 64, x * 64);
    else if(pos == '1')
         mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.img_ptr, y * 64, x * 64);
}

void ft_render_map(t_game *game)
{
    int x; // la altura
    int y; // la anchura

    //calcular el tamaño del mapa
    // para saber en base a eso cuantos suelos tenemos que pintar
    // hay que comprobar si el mapa es un cuadrado lanzar un error!! 
    x = 0;
    while(x < game->map_heigth)
    {
        y = 0;
        while(y < game->map_width)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr,(y * 64), (x * 64));
            ft_select_image(game, game->map[x][y].value, x, y);
            // if(game->map[x][y].value == '1')
            // {
            //     mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.img_ptr,(y * 64), (x * 64)); // ***
            // }
            // else if(game->map[x][y].value != '1')
            // {
            //     ft_select_image(game, game->map[x][y].value, x, y); // hay que guardar las coordenadas jeje para saber donde pintar las cosas 
            // }
            y++;
        }
        x++;
    }
    
}

// cambiar esto que en vez de void sea un int y asignarlo a map_width
void ft_get_width(char  *joined_str, t_game *game)
{

    game->map_width = 0;
    while(joined_str[game->map_width] && joined_str[game->map_width] != '\n')
        game->map_width++;
    if(game->map_width == 0 || joined_str[game->map_width] == 0)
    {
        free(joined_str);
        free(game);
        ft_putendl_fd("Error\nThe .ber file is empty.", 2); //quizas cambiar esto a que check map chars no return nada
        //y haga todo esto pero en check map or something 
        exit(EXIT_FAILURE);  
        //ft_free_game(game, "Error en el cálculo del width"); // esto lo cambiaré a qe devuelva 0 
    }
}

// cambiar esto que en vez de void sea un int y asignarlo a map_height 
void ft_get_height(char *joined_str, t_game *game)
{
    int i;
    int current_line_len;
    
    //recorrer joined_str
    game->map_heigth = 0;
    i = 0;
    while(joined_str[i] != '\0')
    {
        current_line_len = 0;
        while(joined_str[i] != '\0' && joined_str[i] != '\n')
        {
            current_line_len++;
            i++;
        }

        //aqui ya ha llegado al final de la \n asi que podemos sumarle 1 al height
        // ya que solo ha entrado al bucle anterior si habia un char
        // igualmente habrá que checkar si el char leido es 1!!!! 
        // literal this does't make sense i fear
        if(current_line_len > 0)
            game->map_heigth++;
        
        //comprobar si el current_line_len (q es width) es igual al width que hay marcado
        //will probably move this from here at some point but it is what it is for now
        // si esto da error devolveré 0 pero for now we will just free mem 
        if(game->map_width != current_line_len)
        {
            //ft_free_game(game, "El width no coincide");
            free(joined_str);
            free(game);
            ft_putendl_fd("Error.\nMap is not a rectangle.", 2);
            exit(EXIT_FAILURE);
        } 
        // si disinto de 1, 
        if(joined_str[i] == '\n')
            i++;
        
    }

}
