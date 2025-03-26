/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:23:18 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/26 11:05:19 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*add method: free images*/

void ft_destroy_images(t_game *game)
{
    if(game->floor.img_ptr)
        mlx_destroy_image(game->mlx, game->floor.img_ptr); 
    if(game->player.img_ptr)
        mlx_destroy_image(game->mlx, game->player.img_ptr);
    if(game->wall.img_ptr)
        mlx_destroy_image(game->mlx, game->wall.img_ptr);
    if(game->collectable.img_ptr)
        mlx_destroy_image(game->mlx, game->collectable.img_ptr);
    if(game->exit.img_ptr)
        mlx_destroy_image(game->mlx, game->exit.img_ptr);
}

void ft_free_game(t_game *game, int n, char *msg)
{
    int i;
    if(game)
    {
        if(game->map_heigth && game->map)
        {
            i = 0; 
            while(i < game->map_heigth)
            {
                free(game->map[i]);
                i++;
            }
            free(game->map);
        }
        ft_destroy_images(game);
        if(game->mlx_win && game->mlx)
            mlx_destroy_window(game->mlx, game->mlx_win);
        if(game->mlx)
        {
            mlx_destroy_display(game->mlx);
            free(game->mlx);
        }
        free(game);
    }
    if(n == 1)
        ft_end_game();
    else if(n == 0)
        ft_print_error(msg);
}

void ft_end_game()
{
    ft_putendl_fd("CONGRATULATIONS! YOU WON!",1);
    exit(EXIT_SUCCESS);
}

void	ft_free_joined_line(char *joined_str, t_game *game, char *msg)
{
    if(joined_str)
	    free(joined_str);
    if(game)
	    free(game);
	ft_print_error(msg);
}

char	**free_map_copy(char **map_copy, int i)
{
	while (--i >= 0)
		free(map_copy[i]);
	free(map_copy);
    map_copy = NULL;
    return (map_copy);
}

void	ft_print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}
