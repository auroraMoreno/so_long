/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:55:46 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/11 09:52:33 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_map_is_valid(char *joined_str)
{
    int i;
    // si hay algo que no sea un 1 rodeando
    // si hay algun char invalido 
    // when getting the width and height check if it's a rectangle 
    i = 0; 
    while(joined_str[i])
    {
        
        i++;
    }
    return(1);
}


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
    
}


void ft_get_height(char *joined_str, t_game *game)
{
    int i;
    
    //recorrer joined_str
    game->map_heigth = 0;
    i = 0;
    while(joined_str[i] != '\0')
    {
        // si disinto de 1, 
        if(joined_str[i] == '\n')
            game->map_heigth++;
        i++;
        
    }
}
