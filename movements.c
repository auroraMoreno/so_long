/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:16:33 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/24 10:19:19 by aumoreno         ###   ########.fr       */
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
        {
           //ft_change_value(game, game->ghost.x_pos, game->ghost.y_pos);            
           ft_end_game(game); // EXIT SUCCESS
            //printf("YAY!! u can leaveee\n"); // win game
            return (1);
        }
        else
        {
            // hacer aqui la comprobacion y las movidas y como va a devolver 0 se va a saltar el resto del código!!
            printf("no tienes todos los collectables u cant leave\n"); // return 0
            //if x pos es igual a ghost pos entonces tocar la y porq se ha modificado la y si no tocar la x 
            if(x == game->ghost.x_pos)
            {
                // si la y es menor a y pos entonces restar
                if(game->ghost.y_pos > y) // esto es que hemos restado so we moved up 
                    ft_skip_exit(game, x, y - 1);
                else if (game->ghost.y_pos < y)
                    // si la y es mayor a y post entonces sumar
                    ft_skip_exit(game, x, y + 1); // we moved down
            }
            else if (y == game->ghost.y_pos)
            {
                if(game->ghost.x_pos > x)
                    ft_skip_exit(game, x - 1, y); //we moved left
                else if(game->ghost.y_pos < x)
                    ft_skip_exit(game, x + 1, y); // we moved right 
            }
                
            return (0);
        }
    }
    else if(game->map[y][x].value == 'C')
    {
        game->num_collect--; // return 1 y modificamos las pos ?? 
        printf("%d",game->num_collect);
        return (1);
    } //IMPORTANTE TMB CAMBIAR LA IMG A SUELO !!!
    
    // SI ES UN 0 GOOD TO GO so no need of like doing anything
    return (1); 
    
}

// handle exit: 
/*
    necesito que:
        - cuando se encuentre una E pueda hacer pos + 2 para que salte al siguiente cuadrado 
        - pero hay que tener en cuenta que si pos + 2 es NULL (se sale del width o del heigh) que no deje hacerlo
        - si se puede pues actualizar la pos a pos + 2 y habrá que gestionar las imagenes ? 
            - las imagenes serás igual que en change value: donde haya suelo (0) irá P  y donde habia antes P irá suelo
            con la diferencia de que será con - 2 y con + 2? 
*/
void ft_skip_exit(t_game *game, int x, int y)
{
        int old_x;
        int old_y; 
       /*poner al ghost en las coordenada x,y */
       //tener en cuenta que si pos + 2 es NULL (se sale del width o del heigh) que no deje hacerlo
       // la x es el width y la Y es el height 
       // tmb si es una pared sabes 
       // quizas esto tenga que ser && y no ||
       if(game->map[y][x].value && game->map[y][x].value != '1'
        && y >= 0 && x >= 0 
        && y <= game->map_heigth && x <= game->map_width)
       {
        // le dejamos moverse 
            // si el value es un collectable gestionamos
            if(game->map[y][x].value == 'C')
                game->num_collect--;
            //cambiamos el x,y a P y el P a suelo 
            old_x = game->ghost.x_pos;
            old_y = game->ghost.y_pos;
            game->ghost.y_pos = y;
            game->ghost.x_pos = x;
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 64), (game->ghost.y_pos * 64));
            // donde estaba antes el fantasma ponemos el suelo: 
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, (old_x * 64), (old_y * 64)); // chungo tengo que pensar esto 
            game->map[game->ghost.y_pos][game->ghost.x_pos].value = '0'; 
            game->map[y][x].value = 'P';
       }
}

// REVISAR MUY BIEN ESTA FUNCION!!!! 
void ft_change_value(t_game *game, int old_x, int old_y)
{
    //tengoque usar las que ya tiene el fantasma porq ya habré actu la pos del fantasma pero no habré cambiado aun el valor
    if(game->map[game->ghost.y_pos][game->ghost.x_pos].value == 'C')
    {
        printf("soy un collectable");
        //mlx_destroy_image(game->mlx, game->collectable.img_ptr);
    }
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ghost.img_ptr, (game->ghost.x_pos * 64), (game->ghost.y_pos * 64));
    // donde estaba antes el fantasma ponemos el suelo: 
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img_ptr, (old_x * 64), (old_y * 64));
    game->map[old_y][old_x].value = '0'; 
    game->map[game->ghost.y_pos][old_x].value = 'P';
}

//RECORDAR QUE AQUI X = LA ALTURA E Y LA ANCHURA ESTÁ MAL!!!!!
void ft_move_up(t_game *game)
{
    int old_y_pos; 
    
    if(ft_validate_move(game,game->ghost.x_pos, game->ghost.y_pos - 1) == 1)
    {
        old_y_pos = game->ghost.y_pos;
        game->ghost.y_pos -= 1; 
        ft_change_value(game, game->ghost.x_pos, old_y_pos);
        game->steps_counter++;
        printf("Steps: %d\n",game->steps_counter); 
    }
}

void ft_move_down(t_game *game)
{
    int old_y_pos; 
    //solo toco la y 
    if(ft_validate_move(game,game->ghost.x_pos, game->ghost.y_pos + 1) == 1) 
    {
        old_y_pos = game->ghost.y_pos;
        game->ghost.y_pos += 1;
        ft_change_value(game,game->ghost.x_pos, old_y_pos);
        game->steps_counter++;
        printf("Steps: %d\n",game->steps_counter); 
    } 
}

// a 
void ft_move_left(t_game *game)
{
    int old_x_pos; 
    //solo toco la x
    if(ft_validate_move(game,game->ghost.x_pos - 1, game->ghost.y_pos) == 1)
    {
        // modificamos el alrededor, la posicion del fantasma 
        old_x_pos = game->ghost.x_pos;
        game->ghost.x_pos -= 1; //IMPORTANTISIMO CAMBIAR EL VALUE EN LA COORDENADA DEL MAPA PORQ YA NO ES POS INICIAL SABES 
        ft_change_value(game,old_x_pos,game->ghost.y_pos);
        game->steps_counter++;
        printf("Steps: %d\n",game->steps_counter); 
    }  
}

// d
void ft_move_right(t_game *game)
{
    int old_x_pos; 
    //solo toco la x
    if(ft_validate_move(game,game->ghost.x_pos + 1, game->ghost.y_pos) == 1)
    {
        // modificamos el alrededor, la posicion del fantasma 
        old_x_pos = game->ghost.x_pos;
        game->ghost.x_pos += 1; //IMPORTANTISIMO CAMBIAR EL VALUE EN LA COORDENADA DEL MAPA PORQ YA NO ES POS INICIAL SABES 
        ft_change_value(game, old_x_pos, game->ghost.y_pos);
        game->steps_counter++;
        printf("Steps: %d\n",game->steps_counter); 
    }  
}