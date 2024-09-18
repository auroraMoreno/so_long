/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:26:59 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/18 10:30:52 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
// # include <fcntl.h>


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

typedef struct  s_map
{
    int x;
    int y;
    
}t_map;

typedef struct s_game_data
{
    void *mlx;
    void *mlx_win; 
    t_img floor; // si hace falta, coger la estructura de mlx_int de t_img
    t_img wall; 
    // poner aqui el mapa 
    t_map map; 
    int   map_heigth;
    int   map_width;
    
}t_game;



int ft_handle_key(int keycode, t_game *data);
int ft_close_window(t_game *data);
t_game *ft_init_mlx(char *file);
void *ft_init_images(t_game *game);
void ft_init_map(t_game *game, char *file);
void ft_render_map(t_game *game);
int ft_join_map_line(char *line, char **joined_str);
void ft_process_map_line(char *joined_str, t_game *game);
void ft_get_height(char *joined_str, t_game *game);
void ft_get_width(char  *joined_str, t_game *game);
int ft_map_is_valid(t_game *game, char *joined_str);
void ft_render_map(t_game *game);
int ft_issurrounded(t_game *game, int i);

/*ERRORS AND FREEING MEM*/
void ft_free_game(t_game *game, char *error);
void ft_print_error(char *error);


// typedef struct s_img_data {
//     void *img_ptr;
//     char *addr;
//     int bit_per_pixel;
//     int line_len;
//     int endian;
//     //img_data data;
// } t_img_data;