/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:26:59 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/03 11:20:45 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"


typedef struct s_img {
    void *img_ptr;
    char *addr;
    void *img_name;
    int   width;
    int   height;
    char  *path;
    int bit_per_pixel;
    int line_len;
    int endian;
    int x;
    int y;
} t_img;

typedef struct s_game_data
{
    void *mlx;
    void *mlx_win; 
    t_img floor;
    t_img wall; 
    // poner aqui el mapa 
    t_map map; 
    int   map_heigth;
    int   map_width;
    
}t_game;

typedef struct  s_map
{
    int x;
    int y;
    
}t_map;


int ft_handle_key(int keycode, t_game *data);
int ft_close_window(t_game *data);
t_game *ft_init_mlx();
void *ft_init_images(t_game *game);
void ft_init_map(t_game game, void *file);
void ft_render_map(t_game *game);


// typedef struct s_img_data {
//     void *img_ptr;
//     char *addr;
//     int bit_per_pixel;
//     int line_len;
//     int endian;
//     //img_data data;
// } t_img_data;