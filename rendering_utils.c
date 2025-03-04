/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:06:42 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/04 10:03:25 by aumoreno         ###   ########.fr       */
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
