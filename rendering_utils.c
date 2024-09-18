/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:06:42 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/09 12:23:17 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_render_map(t_game *game)
{
    int x; // la anchura
    int y; // la altura

    //calcular el tamaño del mapa
    // para saber en base a eso cuantos suelos tenemos que pintar
    // hay que comprobar si el mapa es un cuadrado lanzar un error!! 
    y = 0;
    while(y <= game->map_heigth)
    {
        x = 0;
        while(x <= game->map_width)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr,110,110);
            x++;
        }
        y++;
    }
    
}
