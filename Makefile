# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 22:23:56 by aumoreno          #+#    #+#              #
#    Updated: 2025/03/26 13:34:37 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 14:22:37 by rbourgea          #+#    #+#              #
#    Updated: 2021/08/31 14:25:47 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
MFLAGS	=	-L./mlx -lmlx -lXext -lX11
IFLAGS	=	-I. -I./libft -I./mlx
LFLAGS	=	-L./libft -lft


MLX_DIR	=	./mlx
MLX		=	libmlx.a

SRC		=	main.c valid_path_check.c checks.c init_game.c init_map.c map_utils.c free_utils.c free_game.c movements_utils.c movements.c gnl/get_next_line_utils.c gnl/get_next_line.c


OBJ		=	$(SRC:%.c=%.o)

%.o: %.c
			$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
			
$(NAME):	$(OBJ)
			$(MAKE) -C ./$(MLX_DIR)
			cp ./$(MLX_DIR)/$(MLX) .
			$(MAKE) -C libft
			$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) $(LFLAGS) $(MFLAGS) -o $@


all:		$(NAME)

clean:
			$(MAKE) -C libft clean
			rm -rf $(OBJ)

fclean:		clean
			$(MAKE) -C libft fclean
			$(MAKE) -C ./$(MLX_DIR) clean
			rm -rf $(MLX)
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re