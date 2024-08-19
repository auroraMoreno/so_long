/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:04:37 by aumoreno          #+#    #+#             */
/*   Updated: 2024/08/19 12:20:58 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**ACORDARSE DE PONER EL WALL DE VUELTA EN EL MAKEFILE!!!!!!!!!! */

// function to push pixel to an image 
// replaces the mlx_pixel_put as this one is slower
// this is bc it pushes px instantly into the window 
// without waiting for the frame being enitrely rendered 
// this is why we buffer our px to the img and then push it to the window 
void ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_close_window(mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int main(void)
{

	t_data img; // guarda el puntero y la dir memoria de la img
	img_data img_data; // guarda info de la img como height, path, width
	
	t_data character_img; // usar una lista para todas las t_data y demás? 
	img_data character_data; 
	
	mlx_data mlx_data; // el putero mlx + la window

	img_data.path = "textures/test.xpm";
	character_data.path = "characters/fantasmita.xpm"
	
	//character dimensions: 
	character_data.height = 30;
	character_data.width  = 30;

	mlx_data.mlx = mlx_init(); // a connection to the correct graphical system
	
	img.img_ptr = mlx_xpm_file_to_image(mlx_data.mlx, img_data.path, &img_data.width, &img_data.height);
	character_img.img_ptr = mlx_xpm_file_to_image(mlx_data.mlx, charater_data.path, &character_data.width, &character_data.heigth);

	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, 780, 480, "hi hiii"); //this creates the window

	// images addresses
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bit_per_pixel, &img.line_len, &img.endian);
	character_data.addr = mlx_get_data_addr(character_img.img_ptr, &character_img.bit_per_pixel, &character_img.line_len, &character_img.endian);

	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, img.img_ptr, 0, 0);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, character_img.img_ptr, 10, 10);

	
	mlx_hook(mlx_data.mlx_win,17,1L<<17,&ft_close_window,&mlx_data);

	mlx_loop(mlx_data.mlx); //initiates the window rendering 
	
	return (0);
}