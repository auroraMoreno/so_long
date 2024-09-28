/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:35:25 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/28 18:59:51 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*ACUERDATE POR FAVOR DEL -WALL EN EL MAKEFILE*/

int ft_handle_key(int keycode, t_game *data)
{
    if(keycode == 65307)
        ft_close_window(data);
    return (0);
}

int ft_close_window(t_game *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}


int main(int argc, char **argv)
{
    t_game  *game;
    
    // comprobamos que hay 2 args 
    if(argc != 2)
    {
        ft_putendl_fd("Error no args\n",2);
        exit(EXIT_FAILURE);
    }
        
    // comprobar que es .ber 

    /*inicializamos game
        mlx y window
    */
   // le pasamos el fichero .ber 
   game = ft_init_game(argv[1]); // checks map, inits mlx and images, render
    // poner los hooks para cerrar ventana y tal 
    mlx_hook(game->mlx_win,17,1L<<17,ft_close_window,game);
    mlx_hook(game->mlx_win,3,1L<<1,ft_handle_key,game);
    // loop 
    mlx_loop(game->mlx);
    return (0);
   
}
