/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:26:59 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/05 10:13:23 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
// # include <fcntl.h>

#define XPM_PATH "xpm/"
#define GHOST_XPM "shinchan_pegado.xpm"
#define FLOOR_XPM "floor2.xpm"
#define WALL_XPM "wall_bus.xpm"
#define COLLECTABLE_XPM "galletita.xpm"
#define EXIT_XPM "puerta_closed.xpm"
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
    int num_collect; // numero de collectables
    int steps_counter;  
    t_map **map;
}t_game;



int ft_on_keypress(int keycode, t_game *data);
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

/*CHARACTER MOVEMENTS*/
void ft_move_up(t_game *game);
void ft_move_down(t_game *game);
void ft_move_left(t_game *game);
void ft_move_right(t_game *game);
int ft_validate_move(t_game *game, int x, int y);
void ft_change_value(t_game *game, int old_x, int old_y);


/*ERRORS AND FREEING MEM*/
void ft_free_game(t_game *game, char *msg);
void ft_print_error(char *error);
void ft_end_game(t_game *game);

void ft_innit_x_row(t_game *game);
void ft_fill_x_row(t_game *game, char *str_joined);
int ft_handle_key(int keycode, t_game *game);

// typedef struct s_img_data {
//     void *img_ptr;
//     char *addr;
//     int bit_per_pixel;
//     int line_len;
//     int endian;
//     //img_data data;
// } t_img_data;