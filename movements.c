/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:16:33 by aumoreno          #+#    #+#             */
/*   Updated: 2024/10/05 19:49:47 by aumoreno         ###   ########.fr       */
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
int ft_validate_move(t_game *game, int x, int y)
{
    if(game->map[y][x].value == '1')
       return (0); // return 0
    else if(game->map[y][x].value == 'E')
    {
        // si collectables es == 0 good to go   
        if(game->num_collect == 0)
            ft_end_game(game); // EXIT SUCCESS
            //printf("YAY!! u can leaveee\n"); // win game
        else
            //printf("no tienes todos los collectables u cant leave\n"); // return 0
            return (0);
    }
    else if(game->map[y][x].value == 'C')
    {
        game->num_collect--; // return 1 y modificamos las pos ?? 
        return (1);
    } //IMPORTANTE TMB CAMBIAR LA IMG A SUELO !!!
    
    // SI ES UN 0 GOOD TO GO so no need of like doing anything
    return (1); 
    
}

// REVISAR MUY BIEN ESTA FUNCION!!!! 
void ft_change_value(t_game *game, int old_x, int old_y)
{
    if(game->map[game->ghost.y_pos][old_x].value == 'C')
    {
        printf("soy un collectable");
        mlx_destroy_image(game->mlx, game->collectable.img_ptr);
    }
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40), (game->ghost.y_pos * 40));
    // donde estaba antes el fantasma ponemos el suelo
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, (old_x * 40), (old_y * 40));
    game->map[old_y][old_x].value = '0'; 
    game->map[game->ghost.y_pos][old_x].value = 'P';
}

//RECORDAR QUE AQUI X = LA ALTURA E Y LA ANCHURA ESTÁ MAL!!!!!
void ft_move_up(t_game *game)
{
    int old_y_pos; 
    //solo toco la y 
    // printf("%d\n",game->ghost.y_pos);
    // printf("%d\n",game->ghost.x_pos);

    //comprobamos el siguiente char antes de hacer nada 
    //en este caso como es para subir hay que pasar el char de arriba
    // es decir la x se queda igual pero la y cambia

    if(ft_validate_move(game,game->ghost.x_pos, game->ghost.y_pos - 1) == 1)
    {
        // si el move es valido actualizamos la pos del fantasma:
        // modificamos el alrededor, la posicion del fantasma 
        old_y_pos = game->ghost.y_pos;
        game->ghost.y_pos -= 1; //IMPORTANTISIMO CAMBIAR EL VALUE EN LA COORDENADA DEL MAPA PORQ YA NO ES POS INICIAL SABES 
        //SI VUELVE A PASAR POR DONDE UN COLLECTABLE Y SIGUE MARCANDO EL VALUE DEL MAPA QUE ES UN COLL ESTÁ MAL!!!!!
        //mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40), (game->ghost.y_pos * 40));
        // donde estaba antes el fantasma ponemos el suelo
        //mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, (game->ghost.x_pos * 40), (old_y_pos * 40));
        ft_change_value(game, game->ghost.x_pos, old_y_pos);
        game->steps_counter++;
        printf("Steps: %d\n",game->steps_counter); 
    }
    // en el mapa hay que actualizar tmb: HABRÁ QUE HACEER LO MISMO PARA COLECTABLES 
    //game->map[old_y_pos][game->ghost.x_pos].value = '0'; 
    //game->map[game->ghost.y_pos][game->ghost.x_pos].value = 'P'; // podemos hacer una funcion ft_change_value
}

void ft_move_down(t_game *game)
{
    int old_y_pos; 
    //solo toco la y 
    // printf("%d\n",game->ghost.y_pos);
    // printf("%d\n",game->ghost.x_pos);

    //comprobamos el siguiente char antes de hacer nada 
    //en este caso como es para subir hay que pasar el char de arriba
    // es decir la x se queda igual pero la y cambia
    if(ft_validate_move(game,game->ghost.x_pos, game->ghost.y_pos + 1) == 1) 
    {
        // modificamos el alrededor, la posicion del fantasma 
        old_y_pos = game->ghost.y_pos;
        game->ghost.y_pos += 1; //IMPORTANTISIMO CAMBIAR EL VALUE EN LA COORDENADA DEL MAPA PORQ YA NO ES POS INICIAL SABES 
        ft_change_value(game,game->ghost.x_pos, old_y_pos);
        game->steps_counter++;
        printf("Steps: %d\n",game->steps_counter); 
    } 
    // //SI VUELVE A PASAR POR DONDE UN COLLECTABLE Y SIGUE MARCANDO EL VALUE DEL MAPA QUE ES UN COLL ESTÁ MAL!!!!!
    // mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40), (game->ghost.y_pos * 40));
    // // donde estaba antes el fantasma ponemos el suelo
    // mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, (game->ghost.x_pos * 40), (old_y_pos * 40));
    // // en el mapa hay que actualizar tmb: HABRÁ QUE HACEER LO MISMO PARA COLECTABLES 
    // game->map[old_y_pos][game->ghost.x_pos].value = '0';
    // game->map[game->ghost.y_pos][game->ghost.x_pos].value = 'P';
}

