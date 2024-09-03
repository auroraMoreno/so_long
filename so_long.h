/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:26:59 by aumoreno          #+#    #+#             */
/*   Updated: 2024/09/02 12:23:23 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_mlx_data
{
    void *mlx;
    void *mlx_win; 
}t_mlx_data;

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
    t_mlx_data mlx;
    t_img floor;
    t_img wall; 
    
}t_game;


int ft_handle_key(int keycode, t_mlx_data *data);
int ft_close_window(t_mlx_data *data);



// typedef struct s_img_data {
//     void *img_ptr;
//     char *addr;
//     int bit_per_pixel;
//     int line_len;
//     int endian;
//     //img_data data;
// } t_img_data;