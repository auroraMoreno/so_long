/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:35:25 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/03 08:48:54 by aumoreno         ###   ########.fr       */
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
        ft_putendl_fd("Error\n",2);
        exit(EXIT_FAILURE);
    }
        
    // comprobar que es .ber 

    /*inicializamos game
        mlx y window
    */
   game = ft_init_mlx();
   
    // poner los hooks para cerrar ventana y tal 
    mlx_hook(game->mlx_win,17,1L<<17,ft_close_window,game);
    mlx_hook(game->mlx_win,3,1L<<1,ft_handle_key,game);
    // loop 
    mlx_loop(game->mlx);
    return (0);
   
}



// int main(int argc, char **argv)
// {
//     t_mlx_data *mlx_data;
//     t_img *bg; 
//     t_img_data *bg_data;
    
//     mlx_data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
//     if(!mlx_data)
//         free(mlx_data);   
//     bg = (t_img *)malloc(sizeof(t_img));
//     if(!bg)
//         free(bg);
//     bg_data = (t_img_data *)malloc(sizeof(t_img_data));
//     if(!bg_data)
//         free(bg_data);
    

//     // vamos a empezar por que se nos abra la window
//     mlx_data->mlx = mlx_init();
//     mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, 400, 300, "so_long");
    
//     // init img bg:
//     bg->path = "xpm/floor.xpm";
//     // pintar la imagen de fondo 
//     bg_data->img_ptr = mlx_xpm_file_to_image(mlx_data->mlx,bg->path,&bg->width,&bg->height);
//     bg_data->addr = mlx_get_data_addr(bg_data->img_ptr, &bg_data->bit_per_pixel, &bg_data->line_len, &bg_data->endian);
    
//     mlx_put_image_to_window(mlx_data->mlx_win, mlx_data->mlx, bg_data->img_ptr, 0 ,0);
    
//     // y vamos a poner y ya el hook de cerrar (luego lo movemos)
// 	mlx_hook(mlx_data->mlx_win,17,1L<<17,ft_close_window,mlx_data);
//     mlx_hook(mlx_data->mlx_win,3,1L<<1,ft_handle_key,mlx_data);
//     mlx_loop(mlx_data->mlx);
    
// }