// a 
void ft_move_left(t_game *game)
{
    int old_x_pos; 
    //solo toco la y 
    // printf("%d\n",game->ghost.y_pos);
    // printf("%d\n",game->ghost.x_pos);

    //comprobamos el siguiente char antes de hacer nada 
    //en este caso como es para subir hay que pasar el char de arriba
    // es decir la x se queda igual pero la y cambia
    ft_validate_move(game,game->ghost.x_pos - 1, game->ghost.y_pos);  
    // modificamos el alrededor, la posicion del fantasma 
    // y luego renderizamos de nuevo el mapa 
    old_x_pos = game->ghost.x_pos;
    game->ghost.x_pos -= 1; //IMPORTANTISIMO CAMBIAR EL VALUE EN LA COORDENADA DEL MAPA PORQ YA NO ES POS INICIAL SABES 
    //SI VUELVE A PASAR POR DONDE UN COLLECTABLE Y SIGUE MARCANDO EL VALUE DEL MAPA QUE ES UN COLL ESTÁ MAL!!!!!
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40), (game->ghost.y_pos * 40));
    // donde estaba antes el fantasma ponemos el suelo
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, (old_x_pos * 40), (game->ghost.y_pos * 40));
    // en el mapa hay que actualizar tmb: HABRÁ QUE HACEER LO MISMO PARA COLECTABLES 
    game->map[game->ghost.y_pos][old_x_pos].value = '0'; // donde estaba antes el fantasma ahora hay suelo
    game->map[game->ghost.y_pos][game->ghost.x_pos].value = 'P'; // donde antes habia suelo ahora fantasma
    game->steps_counter++;
    printf("Steps: %d\n",game->steps_counter); 
}

// d
// la x aqui representa al eje y (cambiarlo)
// y la y al eje x 
void ft_move_right(t_game *game)
{
    int old_x_pos; 
    //solo toco la y 
    // printf("%d\n",game->ghost.y_pos);
    // printf("%d\n",game->ghost.x_pos);

    //comprobamos el siguiente char antes de hacer nada 
    //en este caso como es para subir hay que pasar el char de arriba
    // es decir la x se queda igual pero la y cambia
    ft_validate_move(game,game->ghost.x_pos + 1, game->ghost.y_pos);  
    // modificamos el alrededor, la posicion del fantasma 
    // y luego renderizamos de nuevo el mapa 
    old_x_pos = game->ghost.x_pos;
    game->ghost.x_pos += 1; //IMPORTANTISIMO CAMBIAR EL VALUE EN LA COORDENADA DEL MAPA PORQ YA NO ES POS INICIAL SABES 
    //SI VUELVE A PASAR POR DONDE UN COLLECTABLE Y SIGUE MARCANDO EL VALUE DEL MAPA QUE ES UN COLL ESTÁ MAL!!!!!
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 40), (game->ghost.y_pos * 40));
    // donde estaba antes el fantasma ponemos el suelo
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, (old_x_pos * 40), (game->ghost.y_pos * 40));
    // printf("printing new pos\n");
    // printf("%d\n",game->ghost.y_pos);
    // printf("%d\n",game->ghost.x_pos);
    // en el mapa hay que actualizar tmb: HABRÁ QUE HACEER LO MISMO PARA COLECTABLES 
    game->map[game->ghost.y_pos][old_x_pos].value = '0'; // donde estaba antes el fantasma ahora hay suelo
    game->map[game->ghost.y_pos][game->ghost.x_pos].value = 'P'; // donde antes habia suelo ahora fantasma
    game->steps_counter++;
    printf("Steps: %d\n",game->steps_counter); 
}