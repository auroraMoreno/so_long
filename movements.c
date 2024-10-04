/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:16:33 by aumoreno          #+#    #+#             */
/*   Updated: 2024/10/04 12:20:50 by aumoreno         ###   ########.fr       */
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
//REPASAR ESTA FUNCION PARA ADD ERORRES Y DEMAS 
void ft_validate_move(t_game *game, int x, int y)
{
    if(game->map[x][y].value == '1')
        printf("u are hitting a wall");
    else if(game->map[x][y].value == 'E')
    {
        // si collectables es == 0 good to go   
        if(game->num_collect == 0)
            // ft_end_game(); // EXIT SUCCESS
            printf("YAY!! u can leaveee");
        else
            printf("no tienes todos los collectables u cant leave");
    }
    else if(game->map[x][y].value == 'C') //IMPORTANTE TMB CAMBIAR LA IMG A SUELO !!!
        game->num_collect--; // 
    
    // SI ES UN 0 GOOD TO GO so no need of like doing anything
    
}

//RECORDAR QUE AQUI X = LA ALTURA E Y LA ANCHURA ESTÁ MAL!!!!!
void ft_move_up(t_game *game)
{
    //solo toco la y 
    printf("%d\n",game->ghost.y_pos);
    printf("%d\n",game->ghost.x_pos);

    //comprobamos el siguiente char antes de hacer nada 
    //en este caso como es para subir hay que pasar el char de arriba
    // es decir la x se queda igual pero la y cambia
    ft_validate_move(game,game->ghost.x_pos, game->ghost.y_pos - 1);  
    // modificamos el alrededor, la posicion del fantasma 
    // y luego renderizamos de nuevo el mapa 
    game->ghost.y_pos -= 1;
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40), (game->ghost.y_pos * 40));
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