/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:04:37 by aumoreno          #+#    #+#             */
/*   Updated: 2024/08/07 14:22:21 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**ACORDARSE DE PONER EL WALL DE VUELTA EN EL MAKEFILE!!!!!!!!!! */

void ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	//void *img;
	t_data img;

	mlx = mlx_init(); // a connection to the correct graphical system
	img.img = mlx_new_image(mlx,1920,1080); // init an image 
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hi hiii"); //this creates the window
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_len, &img.endian);
	ft_mlx_pixel_put(&img, 5, 5,0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx); //initiates thw window rendering 
	return (0);
}