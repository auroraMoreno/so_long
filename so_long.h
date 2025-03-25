/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:26:59 by aumoreno          #+#    #+#             */
/*   Updated: 2025/03/25 22:44:49 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

#define XPM_PATH "xpm/"
#define PLAYER_XPM "shinchan_pegado.xpm"
#define FLOOR_XPM "floor2.xpm"
#define WALL_XPM "wall_bus.xpm"
#define COLLECTABLE_XPM "galletita.xpm"
#define EXIT_XPM "puerta_closed.xpm"
#define ENEMY_XPM "enemy.xpm"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	void	*img_name;
	int		width;
	int		height;
	char	*path;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
	int		x_pos;
	int		y_pos;
}	t_img;

typedef struct s_map
{
	int		x;
	int		y;
	char	value;
}	t_map;

typedef struct t_item_counter
{
	int	n_player;
	int	n_exits;
	int	n_floor;
}	t_item_counter;

typedef struct s_game_data
{
	t_item_counter	counter;
	void			*mlx;
	void			*mlx_win;
	t_img			player;
	t_img			collectable;
	t_img			floor;
	t_img			wall;
	t_img			enemy;
	t_img			exit;
	int				map_heigth;
	int				map_width;
	int				num_collect;
	int				steps_counter;
	t_map			**map;
}	t_game;

/*INITIALISATION*/
t_game	*ft_init_game(char *file);
char	**ft_map_copy(t_map **map, int map_width, int map_height);
void	ft_init_map(t_game *game, char *file);
void	ft_init_images(t_game *game);

/*MAP UTILS*/
void	ft_fill_x_row(t_game *game, char *str_joined);
void	ft_get_height(char *joined_str, t_game *game);
void	ft_get_width(char *joined_str, t_game *game);
void	ft_innit_x_row(t_game *game);
void	ft_render_map(t_game *game);

/*MAP CHECKS */
void	ft_map_is_valid(t_game *game, char *joined_str);
void	ft_valid_route(t_game *game);
void	ft_validate_flood_fill(t_game *game, char **map_copy);
void	ft_find_player_and_fill(char **map_copy, t_game *game);
void	ft_flood_fill(char **map_copy, int x, int y, t_game *game);
int		ft_is_ber(char *str);

/*CHARACTER MOVEMENTS*/
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int		ft_validate_move(t_game *game, int x, int y);
void	ft_change_value(t_game *game, int old_x, int old_y);
void	ft_skip_exit(t_game *game, int x, int y);

/*ERRORS AND FREEING MEM*/
void	ft_free_game(t_game *game, char *msg);
void	ft_print_error(char *error);
void	ft_end_game(t_game *game);
void	ft_free_joined_line(char *joined_str, t_game *game, char *msg);
void	free_map_copy(char **map_copy, int i);

/*KEY HANDLING*/
int		ft_on_keypress(int keycode, t_game *data);
int		ft_handle_key(int keycode, t_game *game);
int		ft_close_window(t_game *data);