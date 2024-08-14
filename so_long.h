/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:05:39 by aumoreno          #+#    #+#             */
/*   Updated: 2024/08/14 19:13:59 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"


typedef struct mlx_data
{
    void *mlx;
    void *mlx_win; 
}mlx_data;


typedef struct s_data {
    void *img_ptr;
    char *addr;
    int bit_per_pixel;
    int line_len;
    int endian;
} t_data;


typedef struct img_data {
    void *img_name;
    int   width;
    int    height;
    char   *path;
    
} img_data;