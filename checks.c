/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:30:49 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/08 13:53:02 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_map_characters(t_game *game, char *joined_str, int p)
{
    if(joined_str[p] == 'P')
        game->counter.n_player++;
    else if(joined_str[p] == 'E')
        game->counter.n_exits++;
    else if(joined_str[p] == 'C')
        game->num_collect++;
    else if(joined_str[p] == '0')
        game->counter.n_floor++;
    return(1);
}
    

static int ft_issurrounded(t_game *game, int i)
{
    if(i < game->map_width
        || i > (game->map_heigth - 1) * (game->map_width + 1) // para la ultima linea
        || i % (game->map_width + 1) == 0 // para el borde de la izq
        || i % (game->map_width + 1) == game->map_width - 1 // para el borde de la derecha
    )
        return (1);
        
    return (0);
}

// TODO: VOID
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
        //comprobar si está rodeado de 1
        // si no está surrounded then devolvemos 0 si no 1
        /*CHECK IF MAP IS A RECTANGLE */
        if(ft_issurrounded(game, i))
        {
            if(joined_str[i] != '1')
            {
                free(joined_str);
                //ft_free_game(game,"El mapa esta mal rodeado");
                free(game);
                ft_putendl_fd("Error\nMap must be fully surrounded by walls.", 2);
                exit(EXIT_FAILURE);
            }
        }        
        ft_check_map_characters(game, joined_str, i);
    }

    //add here : || !ft_valid_route(game)
    if(game->counter.n_floor == 0)
    {
        free(joined_str);
        free(game);
        ft_putendl_fd("Error\nNo valid route.", 2); //quizas cambiar esto a que check map chars no return nada
        //y haga todo esto pero en check map or something 
        exit(EXIT_FAILURE); 
    }

    if(game->counter.n_player > 1 || game->counter.n_player == 0)
    {
        free(joined_str);
        free(game);
        ft_putendl_fd("Error\nMap with wrong props.", 2); //quizas cambiar esto a que check map chars no return nada
        //y haga todo esto pero en check map or something 
        exit(EXIT_FAILURE);
    }   
    if(game->counter.n_exits > 1 || game->counter.n_exits == 0)
    {
        free(joined_str);
        free(game);
        ft_putendl_fd("Error\nMap with wrong props.", 2); //quizas cambiar esto a que check map chars no return nada
        //y haga todo esto pero en check map or something 
        exit(EXIT_FAILURE);
    }     
    if(game->num_collect == 0)
    {
        free(joined_str);
        free(game);
        ft_putendl_fd("Error\nMap with wrong props.", 2); //quizas cambiar esto a que check map chars no return nada
        //y haga todo esto pero en check map or something 
        exit(EXIT_FAILURE);   
    }
    
    // check tmb que no sea un rectangulo 
    if(game->map_heigth == game->map_width)
        return (0);
    return(1);
}


int ft_is_ber(char *str)
{
    //recorrer str 
    int i = 0;
    while(str[i])
        i++;
    
    // puedo usar el suubstr para coger hasta el . 
    i--;
    while(str[i] != '.' && str[i])
        i--;
    //si i es 0 return (0);
    if(i <= 0)
        return(0);
    // la estructura tiene que ser: nombre_fichero.ber, teniendo en cunenta que puede tener guiones y chars especiales
     
    //empezando desde el final, mientras sea != . rotamos 
    // si nnunnca lllega a ser  != . entonnces returnn 0 porq esta mal

    // si si llega al punto vamos a partir con substr desde donde está el punto hasta el final 
    char *sub_str = ft_substr(str,i,5);
    //y ahi con strncpm si .ber entonces guay, si no F 
    if(ft_strncmp(sub_str, ".ber", 5) == 0)
    {
        //printf("entro");
        free(sub_str);
        return (1);
    }
    free(sub_str);
    // esto es indeppendiente de si el mapa es válido o no, puede ser un .ber y que luegoo el mapa esté mal 
    return (0);
}
