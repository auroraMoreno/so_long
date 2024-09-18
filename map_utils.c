/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:55:46 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/18 11:54:53 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_map_characters(t_game *game, char *joined_str)
{
    // too many vars probs
    int i;
    int innit_p;
    int exit;
    int coll;
    int floor;
    //si el int i tiene una E;P;C;1
    i = 0; 
    innit_p = 0;
    exit = 0;
    while(joined_str[i] != '\0')
    {
        if(joined_str[i] == '\n')
            continue;
        if(joined_str[i] != 'P' || joined_str[i] != 'E' || joined_str[i] != 'C' || joined_str[i] != '1')
        {
            free(joined_str);
            ft_free_game(game, "Characteres inválidos");
        }
        if(joined_str[i] == 'P')
            innit_p++;
        if(joined_str[i] == 'E')
            exit++;
        if(joined_str[i] == 'C')
            coll++;
        if(joined_str[i] == '1')
            floor++;
        i++;
    }
    if(innit_p != 1 || exit != 1 || floor < 1 || coll < 1)
    {
        free(joined_str);
        ft_free_game(game, "Invalid init position");
    }
    // si hay un char que sea distinto de, free joined and game
    return(1);
}
    

static int ft_issurrounded(t_game *game, int i)
{
    if(i < game->map_width
        || i > (game->map_heigth - 1) * (game->map_width + 1) // para la ultima linea
        || i % (game->map_width + 1) == 0 // para el borde de la izq
        || i % (game->map_width + 1) == game->map_width - 1 // para el borde de la derecha
    )
        return (0);
        
    return (1);
}


int ft_map_is_valid(t_game *game, char *joined_str)
{
    int i;
    // si hay algo que no sea un 1 rodeando
    // si hay algun char invalido 
    // when getting the width and height check if it's a rectangle 
    i = -1; //empezar en -1 por \n 
    while(joined_str[++i] != 0)
    {
        // si me encuentro con un \n sigo ???
        if(joined_str[i] == '\n')
            continue;
        i++;
        //comprobar si está rodeado de 1
        // si no está surrounded then devolvemos 0 si no 1
        if(ft_issurrounded(game, i) == 0)
        {
            free(joined_str);
            ft_free_game(game,"El mapa esta mal rodeado");
        }  
    }
    //comprobar que están todos los P,E,C,0 + no haya chars raros 
    ft_check_map_characters(game, joined_str);
    // check tmb que no sea un rectangulo 
    if(game->map_heigth == game->map_width)
        return (0);
    return(1);
}

// cambiar esto que en vez de void sea un int y asignarlo a map_width
void ft_get_width(char  *joined_str, t_game *game)
{
    int i;
    
    game->map_width = 0;
    i = 0;
    while(joined_str[i] != '\0')
    {
        if(joined_str[i] != '\n')
            game->map_width++;
        i++;
    }
    if(game->map_width == 0 || joined_str[game->map_width] == 0)
        ft_free_game(game, "Error en el cálculo del width"); // esto lo cambiaré a qe devuelva 0 
    
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
        if(current_line_len > 0)
            game->map_heigth++;
        
        //comprobar si el current_line_len (q es width) es igual al width que hay marcado
        //will probably move this from here at some point but it is what it is for now
        // si esto da error devolveré 0 pero for now we will just free mem
        if(game->map_width != current_line_len)
            ft_free_game(game, "El width no coincide");
        // si disinto de 1, 
        if(joined_str[i] == '\n')
            game->map_heigth++;
        i++;
        
    }
}
