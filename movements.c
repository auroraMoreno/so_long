/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:16:33 by aumoreno          #+#    #+#             */
/*   Updated: 2024/10/03 12:15:06 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checkar tmb que se puede mover a ese cuadrado
// si es un muro no puede moverse 

/*
    function to validate si es
        muro 
        collectable 
    si el indice al que se quiere mover el personaje
    es muro, exit y tal se harán una serie  de comprobaciones 
    y se mandarán a distintas funciones
    si es muro no dejará avanzar (esto quizá lo dejamos fuera de la funcion)
    
*/
void ft_vaidate_move(t_game *game)
{
    
}

void ft_move_up(t_game *game)
{
    //solo toco la y 
    printf("%d\n",game->ghost.y_pos);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40) + 40, (game->ghost.y_pos * 40) + 40);
    printf("moving up");
}

void ft_move_down()
{
    
    printf("moving down");
}

void ft_move_left()
{
    printf("moving left");
}

void ft_move_right()
{
    printf("moving right");
}