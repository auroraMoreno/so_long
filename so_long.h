/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:26:59 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/25 00:33:54 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
// # include <fcntl.h>

#define XPM_PATH "xpm/"
#define GHOST_XPM "ghost.xpm"
#define FLOOR_XPM "floor.xpm"
#define WALL_XPM "building.xpm"
#define COLLECTABLE_XPM "collectable.xpm"
#define EXIT_XPM "exit.xpm"
#define ENEMY_XPM "enemy.xpm"


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
    int x_pos; //aqui puedo guardar las coordenads de los coll y eso 
    int y_pos;
} t_img;

typedef struct  s_map
{
    int x;
    int y;
    char value;
    
}t_map;

typedef struct s_game_data
{
    void *mlx;
    void *mlx_win; 
    t_img ghost;
    t_img collectable;
    t_img floor;
    t_img wall; 
    t_img enemy;
    t_img exit;
    // poner aqui el mapa
    int   map_heigth;
    int   map_width;
    //int **map;
    int num_collect;  
    t_map **map;
}t_game;



int ft_handle_key(int keycode, t_game *data);
int ft_close_window(t_game *data);
t_game *ft_init_game(char *file);
void ft_init_images(t_game *game);
void ft_init_map(t_game *game, char *file);
void ft_render_map(t_game *game);
// static int ft_join_map_line(char *line, char **joined_str);
// static void ft_process_map_line(char *joined_str, t_game *game);
void ft_get_height(char *joined_str, t_game *game);
void ft_get_width(char  *joined_str, t_game *game);
int ft_map_is_valid(t_game *game, char *joined_str);
void ft_render_map(t_game *game);
// static int ft_issurrounded(t_game *game, int i);

/*ERRORS AND FREEING MEM*/
void ft_free_game(t_game *game, char *error);
void ft_print_error(char *error);
void ft_innit_x_row(t_game *game);

// typedef struct s_img_data {
//     void *img_ptr;
//     char *addr;
//     int bit_per_pixel;
//     int line_len;
//     int endian;
//     //img_data data;
// } t_img_data;