/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:04:37 by aumoreno          #+#    #+#             */
/*   Updated: 2024/08/06 13:38:52 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 
int main(void)
{
	void *mlx_ptr;
 
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_new_window(mlx_ptr, 1920, 1000, "hi :)");
    mlx_loop(mlx_ptr);
	return (0);
}