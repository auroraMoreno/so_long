/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:16:33 by aumoreno          #+#    #+#             */
/*   Updated: 2024/10/04 11:16:54 by aumoreno         ###   ########.fr       */
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
    
    //vamos a pasarle a la funcion el siguiente char 
    // y con el value vamos a ver qué es, 
*/
// void ft_vaidate_move(t_game *game)
// {
    
// }

//RECORDAR QUE AQUI X = LA ALTURA E Y LA ANCHURA ESTÁ MAL!!!!!
void ft_move_up(t_game *game)
{
    //solo toco la y 
    printf("%d\n",game->ghost.y_pos);
    printf("%d\n",game->ghost.x_pos);

    //

    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40), (game->ghost.y_pos * 40) + 40);
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